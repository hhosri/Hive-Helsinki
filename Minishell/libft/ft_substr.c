/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:32:55 by corellan          #+#    #+#             */
/*   Updated: 2022/11/21 11:53:54 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(s);
	if (len <= l)
		dest = (char *)malloc(sizeof(char) * (len + 1));
	else
		dest = (char *)malloc(sizeof(char) * (l + 1));
	if (dest == NULL || s == NULL)
		return (NULL);
	if (start >= l)
	{
		ft_strlcpy(dest, "", len);
		return (dest);
	}
	while (i < len && i < l)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
