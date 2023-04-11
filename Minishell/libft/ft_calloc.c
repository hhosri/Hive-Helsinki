/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:40:46 by corellan          #+#    #+#             */
/*   Updated: 2022/11/22 17:28:22 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*s;

	if ((nitems > 0) && (size > 0))
		if ((((nitems * size) % size) != 0) || \
			(((nitems * size) % nitems) != 0))
			return (NULL);
	s = (void *)malloc(size * nitems);
	if (s == 0)
		return ((void *)0);
	ft_bzero(s, (nitems * size));
	return (s);
}
