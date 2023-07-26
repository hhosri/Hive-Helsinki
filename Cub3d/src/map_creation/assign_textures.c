/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:57:10 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/24 17:03:32 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	get_array_size(t_texture *texture)
{
	int	i;

	i = 0;
	texture->text_data = ft_calloc(texture->img_height, (sizeof(int *)));
	while (i < texture->img_height)
	{
		texture->text_data[i] = ft_calloc(texture->img_width, (sizeof(int)));
		i++;
	}
}

t_texture	get_texture_values(t_data *data, t_image *image, char *path)
{
	t_texture	tex;
	int			i;
	int			j;

	image->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, \
	&tex.img_width, &tex.img_height);
	image->data = (int *) mlx_get_data_addr(image->img_ptr, \
	&image->bits_per_pixel, &image->line_length, &image->endian);
	get_array_size(&tex);
	i = 0;
	while (i < tex.img_height)
	{
		j = 0;
		while (j < tex.img_width)
		{
			tex.text_data[i][j] = image->data[tex.img_width * i + j];
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx_ptr, image->img_ptr);
	return (tex);
}

void	assign_textures(t_data *data)
{
	t_image	image;

	data->north = get_texture_values(data, &image, data->map->no_path);
	if (data->north.text_data == NULL)
		ft_error_exit("Data north malloc failure\n", 0);
	data->east = get_texture_values(data, &image, data->map->ea_path);
	if (data->east.text_data == NULL)
		ft_error_exit("Data east malloc failure\n", 0);
	data->west = get_texture_values(data, &image, data->map->we_path);
	if (data->west.text_data == NULL)
		ft_error_exit("Data west malloc failure\n", 0);
	data->south = get_texture_values(data, &image, data->map->so_path);
	if (data->south.text_data == NULL)
		ft_error_exit("Data south malloc failure\n", 0);
}
