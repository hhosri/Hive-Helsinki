/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:25:13 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/30 16:16:41 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/libft.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BRED "\e[1;31m"
# define BGRN "\033[1;32;4m"
# define WHTBCK "\e[47m"
# define RESET "\e[0m"
# define BLK "\e[0;30m"

typedef struct s_data
{
	int		filled_bin;
	char	bin[8];
}	t_data;

t_data	g_data;

#endif