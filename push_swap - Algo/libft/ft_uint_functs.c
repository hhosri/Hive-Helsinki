/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:05:43 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/11/11 15:44:06 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printunbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n <= 9 && n >= 0)
	{
		c = n + '0';
		ft_putchar_fd_count(c, fd);
	}
	else
	{
		ft_printunbr_fd(n / 10, fd);
		c = (n % 10) + '0';
		ft_putchar_fd_count(c, fd);
	}
}

static int	ft_uint_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putunbr_fd_count(unsigned int n, int fd)
{
	int	len;

	len = ft_uint_len(n);
	ft_printunbr_fd(n, fd);
	return (len);
}
