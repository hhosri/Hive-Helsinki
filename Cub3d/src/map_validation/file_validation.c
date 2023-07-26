/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:09:57 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/19 11:03:17 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	is_args_valid(int argc)
{
	if (argc < 2)
	{
		ft_error_exit("Program needs map as an argument.\n", 2);
		return (0);
	}
	else if (argc > 2)
	{
		ft_error_exit("Too many arguments.\n", 2);
		return (0);
	}
	else if (argc == 2)
		return (1);
	return (2);
}

static int	is_extension_valid(char **argv)
{
	char	*extension;

	if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
	{
		ft_error_exit("Wrong format.\n", 2);
		return (0);
	}
	else
	{
		extension = ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]));
		if (ft_strlen(extension) != 4)
		{
			ft_error_exit("wrong format.\n", 2);
			return (0);
		}
		else
			return (1);
	}
}

static int	try_open_file(char **argv, t_map *map)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_error_exit("Could not open file.\n", 2);
		return (0);
	}
	else
	{
		map->fd = fd;
		return (1);
	}
}

int	is_file_valid(int argc, char **argv, t_map *map)
{
	if (!is_args_valid(argc) || !is_extension_valid(argv)
		|| !try_open_file(argv, map))
		return (0);
	else if (!is_settings_available(argv, map))
	{
		free_almost_all(map);
		return (0);
	}
	else if (!is_settings_correct(map))
	{
		free_all(map);
		return (0);
	}
	else
	{
		copy_map(map);
		if (!is_map_valid(map))
		{
			free_all(map);
			return (0);
		}
		else
			return (1);
	}
}
