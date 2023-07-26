/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:00:49 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/24 13:07:00 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	is_empty_line_and_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

static int	map_start(t_map *map)
{
	int	i;

	i = 0;
	while (map->all_arr[i + 1])
	{
		if (map->all_arr[i] == '\n' && map->all_arr[i + 1] == '1')
		{
			return (i);
		}
		i++;
	}
	return (i);
}

static int	is_empty_line(t_map *map)
{
	int	i;

	i = map_start(map);
	while (map->all_arr[i + 1])
	{
		if (map->all_arr[i] == '\n' && map->all_arr[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	empty_line_exist(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_2d[i])
	{
		if (is_empty_line_and_space(map->map_2d[i]) == 0
			|| is_empty_line(map) == 0)
		{
			ft_error_exit("No Empty Lines allowed.\n", 2);
			return (0);
		}
		else
			i++;
	}
	return (1);
}
