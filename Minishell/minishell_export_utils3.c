/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_export_utils3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:39:33 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 12:47:48 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_already_exist_plus_ax(t_env *env, char **ar, int i, char *va)
{
	char	**temp;
	char	**temp2;
	char	*bk;

	temp = ft_split(ar[0], '+');
	bk = ft_strdup(env->env[i]);
	temp2 = ft_split(bk, '=');
	if (ft_array_len(temp2) > 1)
		env->env[i] = ft_strjoin_free(env->env[i], ar[1]);
	else if ((ar[1] != NULL) || ((ar[1] == NULL) \
		&& (va[ft_strlen(va) - 1] == '=')))
	{
		free(env->env[i]);
		env->env[i] = ft_strdup(temp[0]);
		env->env[i] = ft_strjoin_free(env->env[i], "=");
		if (ar[1] != NULL)
			env->env[i] = ft_strjoin_free(env->env[i], ar[1]);
	}
	ft_free_split(ar);
	ft_free_split(temp);
	ft_free_split(temp2);
	free(bk);
}

static int	check_already_exist_plus(t_env *env, char *variable)
{
	char	**ar;
	char	**ar2;
	int		i;

	i = 0;
	ar = ft_split(variable, '=');
	ar2 = ft_split(ar[0], '+');
	while (env->env[i] != NULL)
	{
		if ((ft_strncmp(env->env[i], ar2[0], ft_strlen(ar2[0])) == 0) && \
			((env->env[i][ft_strlen(ar2[0])] == '\0') || \
			(env->env[i][ft_strlen(ar2[0])] == '=')))
			break ;
		i++;
	}
	if (env->env[i] == NULL)
	{
		ft_free_split(ar);
		ft_free_split(ar2);
		return (0);
	}
	ft_free_split(ar2);
	check_already_exist_plus_ax(&(*env), ar, i, variable);
	return (1);
}

static int	check_plus_aux(t_env *env, char **arr, int i, char *variable)
{
	i = 0;
	while (env->env[i] != NULL)
	{
		arr[i] = ft_strdup(env->env[i]);
		i++;
	}
	arr[i] = ft_strdup_export(variable);
	ft_add_variables_copy_back(&(*env), arr, i);
	return (1);
}

int	ft_check_plus(t_env *env, char *variable)
{
	int		i;
	char	**arr;

	arr = ft_split(variable, '=');
	if (arr[0][ft_strlen(arr[0]) - 1] != '+')
	{
		ft_free_split(arr);
		return (0);
	}
	ft_free_split(arr);
	if (check_already_exist_plus(&(*env), variable) == 1)
		return (1);
	i = ft_array_len(env->env);
	arr = (char **)malloc(sizeof(char *) * (i + 2));
	if (arr == NULL)
		return (0);
	arr[i + 1] = NULL;
	return (check_plus_aux(&(*env), arr, i, variable));
}
