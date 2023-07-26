/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:32:33 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/24 17:23:00 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

float	ray_distance(t_data *data)
{
	float	distance;

	distance = sqrt((data->rays->rx - data->player->pos_x) * \
	(data->rays->rx - data->player->pos_x) + \
	(data->rays->ry - data->player->pos_y) * \
	(data->rays->ry - data->player->pos_y));
	return (distance);
}

void	wall_texture_chooser(t_data *data)
{
	if (data->rays->dis_h > data->rays->dis_v)
	{
		data->rays->rx = data->rays->vx;
		data->rays->ry = data->rays->vy;
		data->rays->fin_dist = data->rays->dis_v;
		if (data->player->pos_x < data->rays->rx)
			data->tdata->tex = &data->east;
		else
			data->tdata->tex = &data->west;
		return ;
	}
	if (data->rays->dis_h < data->rays->dis_v)
	{
		data->rays->rx = data->rays->hx;
		data->rays->ry = data->rays->hy;
		data->rays->fin_dist = data->rays->dis_h;
		if (data->player->pos_y < data->rays->ry)
			data->tdata->tex = &data->south;
		else
			data->tdata->tex = &data->north;
		return ;
	}
}

void	run_raycaster(t_data *data)
{
	init_hor_ray_data(data);
	draw_hor_ray(data);
	init_ver_ray_data(data);
	draw_vert_ray(data);
	wall_texture_chooser(data);
}

void	draw_rays(t_data *data)
{
	int		rays;
	float	ra_angles;

	rays = 0;
	data->rays->ra = data->player->pa - (DEGREE * PLANE / 2);
	ra_angles = PLANE * DEGREE / 720;
	if (data->rays->ra < 0)
		data->rays->ra += 2 * PI;
	if (data->rays->ra > 2 * PI)
		data->rays->ra -= 2 * PI;
	while (rays < 720)
	{
		run_raycaster(data);
		set_wall_size(data);
		draw_walls(data, rays);
		data->rays->ra += ra_angles;
		if (data->rays->ra < 0)
		data->rays->ra += 2 * PI;
		if (data->rays->ra > 2 * PI)
		data->rays->ra -= 2 * PI;
		rays++;
	}
}
