/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:53:01 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/10/28 15:21:51 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		n = -n;
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_negatives_handler(int n, char *str)
{
	str[0] = '-';
	if (n == -2147483648)
	{
		str[1] = '2';
		n = -147483648;
	}
	n = -n;
	return (n);
}

char	*ft_itoa(int n)
{	
	int		len;
	char	*str;

	len = ft_num_len(n);
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		n = ft_negatives_handler(n, str);
	while (n)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
