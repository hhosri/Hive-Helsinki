/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:55:13 by corellan          #+#    #+#             */
/*   Updated: 2023/04/08 10:54:13 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_pipe(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '|')
		i++;
	return (i);
}

int	ft_strlen_in(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '<')
		i++;
	return (i);
}

int	ft_strlen_out(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '>')
		i++;
	return (i);
}
