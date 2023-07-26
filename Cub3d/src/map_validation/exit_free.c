/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:39:48 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/26 13:05:39 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

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

void	free_text(t_texture *tex)
{
	int	i;

	i = 0;
	if (!tex || !tex->text_data)
		return ;
	while (i < tex->img_height)
	{
		free(tex->text_data[i]);
		i++;
	}
	free(tex->text_data);
}

void	free_all(t_map *map)
{
	free_2d_arr(map->all_2d);
	free_2d_arr(map->all_2d_white);
	free(map->all_arr);
	free(map->c_path);
	free(map->f_path);
	free(map->no_path);
	free(map->so_path);
	free(map->ea_path);
	free(map->we_path);
}

void	free_all_post_validation(t_map *map)
{
	free_2d_arr(map->all_2d);
	free_2d_arr(map->all_2d_white);
	free(map->all_arr);
	free(map->c_path);
	free(map->f_path);
	free(map->no_path);
	free(map->so_path);
	free(map->ea_path);
	free(map->we_path);
	free(map->x_size);
}

void	free_almost_all(t_map *map)
{
	free_2d_arr(map->all_2d);
	free_2d_arr(map->all_2d_white);
	free(map->all_arr);
}
