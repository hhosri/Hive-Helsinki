/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:46:06 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/11/11 15:43:37 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_type(char c, va_list list, int len)
{
	if (c == 'c')
		len += ft_putchar_fd_count(va_arg(list, int), 1);
	if (c == 's')
		len += ft_putstr_fd_count(va_arg(list, char *), 1);
	if (c == 'p')
		len += ft_putptr_fd_count((uintptr_t)va_arg(list, void *), 1);
	if (c == 'i' || c == 'd')
		len += ft_putnbr_fd_count(va_arg(list, int), 1);
	if (c == 'u')
		len += ft_putunbr_fd_count(va_arg(list, unsigned int), 1);
	if (c == 'x' || c == 'X')
		len += ft_puthex_fd_count(va_arg(list, unsigned int), 1, c);
	if (c == '%')
		len += ft_putchar_fd_count('%', 1);
	return (len);
}

static int	ft_char_checker(const char *input, va_list args)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (input[i])
	{
		if (input[i] == '%' && ft_isformat(input[i + 1]))
		{
			len = ft_handle_type(input[i + 1], args, len);
			i++;
		}
		else if (input [i] == '%' && !input[i + 1])
			return (len);
		else if (input[i] == '%' && !ft_isformat(input[i + 1]))
		{
			i++;
			len += ft_putchar_fd_count(input[i], 1);
		}
		else
			len += ft_putchar_fd_count(input[i], 1);
		i++;
	}
	return (len);
}

int	ft_printf(const char *input, ...)
{
	int		len;
	va_list	args;

	va_start(args, input);
	len = ft_char_checker(input, args);
	va_end(args);
	return (len);
}
