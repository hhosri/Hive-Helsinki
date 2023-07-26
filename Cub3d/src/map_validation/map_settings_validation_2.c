/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_settings_validation_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:41:41 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/20 13:14:22 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	can_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	else
	{
		close(fd);
		return (1);
	}
}

static int	is_texture_correct(char *path)
{
	char	*extension;

	extension = path + (ft_strlen(path) - 4);
	if (ft_strncmp(".xpm", extension, ft_strlen(extension)) != 0)
	{
		ft_error_exit("Texture extension should be .xpm\n", 2);
		return (0);
	}
	else
	{
		if (can_open(path) == 0)
		{
			ft_printf("Cannot open: %s\n", path);
			return (0);
		}
		else
			return (1);
	}
}

static int	is_number(char *rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (ft_isdigit(rgb[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	is_color_correct(char *color, t_map *map)
{
	char	**rgb_arr;
	int		i;

	i = 0;
	rgb_arr = ft_split(color, ',');
	while (rgb_arr[i])
	{	
		if ((ft_atoi(rgb_arr[i]) >= 0
				&& ft_atoi(rgb_arr[i]) <= 255 && is_number(rgb_arr[i])))
			i++;
		else
		{
			free_2d_arr(rgb_arr);
			ft_error_exit("RGB code doesn't exist\n", 2);
			return (0);
		}
	}
	free_2d_arr(rgb_arr);
	return (clr_vald_helper(i, map));
}

int	is_settings_correct(t_map *map)
{
	if (is_color_correct(map->f_path, map) && is_color_correct(map->c_path, map)
		&& is_texture_correct(map->no_path) && is_texture_correct(map->so_path)
		&& is_texture_correct(map->ea_path) && is_texture_correct(map->we_path))
		return (1);
	else
		return (0);
}
