/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_int_funct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:00:10 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/11/11 15:43:24 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		ft_putstr_fd_count("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd_count('-', fd);
			n = -n;
			ft_printnbr_fd(n, fd);
		}
		else if (n <= 9 && n >= 0)
		{
			c = n + '0';
			ft_putchar_fd_count(c, fd);
		}
		else
		{
			ft_printnbr_fd(n / 10, fd);
			c = (n % 10) + '0';
			ft_putchar_fd_count(c, fd);
		}
	}
}

static int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_fd_count(int n, int fd)
{
	int	len;

	len = ft_int_len(n);
	ft_printnbr_fd(n, fd);
	return (len);
}
