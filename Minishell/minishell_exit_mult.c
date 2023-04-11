/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exit_mult.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:09:42 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:52:06 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_sucess_return_exit_m(char **ar, int *ret, t_env *env)
{
	if (ft_strncmp(ar[1], "-9223372036854775808", 21) == 0)
	{
		(*ret) = 0;
		ft_free_split(ar);
		return (1);
	}
	(*ret) = (unsigned char)ft_atoll(ar[1]);
	env->exit_stts = (*ret);
	ft_free_split(ar);
	return (1);
}

static int	ft_print_error_e_m1(char **array, int error, t_env *env)
{
	if (error == 1)
	{
		write(2, "minishell: exit: ", 17);
		write(2, array[1], ft_strlen(array[1]));
		write(2, ": numeric argument required\n", 28);
		env->exit_stts = 255;
		ft_free_split(array);
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

static int	ft_exit_args_m_aux(char **array, int *ret, t_env *env)
{
	int	i;

	i = ft_array_len(array);
	if (i > 2)
	{
		if (ft_am_i_a_number(array[1]) == 1 || \
			ft_am_i_valid_number(array[1]) == 1)
			return (ft_print_error_e_m1(array, 1, &(*env)));
		else
			return (ft_print_error_e_m1(array, 2, &(*env)));
	}
	else
	{
		if (ft_am_i_a_number(array[1]) == 1 || \
			ft_am_i_valid_number(array[1]) == 1)
			return (ft_print_error_e_m1(array, 1, &(*env)));
		else
			return (ft_sucess_return_exit_m(array, &(*ret), &(*env)));
	}
	return (0);
}

int	ft_exit_check_m1(char **array, int *ret, t_env *env)
{
	int	i;

	i = ft_array_len(array);
	if (i == 1)
	{
		ft_free_split(array);
		env->exit_stts = 0;
		return (0);
	}
	else if (i > 1)
		return (ft_exit_args_m_aux(array, &(*ret), &(*env)));
	return (3);
}
