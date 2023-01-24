/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:01:15 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/20 11:16:53 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	map_height(char **argv, t_map *map)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
			lines++;
		free(line);
	}
	map->height_blocs = lines;
	close(fd);
}

static void	map_width(char **argv, t_map *map)
{
	int		fd;
	int		len;
	int		bytes;
	char	buff[2];

	fd = open(argv[1], O_RDONLY);
	len = 0;
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buff, 1);
		if (buff[0] == '\n')
			break ;
		else
			len++;
	}
	map->width_blocs = len;
	close(fd);
}

t_map	*read_map(char **argv)
{
	int		fd;
	int		bytes;
	char	buff[2];
	t_map	*map;

	map = create_map(argv);
	bytes = 1;
	fd = open(argv[1], O_RDONLY);
	while (bytes)
	{
		bytes = read(fd, buff, 1);
		if (bytes != 1)
			break ;
		if (buff[0] == 'E')
			map->exit += 1;
		if (buff[0] == 'P')
			map->start += 1;
		if (buff[0] == 'C')
			map->collectible += 1;
	}
	map_height(argv, map);
	map_width(argv, map);
	close(fd);
	return (map);
}

char	*map_to_str(char **argv)
{
	int		fd;
	int		bytes;
	char	buff[2];
	char	*map_str;
	int		i;

	i = 0;
	bytes = 1;
	fd = open(argv[1], O_RDONLY);
	map_str = (char *)malloc(sizeof(*map_str) * map_size(argv) + 1);
	while (bytes)
	{
		bytes = read(fd, buff, 1);
		if (!bytes)
			break ;
		map_str[i] = buff[0];
		i++;
	}
	map_str[i] = '\0';
	close(fd);
	return (map_str);
}

char	**mapstr_to_arr(char *str_map)
{
	char	**map_arr;

	map_arr = ft_split(str_map, '\n');
	return (map_arr);
}
