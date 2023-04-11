/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_export_mult.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:58:35 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:52:57 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_export_m_aux(char **array, int *i, t_env *env)
{
	if (((ft_wordcount_space(array[(*i)]) > 1) && \
		(ft_strchr(array[(*i)], '=') == NULL)) || ((array[(*i)][0] > 47) && \
		(array[(*i)][0] < 58)))
	{
		env->exit_stts = 1;
		write(STDERR_FILENO, "minishell: export: `", 20);
		write(STDERR_FILENO, array[(*i)], ft_strlen(array[(*i)]));
		write(STDERR_FILENO, "': not a valid identifier\n", 26);
		(*i)++;
		return ;
	}
	else if (ft_check_first_variable(array[(*i)]) == 1)
	{
		env->exit_stts = 1;
		write(STDERR_FILENO, "minishell: export: `", 20);
		write(STDERR_FILENO, array[(*i)], ft_strlen(array[(*i)]));
		write(STDERR_FILENO, "': not a valid identifier\n", 26);
		(*i)++;
		return ;
	}
	(*i)++;
}

int	ft_export_mult(t_env *env, char **array)
{
	int	i;

	i = ft_array_len(array);
	env->exit_stts = 0;
	if (i == 1)
		ft_sort_and_print_strings(env->env);
	else
	{
		i = 1;
		if (ft_strlen(array[i]) > 1 && array[i][0] == '-')
		{
			env->exit_stts = 1;
			write(STDERR_FILENO, "minishell: export: Options are not ", 35);
			write(STDERR_FILENO, "available in this version of export\n", 36);
		}
		else
		{
			while (array[i] != NULL)
				ft_export_m_aux(array, &i, &(*env));
		}
	}
	if (array != NULL)
		ft_free_split(array);
	return (3);
}
