/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:25:02 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/24 13:25:05 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	longest_row(char **map_2d_white)
{
	size_t	longest_row;
	int		i;

	i = 0;
	longest_row = 0;
	while (map_2d_white[i])
	{
		if (ft_strlen(map_2d_white[i]) > longest_row)
			longest_row = ft_strlen(map_2d_white[i]);
		i++;
	}
	return (longest_row);
}

static void	copy_fill(char *src, char *dst, int dstSize, char c)
{
	int	src_len;
	int	i;

	src_len = ft_strlen(src);
	i = src_len;
	ft_strlcpy(dst, src, dstSize);
	while (i < dstSize)
	{
		dst[i] = c;
		i++;
	}
	dst[dstSize - 1] = '\0';
}

static int	check_surroudings(char **all_map, t_map *map)
{
	int	i;
	int	last;
	int	j;

	last = map_height(map) - 1;
	i = 1;
	while (i <= last)
	{
		j = 0;
		while (all_map[i][j])
		{
			if ((all_map[i][j] == '0' || is_it_player(all_map[i][j]))
				&& (all_map[i - 1][j] == ' '
				|| all_map[i + 1][j] == ' '
				|| all_map[i][j + 1] == ' ' || all_map[i][j - 1] == ' '))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_all_surrounded(t_map *map)
{
	int	i;
	int	status;

	map->map_2d_complete = malloc(sizeof(char *) * (map_height(map) + 1));
	i = 0;
	while (map->map_2d_white[i])
	{
		map->map_2d_complete[i] = malloc(sizeof(char)
				* (longest_row(map->map_2d_white) + 1));
		copy_fill(map->map_2d_white[i], map->map_2d_complete[i],
			longest_row(map->map_2d_white), ' ');
		i++;
	}
	status = check_surroudings(map->map_2d_complete, map);
	return (status);
}
