/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:00:43 by corellan          #+#    #+#             */
/*   Updated: 2023/04/06 17:29:43 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_second_arg_echo_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] == 'n')
		i++;
	return (i);
}

static void	ft_echo_aux(char **array, int i)
{
	while ((array[i] != NULL) && \
		(ft_second_arg_echo_check(array[i]) == (int)ft_strlen(array[i])))
		i++;
	while (array[i] != NULL)
	{
		write(1, array[i], ft_strlen(array[i]));
		i++;
		if (array[i] != NULL)
			write(1, " ", 1);
	}
}

int	ft_echo(char **array, t_env *env)
{
	int	i;

	i = 1;
	env->exit_stts = 0;
	if (array[1] == NULL)
	{
		write(1, "\n", 1);
		ft_free_split(array);
		return (3);
	}
	ft_echo_aux(array, i);
	if ((ft_second_arg_echo_check(array[1]) < (int)ft_strlen(array[1])) || \
		(ft_strlen(array[1]) == 0))
		write(1, "\n", 1);
	ft_free_split(array);
	return (3);
}
