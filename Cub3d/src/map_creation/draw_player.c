/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:20:17 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/26 11:30:05 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map_2d_white[i])
	{
		j = 0;
		while (data->map->map_2d_white[i][j])
		{
			if (data->map->map_2d_white[i][j] == 'N' || \
				data->map->map_2d_white[i][j] == 'W' || \
				data->map->map_2d_white[i][j] == 'E' || \
				data->map->map_2d_white[i][j] == 'S')
			{
				data->player->x_start = j * GRID_SIZE;
				data->player->y_start = i * GRID_SIZE;
				data->player->direction = data->map->map_2d_white[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_brham(t_arrow *b, t_data *data)
{
	b->x = (data->player->pos_x / GRID_SIZE * GRID_SIZE);
	b->y = (data->player->pos_y / GRID_SIZE * GRID_SIZE);
	b->endx = (data->player->pos_x / GRID_SIZE * GRID_SIZE) - \
	(GRID_SIZE / 3) * cos(data->player->pa);
	b->endy = (data->player->pos_y / GRID_SIZE * GRID_SIZE) - \
	(GRID_SIZE / 3) * sin(data->player->pa);
	b->brx = b->x;
	b->bry = b->y;
	b->brdx = abs(b->endx - b->x);
	b->brdy = -abs(b->endy - b->y);
	if (b->brx < b->endx)
		b->stepx = 1;
	else
		b->stepx = -1;
	if (b->bry < b->endy)
		b->stepy = 1;
	else
		b->stepy = -1;
	b->error = b->brdx + b->brdy;
}

void	draw_directional_arrow(int color, t_data *data)
{
	t_arrow	b;

	init_brham(&b, data);
	while (1)
	{
		if (b.brx > 0 && b.brx < WIN_HEIGHT && b.bry > 0 && b.bry < WIN_WIDTH)
			my_mlx_pixel_put(data->image, b.brx, b.bry, color);
		if (b.brx == b.endx && b.bry == b.endy)
			break ;
		b.err2 = 2 * b.error;
		if (b.err2 >= b.brdy)
		{
			if (b.brx == b.endx)
				break ;
			b.error += b.brdy;
			b.brx += b.stepx;
		}
		if (b.err2 <= b.brdx)
		{
			if (b.bry == b.endy)
				break ;
			b.error += b.brdx;
			b.bry += b.stepy;
		}
	}
}

void	set_player_looking_dir(t_data *data)
{
	if (data->player->direction == 'N')
		data->player->pa = PI / 2;
	if (data->player->direction == 'W')
		data->player->pa = 0;
	if (data->player->direction == 'E')
		data->player->pa = PI;
	if (data->player->direction == 'S')
		data->player->pa = 3 * PI / 2;
	data->player->pdx = cos(data->player->pa) * 5;
	data->player->pdy = sin(data->player->pa) * 5;
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;
	int	player_width;

	i = 0;
	player_width = GRID_SIZE / 5;
	if (check_if_player_in_map(data))
		return ;
	while (i < player_width)
	{
		j = 0;
		while (j < player_width)
		{
			my_mlx_pixel_put(data->image, \
			(data->player->pos_x) + j - (player_width / 2), \
			(data->player->pos_y) + i - (player_width / 2), \
			data->player->color);
			j++;
		}
		i++;
	}
	draw_directional_arrow(data->player->color, data);
}
