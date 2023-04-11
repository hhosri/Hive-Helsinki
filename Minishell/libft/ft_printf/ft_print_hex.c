/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:44:43 by corellan          #+#    #+#             */
/*   Updated: 2022/11/21 12:01:39 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_hex_len(unsigned int number)
{
	size_t			i;
	unsigned int	n;

	i = 1;
	n = number;
	while ((n / 16) > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_print_hex(unsigned int number)
{
	unsigned int	n;
	int				len;
	char			*s;

	len = ft_hex_len(number);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	n = number;
	while (len > 0)
	{
		len--;
		if ((n % 16) > 9)
			s[len] = ((n % 16) + 87);
		else
			s[len] = ((n % 16) + 48);
		n /= 16;
	}
	return (s);
}
