/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:12:32 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/23 11:11:24 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	handle_x_y(int keycode, t_objects *data)
{
	if (keycode == 123 || keycode == 124)
	{
		if (keycode == 123)
			data->player->x_target = data->player->player_x - 1;
		else if (keycode == 124)
			data->player->x_target = data->player->player_x + 1;
		data->player->y_target = data->player->player_y;
	}
	if (keycode == 126 || keycode == 125)
	{
		if (keycode == 126)
			data->player->y_target = data->player->player_y - 1;
		else if (keycode == 125)
			data->player->y_target = data->player->player_y + 1;
		data->player->x_target = data->player->player_x;
	}
}

static char	what_target(t_objects *data)
{
	if (data->map->map[data->player->y_target][data->player->x_target] == '1')
		return ('1');
	return (data->map->map[data->player->y_target][data->player->x_target]);
}

static void	player_wins(int keycode, t_objects *data)
{
	do_move_collect(keycode, data);
	data->player->win = 1;
	winning_splash(data);
	ft_printf(GREEN);
	ft_printf("******************************\n");
	ft_printf("CONGRATULATIONS!\n");
	ft_printf("YOU MANAGED TO EXIT WITH %d STEPS!\n", data->player->moves + 1);
	ft_printf("******************************\n");
	ft_printf(WHITE);
}

static int	check_target(int keycode, t_objects *data)
{
	if (keycode == 53)
		handle_exit(data);
	if (data->player->win == 0)
	{
		handle_x_y(keycode, data);
		if (what_target(data) == '0')
			do_move(keycode, data);
		else if (what_target(data) == 'C' || what_target(data) == 'P')
		{
			if (what_target(data) == 'C')
				data->map->collectible -= 1;
			do_move_collect(keycode, data);
			data->map->map[data->player->y_target]
			[data->player->x_target] = '0';
		}
		else if (what_target(data) == 'E' && data->map->collectible != 0)
			player_almost_wins(data);
		else if (what_target(data) == 'E' && data->map->collectible == 0)
			player_wins(keycode, data);
		if (what_target(data) == '0' || what_target(data) == 'C'
			|| (what_target(data) == 'E' && data->map->collectible == 0))
			moves_counter(data);
	}
	return (1);
}

void	start_game(t_objects *data)
{
	mlx_key_hook(data->mlx_win, check_target, data);
	mlx_hook(data->mlx_win, 17, 0L, close_window, data);
}
