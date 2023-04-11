/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:16:57 by corellan          #+#    #+#             */
/*   Updated: 2023/03/20 15:16:06 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int n)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (i);
	else if (n == -2147483648LL)
		return (11);
	else
	{
		if (n < 0)
		{
			i = 2;
			n *= -1;
		}
		while ((n / 10) > 0)
		{
			n /= 10;
			i++;
		}
		return (i);
	}
}

static char	*ft_itoa_aux(char *digit, int n, int sign, int l)
{
	int	len;
	int	num;

	len = ft_intlen(n);
	len += sign;
	num = 0;
	while (l > sign)
	{
		num = n % 10;
		n /= 10;
		digit[l - 1] = num + '0';
		l--;
	}
	digit[len] = '\0';
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*digit;
	int		l;

	l = ft_intlen(n);
	digit = (char *)malloc(sizeof(char) * (l + 1));
	if (digit == NULL)
		return (NULL);
	if (n == -2147483648LL)
	{
		ft_strlcpy(digit, "-2147483648", 12);
		return (digit);
	}
	if (n < 0)
	{
		digit[0] = '-';
		n *= -1;
		return (ft_itoa_aux(digit, n, 1, l));
	}
	else
		return (ft_itoa_aux(digit, n, 0, l));
}
