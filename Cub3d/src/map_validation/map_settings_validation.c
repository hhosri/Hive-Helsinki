/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_settings_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:22:12 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/20 13:14:28 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	is_all_settings_available(t_map *map)
{
	if (map->is_c == 1 && map->is_f == 1
		&& map->is_ea == 1 && map->is_no == 1
		&& map->is_so == 1 && map->is_we == 1)
		return (1);
	else
	{
		return (0);
	}
}

static int	settings_availibility(t_map *map)
{
	int	i;

	i = 0;
	while (map->all_2d[i])
	{
		if (ft_strnstr(map->all_2d[i], "NO ", ft_strlen(map->all_2d[i])))
			map->is_no++;
		else if (ft_strnstr(map->all_2d[i], "SO ", ft_strlen(map->all_2d[i])))
			map->is_so++;
		else if (ft_strnstr(map->all_2d[i], "EA ", ft_strlen(map->all_2d[i])))
			map->is_ea++;
		else if (ft_strnstr(map->all_2d[i], "WE ", ft_strlen(map->all_2d[i])))
			map->is_we++;
		else if (ft_strnstr(map->all_2d[i], "C ", ft_strlen(map->all_2d[i])))
			map->is_c++;
		else if (ft_strnstr(map->all_2d[i], "F ", ft_strlen(map->all_2d[i])))
			map->is_f++;
		i++;
	}
	return (is_all_settings_available(map));
}

static void	parse_map(char **argv, t_map *map)
{
	map->file_size = map_size(map);
	map_to_arr(argv, map);
	map_to_2d(map);
	init_settings(map);
}

int	is_settings_available(char **argv, t_map *map)
{
	parse_map(argv, map);
	if (settings_availibility(map))
	{
		fill_color_xmp_paths(map);
		return (1);
	}
	else
	{
		ft_error_exit("Missing or Duplicate map settings!\n", 2);
		return (0);
	}
}
