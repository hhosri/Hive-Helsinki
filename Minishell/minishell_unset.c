/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_unset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:42:40 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:58:44 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_copy_back_after_unset(t_env *env, char **array, int i)
{
	ft_free_split(env->env);
	env->env = (char **)malloc(sizeof(char *) * (i + 1));
	if (env->env == NULL)
		return ;
	env->env[i] = NULL;
	i = 0;
	while (array[i] != NULL)
	{
		env->env[i] = ft_strdup(array[i]);
		i++;
	}
	ft_free_split(array);
}

void	ft_remove_variables(t_env *env, char *variable)
{
	char	**array;
	int		i;
	int		j;
	int		k;

	i = ft_array_len(env->env);
	j = 0;
	if (ft_find_word_array(env->env, variable) == i)
		return ;
	k = ft_find_word_array(env->env, variable);
	array = (char **)malloc(sizeof(char *) * (i));
	if (array == NULL)
		return ;
	array[i - 1] = NULL;
	i = 0;
	while (env->env[j] != NULL)
	{
		array[i] = ft_strdup(env->env[j]);
		j++;
		i++;
		if (j == k)
			j++;
	}
	ft_copy_back_after_unset(&(*env), array, i);
}

static int	ft_check_unset_variable(char *variable)
{
	int		i;

	i = 0;
	if (ft_strlen(variable) == 0)
		return (1);
	while ((variable[i] > 47 && variable[i] < 58) || \
		(variable[i] > 64 && variable[i] < 91) || \
		(variable[i] > 96 && variable[i] < 123) || (variable[i] == 95))
		i++;
	if (i < (int)ft_strlen(variable))
		return (1);
	return (0);
}

static void	ft_unset_aux(char **array, int *i, t_env *env)
{
	if ((ft_wordcount_space(array[(*i)]) > 1) || ((array[(*i)][0] > 47) && \
		(array[(*i)][0] < 58)))
	{
		env->exit_stts = 1;
		write(STDERR_FILENO, "minishell: unset: `", 19);
		write(STDERR_FILENO, array[(*i)], ft_strlen(array[(*i)]));
		write(STDERR_FILENO, "': not a valid identifier\n", 26);
		(*i)++;
		return ;
	}
	else if (ft_check_unset_variable(array[(*i)]) == 1)
	{
		env->exit_stts = 1;
		write(STDERR_FILENO, "minishell: unset: `", 19);
		write(STDERR_FILENO, array[(*i)], ft_strlen(array[(*i)]));
		write(STDERR_FILENO, "': not a valid identifier\n", 26);
		(*i)++;
		return ;
	}
	ft_remove_variables(&(*env), array[(*i)]);
	(*i)++;
}

int	ft_unset(t_env *env, char **array)
{
	int	i;

	env->exit_stts = 0;
	i = ft_array_len(array);
	if (i == 1)
	{
		ft_free_split(array);
		return (3);
	}
	i = 1;
	if (ft_strlen(array[i]) > 1 && array[i][0] == '-')
	{
		env->exit_stts = 1;
		write(STDERR_FILENO, "minishell: unset: Options are not ", 34);
		write(STDERR_FILENO, "available in this version of unset\n", 35);
	}
	else
	{
		while (array[i] != NULL)
			ft_unset_aux(array, &i, &(*env));
	}
	if (array != NULL)
		ft_free_split(array);
	return (3);
}
