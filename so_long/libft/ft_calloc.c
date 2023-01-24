/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:02:52 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/10/31 15:43:12 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	all_size;

	all_size = count * size;
	ptr = (void *)malloc(sizeof(*ptr) * all_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, all_size);
	return (ptr);
}
