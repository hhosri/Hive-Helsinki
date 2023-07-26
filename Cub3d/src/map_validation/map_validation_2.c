/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:25:02 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/20 13:14:33 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	map_height(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_2d[i])
		i++;
	return (i);
}

static int	is_all_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_first_last_wall(t_map *map, int height)
{
	int	i;

	i = 1;
	while (i < height - 1)
	{
		if (map->map_2d[i][0] != '1'
			|| map->map_2d[i][ft_strlen(map->map_2d[i]) - 1] != '1')
			return (0);
		else
			i++;
	}
	return (1);
}

int	is_surrounded(t_map *map)
{
	int	height;

	height = map_height(map);
	if (!is_all_wall(map->map_2d[0])
		|| !is_all_wall(map->map_2d[height - 1])
		|| !is_first_last_wall(map, height) || !is_all_surrounded(map))
	{
		ft_error_exit("Map needs to be surrounded by walls\n", 2);
		return (0);
	}
	else
		return (1);
}
