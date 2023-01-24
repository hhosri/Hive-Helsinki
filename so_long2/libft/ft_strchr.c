/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:21:38 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/10/26 11:19:54 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;

	len = (ft_strlen(s) + 1);
	while (len > 0)
	{
		if (*s == (char) c)
			return ((char *)s);
		else
		{
			s++;
			len--;
		}
	}
	return (NULL);
}
