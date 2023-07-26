/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:30:56 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/26 11:32:26 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	check_too_close_x(t_data *data)
{
	if ((int)data->player->pos_x % GRID_SIZE < 2)
	{
		if (data->map->map_2d_white[(int)data->player->pos_y / GRID_SIZE] \
		[(int)data->player->pos_x / GRID_SIZE - 1] == '1')
		{
			data->player->pos_x = data->player->x_start + GRID_SIZE / 2;
			data->player->pos_y = data->player->y_start + GRID_SIZE / 2;
			initialize_image(data);
			return (1);
		}
	}
	else if ((int)data->player->pos_x % GRID_SIZE >= GRID_SIZE - 2)
	{
		if (data->map->map_2d_white[(int)data->player->pos_y / GRID_SIZE] \
		[(int)data->player->pos_x / GRID_SIZE + 1] == '1')
		{
			data->player->pos_x = data->player->x_start + GRID_SIZE / 2;
			data->player->pos_y = data->player->y_start + GRID_SIZE / 2;
			initialize_image(data);
			return (1);
		}
	}
	return (0);
}

int	check_if_too_close(t_data *data)
{
	if ((int)data->player->pos_y % GRID_SIZE < 2)
	{
		if (data->map->map_2d_white[(int)data->player->pos_y / GRID_SIZE - 1] \
		[(int)data->player->pos_x / GRID_SIZE] == '1')
		{
			data->player->pos_x = data->player->x_start + GRID_SIZE / 2;
			data->player->pos_y = data->player->y_start + GRID_SIZE / 2;
			initialize_image(data);
			return (1);
		}
	}
	else if ((int)data->player->pos_y % GRID_SIZE >= GRID_SIZE - 2)
	{
		if (data->map->map_2d_white[(int)data->player->pos_y / GRID_SIZE + 1] \
		[(int)data->player->pos_x / GRID_SIZE] == '1')
		{
			data->player->pos_x = data->player->x_start + GRID_SIZE / 2;
			data->player->pos_y = data->player->y_start + GRID_SIZE / 2;
			initialize_image(data);
			return (1);
		}
	}
	if (check_too_close_x(data))
		return (1);
	return (0);
}

int	check_if_player_in_wall(t_data *data)
{
	if (check_if_too_close(data))
		return (1);
	if (data->player->pos_y > (data->map->y_size * GRID_SIZE))
		data->player->pos_y = ((int)data->player->pos_y * \
		GRID_SIZE - GRID_SIZE - 1);
	if (data->player->pos_x > (data->map->x_size_max * GRID_SIZE - GRID_SIZE))
		data->player->pos_x = ((int)data->player->pos_x * \
		GRID_SIZE - GRID_SIZE - 1);
	if (data->map->map_2d_white[(int)data->player->pos_y / GRID_SIZE] \
	[(int)data->player->pos_x / GRID_SIZE] == '1' \
	|| data->map->map_2d_white[(int)data->player->pos_y / GRID_SIZE] \
	[(int)data->player->pos_x / GRID_SIZE] == ' ' \
	|| data->player->pos_x < GRID_SIZE + GRID_SIZE / 5 \
	|| data->player->pos_y < GRID_SIZE + GRID_SIZE / 5)
	{
		data->player->pos_x = data->player->x_start + GRID_SIZE / 2;
		data->player->pos_y = data->player->y_start + GRID_SIZE / 2;
		initialize_image(data);
		return (1);
	}
	return (0);
}

int	check_if_player_in_map(t_data *data)
{
	if (check_if_player_in_wall(data))
		return (1);
	if (data->player->pos_y > (data->map->y_size * GRID_SIZE))
		data->player->pos_y -= ((int)data->player->pos_y % GRID_SIZE + 1);
	if (data->player->pos_x < 0 || data->player->pos_x > \
	data->map->x_size_max * GRID_SIZE - GRID_SIZE * 1.5)
	{
		data->player->pos_x = data->player->x_start + GRID_SIZE / 2;
		data->player->pos_y = data->player->y_start + GRID_SIZE / 2;
		initialize_image(data);
		return (1);
	}
	else if (data->player->pos_y < 0 || data->player->pos_y > \
	((data->map->y_size * GRID_SIZE) - (GRID_SIZE / 5)))
	{
		data->player->pos_x = data->player->x_start + GRID_SIZE / 2;
		data->player->pos_y = data->player->y_start + GRID_SIZE / 2;
		initialize_image(data);
		return (1);
	}
	return (0);
}
