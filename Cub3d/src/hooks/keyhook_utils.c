/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:36:09 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/26 11:39:03 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	check_w_s_next_move(int key, t_data *data)
{
	float	x;
	float	y;

	if (key == 13)
	{
		x = data->player->pos_x - data->player->pdx;
		y = data->player->pos_y - data->player->pdy;
		if (data->map->map_2d_white[(int)y / GRID_SIZE] \
		[(int)x / GRID_SIZE] == '1')
		{
			data->player->pos_x = data->player->x_start;
			data->player->pos_y = data->player->y_start;
		}
	}
	else if (key == 1)
	{
		x = data->player->pos_x + data->player->pdx;
		y = data->player->pos_y + data->player->pdy;
		if (data->map->map_2d_white[(int)y / GRID_SIZE] \
		[(int)x / GRID_SIZE] == '1')
		{
			data->player->pos_x = data->player->x_start;
			data->player->pos_y = data->player->y_start;
		}
	}
}

void	check_a_d_next_move(int key, t_data *data)
{
	float	x;
	float	y;

	if (key == 2)
	{
		x = data->player->pos_x + (GRID_SIZE / 5) * sin(data->player->pa);
		y = data->player->pos_y - (GRID_SIZE / 5) * cos(data->player->pa);
		if (data->map->map_2d_white[(int)y / GRID_SIZE] \
		[(int)x / GRID_SIZE] == '1')
		{
			data->player->pos_x = data->player->x_start;
			data->player->pos_y = data->player->y_start;
		}
	}
	else if (key == 0)
	{
	x = data->player->pos_x - (GRID_SIZE / 5) * sin(data->player->pa);
	y = data->player->pos_y + (GRID_SIZE / 5) * cos(data->player->pa);
		if (data->map->map_2d_white[(int)y / GRID_SIZE] \
		[(int)x / GRID_SIZE] == '1')
		{
			data->player->pos_x = data->player->x_start;
			data->player->pos_y = data->player->y_start;
		}
	}
}

int	w_s_keyhooks(int key, t_data *data)
{
	if (key == 13)
	{
		data->player->pos_x -= data->player->pdx / 3;
		data->player->pos_y -= data->player->pdy / 3;
		check_w_s_next_move(key, data);
	}
	if (key == 1)
	{
		data->player->pos_x += data->player->pdx / 3;
		data->player->pos_y += data->player->pdy / 3;
		check_w_s_next_move(key, data);
	}
	return (0);
}

int	a_d_keyhooks(int key, t_data *data)
{
	float	x;
	float	y;

	x = 0;
	y = 0;
	if (key == 0)
	{
		data->player->pos_x -= (GRID_SIZE / 7) * sin(data->player->pa);
		data->player->pos_y += (GRID_SIZE / 7) * cos(data->player->pa);
		check_a_d_next_move(key, data);
	}
	if (key == 2)
	{
		data->player->pos_x += (GRID_SIZE / 7) * sin(data->player->pa);
		data->player->pos_y -= (GRID_SIZE / 7) * cos(data->player->pa);
		check_a_d_next_move(key, data);
	}
	return (0);
}

int	turning_keyhooks(int key, t_data *data)
{
	if (key == 123)
	{
		data->player->pa -= 0.1;
		if (data->player->pa < 0)
			data->player->pa += 2 * PI;
		data->player->pdx = cos(data->player->pa) * 5;
		data->player->pdy = sin(data->player->pa) * 5;
	}
	if (key == 124)
	{
		data->player->pa += 0.1;
		if (data->player->pa > 2 * PI)
			data->player->pa -= 2 * PI;
		data->player->pdx = cos(data->player->pa) * 5;
		data->player->pdy = sin(data->player->pa) * 5;
	}
	return (0);
}
