/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:08:28 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/20 10:47:48 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_right_collect(t_objects *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->player_x * 60, data->player->player_y * 60);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->x_target * 60, data->player->y_target * 60);
	data->player->player_x = data->player->player_x + 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->character_img,
		data->player->player_x * 60, data->player->player_y * 60);
}

static void	move_left_collect(t_objects *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->player_x * 60, data->player->player_y * 60);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->x_target * 60, data->player->y_target * 60);
	data->player->player_x = data->player->player_x - 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->character_img,
		data->player->player_x * 60, data->player->player_y * 60);
}

static void	move_up_collect(t_objects *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->player_x * 60, data->player->player_y * 60);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->x_target * 60, data->player->y_target * 60);
	data->player->player_y = data->player->player_y + 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->character_img,
		data->player->player_x * 60, data->player->player_y * 60);
}

static void	move_down_collect(t_objects *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->player_x * 60, data->player->player_y * 60);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->space_img,
		data->player->x_target * 60, data->player->y_target * 60);
	data->player->player_y = data->player->player_y - 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->character_img,
		data->player->player_x * 60, data->player->player_y * 60);
}

void	do_move_collect(int keycode, t_objects *data)
{
	if (keycode == 126)
		move_down_collect(data);
	else if (keycode == 125)
		move_up_collect(data);
	else if (keycode == 123)
		move_left_collect(data);
	else if (keycode == 124)
		move_right_collect(data);
}
