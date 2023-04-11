/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:28:40 by corellan          #+#    #+#             */
/*   Updated: 2023/01/05 10:57:13 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_pos(char const *str, int i, int counter, int neg)
{
	long long	num;
	long long	negative;
	int			number;

	num = 0;
	number = 0;
	negative = (long long)neg;
	while (str[i] <= 57 && str[i] >= 48)
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	num *= negative;
	if ((i - counter) >= 20)
		return (-1);
	else if (num < 0)
		return (-1);
	else
	{
		number = (int)num;
		return (number);
	}
}

static int	ft_atoi_neg(char const *str, int i, int counter, int neg)
{
	long long	num;
	long long	negative;
	int			number;

	num = 0;
	number = 0;
	negative = (long long)neg;
	while (str[i] <= 57 && str[i] >= 48)
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	num *= negative;
	if ((i - counter) >= 20)
		return (0);
	else if (num > 0)
	{
		return (0);
	}
	else
	{
		number = (int)num;
		return (number);
	}
}

int	ft_atoi(char const *str)
{
	int	i;
	int	neg;
	int	counter;

	i = 0;
	neg = 1;
	counter = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	counter = i;
	if (neg == -1)
		return (ft_atoi_neg(str, i, counter, neg));
	else
		return (ft_atoi_pos(str, i, counter, neg));
}
