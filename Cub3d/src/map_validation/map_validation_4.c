/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:25:02 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/20 13:26:24 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	is_it_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

static int	is_it_surrounded(int i, int j, t_map *map)
{
	if (map->map_2d_complete[i + 1][j] == '1'
		&& map->map_2d_complete[i - 1][j] == '1'
		&& map->map_2d_complete[i][j + 1] == '1'
		&& map->map_2d_complete[i][j - 1] == '1')
		return (0);
	else
		return (1);
}

static int	helper(int i, int j, t_map *map)
{
	if (is_it_surrounded(i, j, map))
		return (1);
	else
	{
		ft_error_exit("Player can not move", 2);
		return (0);
	}
}

int	can_player_move(t_map *map)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while (map->map_2d_complete[i])
	{
		j = 0;
		while (map->map_2d_complete[i][j])
		{
			if (is_it_player(map->map_2d_complete[i][j]))
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found)
			break ;
		i++;
	}
	return (helper(i, j, map));
}
