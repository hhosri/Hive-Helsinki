/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:25:07 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/30 15:49:51 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_power(int n, int pow)
{
	int	result;

	result = 1;
	if (pow == 0)
		return (1);
	else
	{
		while (pow > 0)
		{
			result = result * n;
			pow--;
		}
		return (result);
	}
}

static void	parse_sig(int n)
{
	int		i;
	int		dec;

	dec = 0;
	i = 7;
	if (g_data.filled_bin <= 7)
	{
		if (n == 30)
			g_data.bin[g_data.filled_bin] = '0';
		else if (n == 31)
			g_data.bin[g_data.filled_bin] = '1';
		g_data.filled_bin++;
	}
	if (g_data.filled_bin == 8)
	{
		while (i >= 0)
		{
			dec += ft_power(2, (7 - i)) * (g_data.bin[i] - '0');
			i--;
		}
		ft_printf(RESET);
		ft_printf("%c", (char)dec);
		g_data.filled_bin = 0;
	}
}

int	main(int argc, char **argv)
{
	argv = NULL;
	if (argc != 1)
	{
		ft_printf(RED);
		ft_printf("Server doesn't take any arguments!\n");
	}
	else
	{
		ft_printf(BGRN);
		ft_printf("| Server is ON |\n");
		ft_printf(GREEN);
		ft_printf("Your Server's PID is: ");
		ft_printf(WHTBCK);
		ft_printf(BRED);
		ft_printf("%d\n", getpid());
		ft_printf(BLK);
		ft_printf("Server is Listening...\n");
		while (1)
		{
			signal(SIGUSR1, parse_sig);
			signal(SIGUSR2, parse_sig);
			pause();
		}
	}
	return (0);
}
