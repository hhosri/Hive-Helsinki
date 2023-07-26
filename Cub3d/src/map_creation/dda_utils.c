/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:20:05 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/22 14:52:13 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	vert_is_it_a_wall(t_data *data)
{
	data->rays->vx = data->rays->rx;
	data->rays->vy = data->rays->ry;
	data->rays->dis_v = ray_distance(data);
	data->rays->dof = 8;
}

void	hor_is_it_a_wall(t_data *data)
{
	data->rays->hx = data->rays->rx;
	data->rays->hy = data->rays->ry;
	data->rays->dis_h = ray_distance(data);
	data->rays->dof = 8;
}

void	check_ray_len_overflow(t_data *data)
{
	if (data->rays->rx > WIN_WIDTH || data->rays->rx < 0)
		data->rays->rx = data->player->pos_x;
	if (data->rays->ry > WIN_HEIGHT || data->rays->ry < 0)
		data->rays->ry = data->player->pos_y;
}

int	get_map_rows(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map_2d_white[i] != NULL)
		i++;
	return (i);
}
