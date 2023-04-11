/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:49:09 by corellan          #+#    #+#             */
/*   Updated: 2022/11/06 15:18:44 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnstr_aux(const char *big, const char *little, size_t len, \
size_t i)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (little[i] != '\0' && j < len && big[j] != '\0')
	{
		while (big[j] != little[i] && j < len && big[j] != '\0')
			j++;
		if (big[j] == little[i])
		{
			i++;
			j++;
		}
		if ((big[j] != little[i]) && little[i] != '\0')
		{
			i = 0;
			k++;
			j = k;
		}
	}
	if ((i < ft_strlen(little)) || (j > len))
		return (0);
	else
		return ((char *)big + j - i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	return (ft_strnstr_aux(big, little, len, i));
}
