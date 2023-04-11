/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:43:14 by corellan          #+#    #+#             */
/*   Updated: 2022/11/21 13:26:11 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_hex_len(unsigned long number)
{
	size_t			i;
	unsigned long	n;

	i = 1;
	n = number;
	while ((n / 16) > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_print_address(unsigned long number)
{
	unsigned long	n;
	int				len;
	char			*s;

	len = (ft_hex_len(number) + 2);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	n = number;
	while (len > 0)
	{
		len--;
		if ((n % 16) > 9 && len > 1)
			s[len] = ((n % 16) + 87);
		if ((n % 16) <= 9 && len > 1)
			s[len] = ((n % 16) + 48);
		if (len == 1)
			s[len] = 'x';
		if (len == 0)
			s[len] = '0';
		n /= 16;
	}
	return (s);
}
