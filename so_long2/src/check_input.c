/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:04:17 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/23 10:55:01 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	mandatory_parts(t_map *map)
{
	if (map->collectible == 0 || map->exit == 0 || map->start == 0)
		return (0);
	if (map->exit > 1 || map->start > 1)
		return (0);
	return (1);
}

static int	is_rectangle(t_map *map)
{
	if (map->width_blocs == map->height_blocs)
		return (0);
	return (1);
}

static int	is_c_allowed(char *str_map)
{
	int	i;

	i = 0;
	while (str_map[i])
	{
		if (str_map[i] != 'C' && str_map[i] != 'E' && str_map[i] != 'P'
			&& str_map[i] != '1' && str_map[i] != '0' && str_map[i] != '\n')
			return (0);
		else
			i++;
	}
	return (1);
}

static int	is_same_len(char **argv)
{
	char	**map_arr;
	int		i;
	char	*map_str;

	map_str = map_to_str(argv);
	i = 0;
	map_arr = ft_split(map_str, '\n');
	while (map_arr[i + 1])
	{
		if (ft_strlen(map_arr[i]) != ft_strlen(map_arr[i + 1]))
		{
			free_arr_str(map_arr, map_str);
			return (0);
		}
		else
			i++;
	}
	free_arr_str(map_arr, map_str);
	return (1);
}

int	input_check(t_map *map, char **argv)
{	
	char	*str_map;
	char	**arr_map;

	str_map = map_to_str(argv);
	arr_map = mapstr_to_arr(str_map);
	if (mandatory_parts(map) == 0 || is_rectangle(map) == 0
		|| is_c_allowed(str_map) == 0 || is_same_len(argv) == 0
		|| is_wall_surround(argv, map) == 0)
	{
		ft_printf(RED);
		if (mandatory_parts(map) == 0)
			ft_printf("Error\nMissing objects or Duplicates!\n");
		else if (is_rectangle(map) == 0)
			ft_printf("Error\nMap is not a rectangle!\n");
		else if (is_c_allowed(str_map) == 0)
			ft_printf("Error\nInvalid character in the map!\n");
		else if (is_same_len(argv) == 0)
			ft_printf("Error\nNot all lines have the same length!\n");
		else if (is_wall_surround(argv, map) == 0)
			ft_printf("Error\nThe map is not surrounded by walls!\n");
		free_arr_str(arr_map, str_map);
		return (0);
	}
	free_arr_str(arr_map, str_map);
	return (1);
}
