/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:03:20 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/20 16:48:04 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*create_map(char **argv)
{
	t_map	*map;
	char	*str_map;
	char	**arr_map;

	str_map = map_to_str(argv);
	arr_map = mapstr_to_arr(str_map);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = arr_map;
	map->collectible = 0;
	map->collectible_check = 0;
	map->reach_exit = 0;
	map ->exit = 0;
	map->start = 0;
	map->width_blocs = 0;
	map->height_blocs = 0;
	map->validity = 0;
	free(str_map);
	return (map);
}

t_player	*create_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x_target = 1;
	player->y_target = 1;
	player->win = 0;
	player->moves = 0;
	return (player);
}

void	player_position(char **argv, t_player *player)
{
	int		i;
	int		j;
	char	*str_map;
	char	**arr_map;

	str_map = map_to_str(argv);
	arr_map = mapstr_to_arr(str_map);
	i = 0;
	j = 0;
	while (arr_map[i])
	{
		j = 0;
		while (arr_map[i][j])
		{
			if (arr_map[i][j] == 'P')
			{
				player->player_x = j;
				player->player_y = i;
			}
			j++;
		}
		i++;
	}
	free_arr_str(arr_map, str_map);
}

void	fill_imgs_data(t_images *imgs_data, void *mlx)
{
	int	width;
	int	height;

	imgs_data->character_path = "./textures/character.xpm";
	imgs_data->wall_path = "./textures/wall.xpm";
	imgs_data->space_path = "./textures/space.xpm";
	imgs_data->exit_path = "./textures/finish.xpm";
	imgs_data->collectible_path = "./textures/box.xpm";
	imgs_data->win_path = "./textures/win.xpm";
	imgs_data->character_img = mlx_xpm_file_to_image(mlx,
			imgs_data->character_path, &width, &height);
	imgs_data->wall_img = mlx_xpm_file_to_image(mlx,
			imgs_data->wall_path, &width, &height);
	imgs_data->space_img = mlx_xpm_file_to_image(mlx,
			imgs_data->space_path, &width, &height);
	imgs_data->collectible_img = mlx_xpm_file_to_image(mlx,
			imgs_data->collectible_path, &width, &height);
	imgs_data->exit_img = mlx_xpm_file_to_image(mlx,
			imgs_data->exit_path, &width, &height);
	imgs_data->win_img = mlx_xpm_file_to_image(mlx,
			imgs_data->win_path, &width, &height);
}
