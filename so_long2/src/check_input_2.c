/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:05:11 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/20 16:49:54 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	horizontal_border(char **map_arr, int row)
{
	int	i;

	i = 0;
	while (map_arr[row][i])
	{
		if (map_arr[row][i] != '1')
			return (0);
		else
			i++;
	}
	return (1);
}

static int	vertical_border(char **map_arr, int side)
{
	int	i;

	i = 0;
	while (map_arr[i])
	{
		if (map_arr[i][side] != '1')
			return (0);
		else
			i++;
	}
	return (1);
}

int	is_wall_surround(char **argv, t_map *map)
{
	char	**map_arr;
	int		last_row;
	int		i;
	char	*str_map;

	str_map = map_to_str(argv);
	i = 0;
	last_row = 0;
	map_arr = ft_split(str_map, '\n');
	while (map_arr[last_row])
		last_row++;
	if (horizontal_border(map_arr, 0) == 0
		|| horizontal_border(map_arr, last_row - 1) == 0)
	{
		free_arr_str(map_arr, str_map);
		return (0);
	}
	if (vertical_border(map_arr, 0) == 0
		|| vertical_border(map_arr, (map->width_blocs) - 1) == 0)
	{
		free_arr_str(map_arr, str_map);
		return (0);
	}
	free_arr_str(map_arr, str_map);
	return (1);
}

void	check_valid_path(int column, int row, char **maze, t_map *map)
{
	if (map->reach_exit == 1 && map->collectible_check == map->collectible)
		map->validity = 1;
	if (maze[column][row] == 'E')
		map->reach_exit = 1;
	if (maze[column][row] == '0' || maze[column][row] == 'C'
		|| maze[column][row] == 'P')
	{
		if (maze[column][row] == 'C')
			map->collectible_check += 1;
		maze[column][row] = 'X';
		if (column < map->height_blocs - 1)
			check_valid_path (column + 1, row, maze, map);
		if (row < map->width_blocs - 1)
			check_valid_path (column, row + 1, maze, map);
		if (column > 0)
			check_valid_path(column - 1, row, maze, map);
		if (row > 0)
			check_valid_path(column, row - 1, maze, map);
	}
}

int	map_validity(char **argv, t_player *player, t_map *map)
{
	char		**arr_map;
	char		*str_map;

	str_map = map_to_str(argv);
	arr_map = mapstr_to_arr(str_map);
	player_position(argv, player);
	check_valid_path(player->player_y, player->player_x, arr_map, map);
	free(str_map);
	free_2d_arr(arr_map);
	if (map->validity == 0)
		return (0);
	return (1);
}
