/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:47:42 by corellan          #+#    #+#             */
/*   Updated: 2022/11/21 11:49:10 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen(unsigned int n)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (i);
	while ((n / 10) > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char			*digit;
	int				l;
	unsigned int	num;

	l = ft_intlen(n);
	num = 0;
	digit = (char *)malloc(sizeof(char) * (l + 1));
	if (digit == NULL)
		return (NULL);
	digit[l] = '\0';
	while (l > 0)
	{
		num = n % 10;
		n /= 10;
		digit[l - 1] = num + '0';
		l--;
	}
	return (digit);
}
