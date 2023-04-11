/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:54:26 by corellan          #+#    #+#             */
/*   Updated: 2022/11/04 17:20:58 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tempdest;
	unsigned const char	*tempsrc;

	i = 0;
	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned const char *)src;
	if (tempdest == 0 && tempsrc == 0)
		return ((void *)0);
	while (i < n)
	{
		tempdest[i] = tempsrc[i];
		i++;
	}
	return (dest);
}
