/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:06:57 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/20 14:39:08 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_arr_str(char **arr, char *str)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free (str);
}

void	program_error(t_map	*map, t_player *player, char **map_arr)
{
	exit(EXIT_FAILURE);
	free(map);
	free(player);
	free_2d_arr(map_arr);
}

void	program_error_beginning(t_map	*map, t_player *player)
{
	exit(EXIT_FAILURE);
	free(map);
	free(player);
}

void	free_all_imgs(t_objects *data)
{
	mlx_destroy_image(data->mlx, data->imgs->character_img);
	mlx_destroy_image(data->mlx, data->imgs->exit_img);
	mlx_destroy_image(data->mlx, data->imgs->wall_img);
	mlx_destroy_image(data->mlx, data->imgs->collectible_img);
	mlx_destroy_image(data->mlx, data->imgs->space_img);
	mlx_destroy_image(data->mlx, data->imgs->win_img);
}
