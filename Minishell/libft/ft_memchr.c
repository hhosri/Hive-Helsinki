/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:47:53 by corellan          #+#    #+#             */
/*   Updated: 2022/11/01 16:12:02 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char		*s;
	unsigned char		d;
	size_t				i;

	i = 0;
	d = (unsigned char)c;
	s = (unsigned char *)str;
	while (i < n)
	{
		if (*s == d)
			return ((unsigned char *)s);
		s++;
		i++;
	}
	return (NULL);
}
