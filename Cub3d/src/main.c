/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:25:02 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/26 13:07:23 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	open_win(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (data->win_ptr == NULL)
	{
		free(data->image);
		return (0);
	}
	assign_textures(data);
	initialize_image(data);
	init_hooks(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	data;

	map = malloc(sizeof(t_map));
	data.map = map;
	if (is_file_valid(argc, argv, map) == 0)
	{
		close(map->fd);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (get_size(map) == 1)
		{
			init_data(&data);
			open_win(&data);
		}
		else
			free_2d_arr(map->map_2d_complete);
	}
	free_all_post_validation(map);
	free(map);
	return (0);
}
