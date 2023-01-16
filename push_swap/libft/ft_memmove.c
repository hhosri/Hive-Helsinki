/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:00:16 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/10/31 13:59:19 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstp;
	char	*srcp;

	dstp = (char *)dst;
	srcp = (char *)src;
	if (dst == src)
		return (dst);
	if (srcp > dstp)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			dstp[len - 1] = srcp[len - 1];
			len--;
		}
	}
	return (dst);
}
