/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:09:42 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:52:36 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_sucess_return_exit(char **ar, char *str, int *ret, t_env *env)
{
	write(2, "exit\n", 5);
	if (ft_strncmp(ar[1], "-9223372036854775808", 21) == 0)
	{
		(*ret) = 0;
		ft_free_split(ar);
		free(str);
		ft_free_split(env->env);
		free(env->new_str);
		return (1);
	}
	(*ret) = (unsigned char)ft_atoll(ar[1]);
	ft_free_split(ar);
	ft_free_split(env->env);
	free(str);
	free(env->new_str);
	return (1);
}

static int	ft_print_error_exit(char **array, char *str, int error, t_env *env)
{
	write(2, "exit\n", 5);
	if (error == 1)
	{
		write(2, "minishell: exit: ", 17);
		write(2, array[1], ft_strlen(array[1]));
		write(2, ": numeric argument required\n", 28);
		ft_free_split(array);
		ft_free_split(env->env);
		free(env->new_str);
		free(str);
		return (2);
	}
	if (error == 2)
	{
		write(2, "minishell: exit: ", 17);
		write(2, "too many arguments\n", 19);
		env->exit_stts = 1;
		ft_free_split(array);
		return (3);
	}
	return (0);
}

static int	ft_exit_multiargument(char **array, char *str, int *ret, t_env *env)
{
	int	i;

	i = ft_array_len(array);
	if (i > 2)
	{
		if (ft_am_i_a_number(array[1]) == 1 || \
			ft_am_i_valid_number(array[1]) == 1)
			return (ft_print_error_exit(array, str, 1, &(*env)));
		else
			return (ft_print_error_exit(array, str, 2, &(*env)));
	}
	else
	{
		if (ft_am_i_a_number(array[1]) == 1 || \
			ft_am_i_valid_number(array[1]) == 1)
			return (ft_print_error_exit(array, str, 1, &(*env)));
		else
			return (ft_sucess_return_exit(array, str, &(*ret), &(*env)));
	}
	return (0);
}

int	ft_exit_check(char **array, char *str, int *ret, t_env *env)
{
	int	i;

	i = ft_array_len(array);
	if (i == 1)
	{
		write(2, "exit\n", 5);
		free(str);
		ft_free_split(array);
		ft_free_split(env->env);
		free(env->new_str);
		env->exit_stts = 0;
		return (0);
	}
	else if (i > 1)
		return (ft_exit_multiargument(array, str, &(*ret), &(*env)));
	return (3);
}
