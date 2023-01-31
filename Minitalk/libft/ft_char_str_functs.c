/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_str_functs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:27:57 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/11/11 15:43:21 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd_count(char c, int fd)
{
	int	counter;

	counter = 0;
	write (fd, &c, 1);
	counter++;
	return (counter);
}

int	ft_putstr_fd_count(char *s, int fd)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	if (s == NULL)
		return (ft_putstr_fd_count("(null)", fd));
	while (s[i])
	{
		counter += ft_putchar_fd_count(s[i], fd);
		i++;
	}
	return (counter);
}
