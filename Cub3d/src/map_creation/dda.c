/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:57:38 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/25 11:13:14 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	loop_vert_ray(t_data *data)
{
	while (data->rays->dof < 8 && data->rays->rx >= 0 && data->rays->ry >= 0)
	{
		if (data->rays->ry >= data->map->y_size * GRID_SIZE)
			data->rays->ry = data->map->y_size * GRID_SIZE - 0.00001;
		data->rays->mx = (int) data->rays->rx / GRID_SIZE;
		data->rays->my = (int) data->rays->ry / GRID_SIZE;
		data->rays->mp = data->rays->my * \
		data->map->x_size_max + data->rays->mx;
		if (data->rays->mx >= 0 && data->rays->mp < data->map->map_size && \
		data->map->x_size[data->rays->my] && data->rays->mx < \
		data->map->x_size[data->rays->my] && data->rays->my >= 0 && \
		data->rays->my < data->map->y_size && \
		data->map->map_2d_white[data->rays->my][data->rays->mx] == '1')
			vert_is_it_a_wall(data);
		else
		{
			data->rays->rx += data->rays->xo;
			data->rays->ry += data->rays->yo;
		}
		if (data->rays->rx > WIN_WIDTH || data->rays->ry > WIN_HEIGHT)
			break ;
	}
	check_ray_len_overflow(data);
}

void	draw_vert_ray(t_data *data)
{
	if (data->rays->ra < PI / 2 || data->rays->ra > PI * 3 / 2)
	{
		data->rays->rx = (int)data->player->pos_x - \
		(int)data->player->pos_x % GRID_SIZE - 0.0001;
		data->rays->ry = (data->player->pos_x - data->rays->rx) \
		* data->rays->n_tan + data->player->pos_y;
		data->rays->xo = -GRID_SIZE;
		data->rays->yo = -data->rays->xo * data->rays->n_tan;
	}
	if (data->rays->ra > PI / 2 && data->rays->ra < PI * 3 / 2)
	{
		data->rays->rx = ((int)data->player->pos_x - \
		(int)data->player->pos_x % GRID_SIZE) + GRID_SIZE;
		data->rays->ry = (data->player->pos_x - data->rays->rx) \
		* data->rays->n_tan + data->player->pos_y;
		data->rays->xo = GRID_SIZE;
		data->rays->yo = -data->rays->xo * data->rays->n_tan;
	}
	if (data->rays->ra == 0 || data->rays->ra == PI)
	{
		data->rays->rx = data->player->pos_x;
		data->rays->ry = data->player->pos_y;
		data->rays->dof = 8;
	}
	loop_vert_ray(data);
}

void	loop_hor_ray(t_data *data)
{
	while (data->rays->dof < 8 && data->rays->rx >= 0 && data->rays->ry >= 0)
	{
		if (data->rays->ry >= data->map->y_size * GRID_SIZE)
			data->rays->ry = data->map->y_size * GRID_SIZE - 0.5;
		data->rays->mx = (int) data->rays->rx / GRID_SIZE;
		data->rays->my = (int) data->rays->ry / GRID_SIZE;
		data->rays->mp = data->rays->my * \
		data->map->x_size_max + data->rays->mx;
		if (data->rays->mx >= 0 && data->rays->mp < data->map->map_size && \
		data->map->x_size[data->rays->my] && data->rays->mx < \
		data->map->x_size[data->rays->my] && data->rays->my >= 0 && \
		data->rays->my < data->map->y_size && \
		data->map->map_2d_white[data->rays->my][data->rays->mx] == '1')
			hor_is_it_a_wall(data);
		else
		{
			data->rays->rx += data->rays->xo;
			data->rays->ry += data->rays->yo;
		}
		if (data->rays->rx > WIN_WIDTH || data->rays->ry > WIN_HEIGHT)
			break ;
	}
	check_ray_len_overflow(data);
}

void	draw_hor_ray(t_data *data)
{
	if (data->rays->ra < PI)
	{
		data->rays->ry = ((int)data->player->pos_y - \
		(int)data->player->pos_y % GRID_SIZE) - 0.0001;
		data->rays->rx = (data->player->pos_y - data->rays->ry) \
		* data->rays->a_tan + data->player->pos_x;
		data->rays->yo = -GRID_SIZE;
		data->rays->xo = -data->rays->yo * data->rays->a_tan;
	}
	if (data->rays->ra > PI)
	{
		data->rays->ry = ((int)data->player->pos_y - \
		(int)data->player->pos_y % GRID_SIZE) + GRID_SIZE;
		data->rays->rx = (data->player->pos_y - data->rays->ry) \
		* data->rays->a_tan + data->player->pos_x;
		data->rays->yo = GRID_SIZE;
		data->rays->xo = -data->rays->yo * data->rays-> a_tan;
	}
	if (data->rays->ra == 0 || data->rays->ra == PI)
	{
		data->rays->rx = data->player->pos_x;
		data->rays->ry = data->player->pos_y;
		data->rays->dof = 8;
	}
	loop_hor_ray(data);
}
