/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:46:50 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/20 10:49:46 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_right(t_objects *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->player_x * 60, data->player->player_y * 60);
	data->player->player_x = data->player->player_x + 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->imgs->character_img, data->player->player_x * 60,
		data->player->player_y * 60);
}

static void	move_left(t_objects *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->player_x * 60, data->player->player_y * 60);
	data->player->player_x = data->player->player_x - 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->character_img,
		data->player->player_x * 60, data->player->player_y * 60);
}

static void	move_up(t_objects *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->player_x * 60, data->player->player_y * 60);
	data->player->player_y = data->player->player_y + 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->character_img,
		data->player->player_x * 60, data->player->player_y * 60);
}

static void	move_down(t_objects *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->player_x * 60, data->player->player_y * 60);
	data->player->player_y = data->player->player_y - 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->character_img,
		data->player->player_x * 60, data->player->player_y * 60);
}

void	do_move(int keycode, t_objects *data)
{
	if (keycode == 126)
		move_down(data);
	else if (keycode == 125)
		move_up(data);
	else if (keycode == 123)
		move_left(data);
	else if (keycode == 124)
		move_right(data);
}
