/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:25:02 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/20 13:26:09 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	allowed_c(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'W'
		&& c != 'E' && c != 'S' && c != ' ' && c != '\t')
		return (0);
	else
		return (1);
}

static int	is_foreign_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_2d[i])
	{
		j = 0;
		while (map->map_2d[i][j])
		{
			if (!allowed_c(map->map_2d[i][j]))
			{
				ft_error_exit("No foreign characters allowed.\n", 2);
				return (0);
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}

static int	is_player(char c)
{
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return (1);
	else
		return (0);
}

static int	is_only_one(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_2d[i])
	{
		j = 0;
		while (map->map_2d[i][j])
		{
			if (is_player(map->map_2d[i][j]) == 1)
				map->player_num++;
			j++;
		}
		i++;
	}
	if (map->player_num != 1)
	{
		ft_error_exit("Too many or No players.\n", 2);
		return (0);
	}
	else
		return (1);
}

int	is_map_valid(t_map *map)
{
	if (is_foreign_characters(map) == 0 || is_only_one(map) == 0
		|| is_surrounded(map) == 0 || can_player_move(map) == 0
		|| empty_line_exist(map) == 0)
		return (0);
	else
		return (1);
}
