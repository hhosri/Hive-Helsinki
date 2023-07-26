/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:00:50 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/20 13:13:51 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	clr_vald_helper(int i, t_map *map)
{
	if (i == 3)
	{
		color_to_int(map);
		return (1);
	}
	else
	{
		ft_error_exit("Wrong number of arguments for RGB settings\n", 2);
		return (0);
	}	
}

static int	rgb_to_int(int rgb[3])
{
	int	color;

	color = rgb[0] * 65536 + rgb[1] * 256 + rgb[2];
	return (color);
}

static void	char_to_int(char **floor_rgb, char **ceiling_rgb, t_map *map)
{
	int	floor_rgb_int[3];
	int	ceil_rgb_int[3];
	int	i;

	i = 0;
	while (floor_rgb[i])
	{
		floor_rgb_int[i] = ft_atoi(floor_rgb[i]);
		ceil_rgb_int[i] = ft_atoi(ceiling_rgb[i]);
		i++;
	}
	map->floor_color = rgb_to_int(floor_rgb_int);
	map->ceil_color = rgb_to_int(ceil_rgb_int);
}

void	color_to_int(t_map *map)
{
	char	**floor_rgb;
	char	**ceiling_rgb;

	floor_rgb = ft_split_2(map->f_path, ',');
	ceiling_rgb = ft_split_2(map->c_path, ',');
	char_to_int(floor_rgb, ceiling_rgb, map);
	free_2d_arr(floor_rgb);
	free_2d_arr(ceiling_rgb);
}
