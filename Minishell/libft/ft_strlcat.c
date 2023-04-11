/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 07:43:32 by corellan          #+#    #+#             */
/*   Updated: 2022/11/02 15:48:10 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_size(const char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && i < size)
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	dest;
	size_t	source;
	size_t	i;

	source = ft_strlen(src);
	if (size == 0 && dst == NULL)
		return (0 + source);
	dest = ft_strlen_size(dst, size);
	i = 0;
	if (size == dest)
		return (dest + source);
	else
	{
		while ((dest + i) < (size - 1) && src[i] != '\0')
		{
			dst[dest + i] = src[i];
			i++;
		}
		dst[dest + i] = '\0';
		return (dest + source);
	}
}
