/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:48:53 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/11/03 13:50:54 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	substring = (char *)malloc(sizeof(*substring) * len + 1);
	if (!substring)
		return (NULL);
	while (s[start] && len > 0 && (start <= ft_strlen(s)))
	{
		substring[i] = s[start];
		start++;
		len--;
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
