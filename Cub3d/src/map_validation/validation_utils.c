/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:51:35 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/20 13:14:57 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	map_size(t_map *map)
{
	int		i;
	int		bytes;
	char	buffer[2];
	int		size;

	size = 0;
	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	while (bytes == 1)
	{
		bytes = read(map->fd, buffer, 1);
		if (bytes != 1)
			break ;
		size++;
	}
	close(map->fd);
	return (size);
}

void	map_to_arr(char **argv, t_map *map)
{
	int		bytes;
	char	buff[2];
	int		i;

	map->fd = open(argv[1], O_RDONLY);
	i = 0;
	bytes = 1;
	map->all_arr = (char *)malloc(sizeof(*map->all_arr) * (map->file_size + 1));
	while (bytes)
	{
		bytes = read(map->fd, buff, 1);
		if (!bytes)
			break ;
		map->all_arr[i] = buff[0];
		i++;
	}
	map->all_arr[i] = '\0';
	close(map->fd);
}

void	map_to_2d(t_map *map)
{
	map->all_2d = ft_split(map->all_arr, '\n');
	map->all_2d_white = ft_split_2(map->all_arr, '\n');
}

void	copy_map(t_map *map)
{
	map->map_2d = &map->all_2d[6];
	map->map_2d_white = &map->all_2d_white[6];
}
