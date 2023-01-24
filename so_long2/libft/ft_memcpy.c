/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:44:58 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/10/31 14:06:29 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*dstp;
	const char	*srcp;

	if ((dst == src) || n == 0)
		return (dst);
	dstp = (char *)dst;
	srcp = (const char *)src;
	i = 0;
	while (n > 0)
	{
		dstp[i] = srcp[i];
		i++;
		n--;
	}
	return (dst);
}
