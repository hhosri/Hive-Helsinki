/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:05:10 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/10/31 14:14:21 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (ft_strlen(s));
	while (len + 1 > 0)
	{
		if (s[len] == (char) c)
			return ((char *) s + len);
		else
			len--;
	}
	return (NULL);
}
