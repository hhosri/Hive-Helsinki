/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:41:11 by corellan          #+#    #+#             */
/*   Updated: 2022/11/05 15:46:43 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int		a;
	unsigned int		b;
	unsigned int		i;
	char				*dest;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = 0;
	dest = (char *)malloc(sizeof(char) * ((a + b) + 1));
	if (dest == NULL)
		return (NULL);
	while (i < (a + b))
	{
		if (i < a)
			dest[i] = s1[i];
		else
			dest[i] = s2[i - a];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
