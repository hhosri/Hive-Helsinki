/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:33:45 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/24 16:56:19 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x < WIN_WIDTH && x >= 0 && y < WIN_HEIGHT && y >= 0)
	{
		dst = image->addr + (y * image->line_length + \
		x * (image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_background(t_data *data)
{
	int	j;
	int	i;

	i = 0;
	while (i < WIN_HEIGHT / 2)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			my_mlx_pixel_put(data->image, j, i, data->map->ceil_color);
			j++;
		}
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			my_mlx_pixel_put(data->image, j, i, data->map->floor_color);
			j++;
		}
		i++;
	}
}

void	initialize_image(t_data *data)
{
	data->image->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->image->addr = mlx_get_data_addr(data->image->img_ptr, \
		&data->image->bits_per_pixel, \
		&data->image->line_length, &data->image->endian);
	if (data->player->pos_x == 0)
	{
		find_player(data);
		data->player->pos_x = data->player->x_start + GRID_SIZE / 2;
		data->player->pos_y = data->player->y_start + GRID_SIZE / 2;
		set_player_looking_dir(data);
	}
	draw_background(data);
	draw_rays(data);
	draw_map(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx_ptr, \
	data->win_ptr, data->image->img_ptr, 0, 0);
}
