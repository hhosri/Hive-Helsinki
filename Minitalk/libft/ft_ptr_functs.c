/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:15:10 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/11/11 15:43:43 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_len(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

static void	ft_printptr(uintptr_t ptr, int fd)
{
	if (ptr >= 16)
	{
		ft_printptr(ptr / 16, fd);
		ft_printptr(ptr % 16, fd);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd_count(ptr + '0', fd);
		else
			ft_putchar_fd_count(ptr - 10 + 'a', fd);
	}
}

int	ft_putptr_fd_count(uintptr_t ptr, int fd)
{
	int	len;

	len = ft_ptr_len(ptr);
	ft_putstr_fd_count("0x", fd);
	ft_printptr(ptr, fd);
	if (ptr == 0)
		return (len + 3);
	else
		return (len + 2);
}
