/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:28:35 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:58:59 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_am_i_valid_number(char const *str)
{
	int			i;
	long long	num;

	i = 0;
	num = 0;
	if (ft_strncmp(str, "-9223372036854775808", 21) == 0)
		return (0);
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] <= 57 && str[i] >= 48)
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	if (num < 0)
		return (1);
	return (0);
}

int	ft_am_i_a_number(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (1);
	}
	while ((str[i] <= 57 && str[i] >= 48))
		i++;
	if (i < ft_strlen(str))
		return (1);
	return (0);
}

long long	ft_atoll(char const *str)
{
	int			i;
	long long	number;
	long long	neg;

	i = 0;
	neg = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		number *= 10;
		number += (str[i++] - '0');
	}
	if ((number < 0) && (neg == -1))
		return (0);
	if ((number < 0) && (neg == 1))
		return (-1);
	return ((neg * number));
}
