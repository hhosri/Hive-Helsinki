/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:16:43 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/26 11:29:34 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

float	fisheye_solver(t_data *data)
{
	float	ca;

	ca = data->rays->ra - data->player->pa;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	return (ca);
}

void	set_wall_size(t_data *data)
{
	float	ca;

	ca = 0;
	if (data->rays->dis_h < data->rays->dis_v)
	{
		data->tdata->tex_x = fmod(data->rays->rx, data->map->x_size_max);
		data->tdata->tex_x = data->tdata->tex_x / \
		data->map->x_size_max * data->tdata->tex->img_width;
	}
	else
	{
		data->tdata->tex_x = fmod(data->rays->ry, data->map->x_size_max);
		data->tdata->tex_x = data->tdata->tex_x / \
		data->map->x_size_max * data->tdata->tex->img_width;
	}
	ca = fisheye_solver(data);
	data->rays->fin_dist = data->rays->fin_dist * cos(ca);
	data->tdata->height = data->map->y_size * \
	(WIN_HEIGHT / 2 * 3) / (data->rays->fin_dist - 1);
	data->tdata->wall_bottom = (WIN_HEIGHT / 2) + (data->tdata->height / 2);
	data->tdata->wall_top = (WIN_HEIGHT / 2) - (data->tdata->height / 2);
	data->rays->ry = data->tdata->wall_top;
	data->tdata->draw_end = data->tdata->x + (WIN_WIDTH / PLANE);
}

void	help_draw_walls(t_data *data, int rays)
{
	while (data->rays->ry <= data->tdata->wall_bottom \
	&& data->rays->ry < WIN_HEIGHT)
	{
		if (data->tdata->tex_xi >= data->tdata->tex->img_width)
			data->tdata->tex_xi = 0;
		if (data->tdata->tex_yi >= data->tdata->tex->img_height)
			data->tdata->tex_yi = 0;
		if (data->rays->rx >= 0 && data->rays->ry >= 0 && \
		data->rays->rx < WIN_WIDTH && data->rays->ry < WIN_HEIGHT)
			my_mlx_pixel_put(data->image, rays, data->rays->ry, \
			data->tdata->tex->text_data \
			[data->tdata->tex_yi][data->tdata->tex_xi]);
		data->rays->ry++;
		if (data->tdata->mod_ofs < 1)
			data->tdata->mod_ofs = data->tdata->mod_ofs + data->tdata->offs;
		else
		{
			data->tdata->tex_yi += (int)data->tdata->mod_ofs;
			data->tdata->mod_ofs = data->tdata->offs \
			+ fmod(data->tdata->mod_ofs, 1);
		}
	}
	data->tdata->tex_x += (data->tdata->offs / 2);
	if (data->tdata->tex_x > data->tdata->tex->img_width)
		data->tdata->tex_x = 0;
}

void	draw_walls(t_data *data, int rays)
{
	int	i;

	i = 0;
	init_draw_stripe(data);
	draw_stripe_helper(data);
	while (i < 2)
	{
		help_draw_walls(data, rays);
		i++;
	}
}
