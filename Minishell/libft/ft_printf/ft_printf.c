/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:45:22 by corellan          #+#    #+#             */
/*   Updated: 2022/12/16 11:01:49 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pf_a4(int *i, int *count, char c)
{
	if (c == '%')
	{
		ft_putchar_fd(c, 1);
		(*count) -= 1;
		(*i) += 2;
	}
	else if (c == '\0')
	{
		(*count) -= 1;
		(*i) += 1;
	}
	else
	{
		(*count) -= 2;
		(*i) += 2;
	}
}

static void	ft_pf_a3(int *i, int *count, char *str)
{
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		(*count) += (ft_strlen(str) - 2);
		(*i) += 2;
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		(*count) += 4;
		(*i) += 2;
	}
}

static void	ft_pf_a2(int *i, int *count, char c, unsigned long num)
{
	char	*s;

	s = NULL;
	if (c == 'x')
		s = ft_print_hex((unsigned int)num);
	else if (c == 'X')
		s = ft_print_hex_u((unsigned int)num);
	else if (c == 'p')
		s = ft_print_address(num);
	else
		s = ft_uitoa((unsigned int)num);
	(*count) += (ft_strlen(s) - 2);
	ft_putstr_fd(s, 1);
	free(s);
	(*i) += 2;
}

static void	ft_pf_a1(int *i, int *c, char d, int num)
{
	char	*s;

	s = NULL;
	if (d == 'd' || d == 'i')
	{
		s = ft_itoa(num);
		(*c) += (ft_strlen(s) - 2);
		ft_putstr_fd(s, 1);
		free(s);
	}
	if (d == 'c')
	{
		ft_putchar_fd(num, 1);
		(*c) -= 1;
	}
	(*i) += 2;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_data	d;

	d.c = 0;
	d.i = 0;
	va_start(args, s);
	while (s[d.i] != '\0')
	{
		if ((s[d.i] == '%') && (s[d.i + 1] == 'd' || s[d.i + 1] == 'i' || \
			s[d.i + 1] == 'c'))
			ft_pf_a1(&d.i, &d.c, s[d.i + 1], va_arg(args, int));
		else if ((s[d.i] == '%') && (s[d.i + 1] == 'x' || s[d.i + 1] == 'X' || \
				s[d.i + 1] == 'p' || s[d.i + 1] == 'u'))
			ft_pf_a2(&d.i, &d.c, s[d.i + 1], va_arg(args, unsigned long));
		else if ((s[d.i] == '%') && (s[d.i + 1] == 's'))
			ft_pf_a3(&d.i, &d.c, va_arg(args, char *));
		else if ((s[d.i] == '%'))
			ft_pf_a4(&d.i, &d.c, s[d.i + 1]);
		else
			ft_writer(&d.i, s[d.i]);
	}
	va_end(args);
	return (d.i + d.c);
}
