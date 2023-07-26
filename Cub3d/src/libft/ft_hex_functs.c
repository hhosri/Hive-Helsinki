/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:02:06 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/13 13:04:23 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	ft_printhex(unsigned int n, int fd, char c)
{
	if (n >= 16)
	{
		ft_printhex(n / 16, fd, c);
		ft_printhex(n % 16, fd, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd_count(n + '0', fd);
		else
		{
			if (c == 'x')
				ft_putchar_fd_count(n - 10 + 'a', fd);
			else
				ft_putchar_fd_count(n - 10 + 'a' - 32, fd);
		}
	}
}

int	ft_puthex_fd_count(unsigned int n, int fd, char c)
{
	int	len;

	len = ft_hex_len(n);
	ft_printhex(n, fd, c);
	if (n == 0)
		return (len + 1);
	else
		return (len);
}
