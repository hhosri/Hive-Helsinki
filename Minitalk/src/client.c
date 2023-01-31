/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:25:04 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/30 15:54:44 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	check_input(int argc, char **argv)
{
	if (argc != 3)
	{
		if (argc > 3)
		{
			ft_printf(RED);
			ft_printf("Too many Arguments!\n");
		}
		else
		{
			ft_printf(RED);
			ft_printf("Missing Arguments!\n");
		}
		return (0);
	}
	else if (argv[2][0] == '\0')
	{
		ft_printf(RED);
		ft_printf("Please enter a message argument!\n");
		return (0);
	}
	return (1);
}

static void	conv_bin_send_sig(char *str, pid_t pid)
{
	int	bit;

	while (*str)
	{
		bit = 7;
		while (bit >= 0)
		{
			if (((*str >> bit) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((*str >> bit) & 1) == 1)
				kill(pid, SIGUSR2);
			bit--;
			usleep(300);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (check_input(argc, argv) == 0)
		exit (0);
	else
	{
		pid = ft_atoi(argv[1]);
		conv_bin_send_sig(argv[2], pid);
	}
	return (0);
}
