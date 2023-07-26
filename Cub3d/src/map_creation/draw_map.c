/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:26:57 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/24 17:37:58 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	its_player(t_data *data, int x, int y)
{
	if (data->map->map_2d_white[x][y] == 'N' \
	|| data->map->map_2d_white[x][y] == 'S' \
	|| data->map->map_2d_white[x][y] == 'E' \
	|| data->map->map_2d_white[x][y] == 'W')
		return (1);
	else
		return (0);
}

void	draw_ver_lines(t_data *data, int grid_x, int grid_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			if (data->map->map_2d_white[grid_x][grid_y] != ' ' \
			&& (i == 0 || i == GRID_SIZE - 1))
				my_mlx_pixel_put(data->image, (grid_y * GRID_SIZE) + j, \
				grid_x * GRID_SIZE, data->player->color);
			else if (data->map->map_2d_white[grid_x][grid_y] == '1' \
			&& (i > 0 && i < GRID_SIZE - 1))
				my_mlx_pixel_put(data->image, (grid_y * GRID_SIZE) + j, \
				grid_x * GRID_SIZE, data->map->wall_color);
			else if ((data->map->map_2d_white[grid_x][grid_y] == '0' && \
			(i > 0 && i < GRID_SIZE - 1)) || its_player(data, grid_x, grid_y))
				my_mlx_pixel_put(data->image, (grid_y * GRID_SIZE) + j, \
				grid_x * GRID_SIZE, data->map->floor_color);
			j++;
		}
		i++;
	}
}

void	draw_hor_lines(t_data *data, int grid_x, int grid_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			if (data->map->map_2d_white[grid_x][grid_y] != ' ' \
			&& (i == 0 || i == GRID_SIZE - 1))
				my_mlx_pixel_put(data->image, grid_y * GRID_SIZE + i, \
				(grid_x * GRID_SIZE) + j, data->player->color);
			else if (data->map->map_2d_white[grid_x][grid_y] == '1' \
			&& i > 0 && i < GRID_SIZE - 1)
				my_mlx_pixel_put(data->image, grid_y * GRID_SIZE + i, \
				(grid_x * GRID_SIZE) + j, data->map->wall_color);
			else if ((data->map->map_2d_white[grid_x][grid_y] == '0' \
			&& i > 0 && i < GRID_SIZE - 1) || its_player(data, grid_x, grid_y))
				my_mlx_pixel_put(data->image, grid_y * GRID_SIZE + i, \
				grid_x * GRID_SIZE + j, data->map->floor_color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	x_len;
	int	y_len;

	i = 0;
	j = 0;
	x_len = get_map_rows(data);
	y_len = slen(data->map->map_2d_white[i]);
	while (x_len > i)
	{
		j = 0;
		while (y_len > j)
		{
			draw_hor_lines(data, i, j);
			draw_ver_lines(data, i, j);
			j++;
		}
		i++;
		y_len = slen(data->map->map_2d_white[i]);
	}
}
