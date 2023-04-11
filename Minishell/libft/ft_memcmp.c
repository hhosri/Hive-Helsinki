/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:06:31 by corellan          #+#    #+#             */
/*   Updated: 2023/01/05 10:58:18 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t						i;
	int							s1;
	int							s2;
	unsigned const char			*st1;
	unsigned const char			*st2;

	i = 0;
	st1 = (unsigned const char *)str1;
	st2 = (unsigned const char *)str2;
	while (i < n)
	{
		if (st1[i] != st2[i])
		{
			s1 = st1[i];
			s2 = st2[i];
			return (s1 - s2);
		}
		i++;
	}
	return (0);
}
