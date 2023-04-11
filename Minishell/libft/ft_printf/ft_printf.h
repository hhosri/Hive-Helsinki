/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:46:08 by corellan          #+#    #+#             */
/*   Updated: 2023/01/04 12:20:31 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

typedef struct s_data
{
	int	c;
	int	i;

}t_data;

int		ft_printf(const char *s, ...);
char	*ft_print_hex(unsigned int number);
char	*ft_print_hex_u(unsigned int number);
char	*ft_print_address(unsigned long number);
char	*ft_uitoa(unsigned int n);
void	ft_writer(int *i, char c);

#endif
