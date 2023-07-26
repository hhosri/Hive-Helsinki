/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sizes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:54:01 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/26 12:00:00 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	get_y_size(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_2d_white[i])
		i++;
	map->y_size = i;
	if (map->y_size > (WIN_HEIGHT / GRID_SIZE))
		return (0);
	else
		return (1);
}

static void	get_x_and_map_size(t_map *map)
{
	int	i;

	i = 0;
	map->x_size = malloc(sizeof(int) * map->y_size);
	while (map->map_2d_white[i])
	{
		map->x_size[i] = ft_strlen(map->map_2d_white[i]);
		i++;
	}
}

static int	get_x_size_max(t_map *map)
{
	int	i;
	int	temp_size;
	int	size;

	temp_size = 0;
	size = 0;
	i = 0;
	while (map->map_2d_white[i])
	{
		temp_size = ft_strlen(map->map_2d_white[i]);
		if (temp_size > size)
			size = temp_size;
		i++;
	}
	map->x_size_max = size;
	if (map->x_size_max > (WIN_WIDTH / GRID_SIZE))
		return (0);
	else
		return (1);
}

int	get_size(t_map *map)
{
	if (get_y_size(map) == 0 || get_x_size_max(map) == 0)
	{
		ft_error_exit("Map size is larger than screen\n", 2);
		return (0);
	}
	else
	{
		get_x_and_map_size(map);
		map->map_size = map->y_size * map->x_size_max;
		return (1);
	}
}
