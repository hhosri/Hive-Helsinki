/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:40 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/23 10:55:27 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_objects	*create_object(t_map *map,
	t_player *player, t_images *imgs_data)
{
	t_objects	*data;

	data = (t_objects *)malloc(sizeof(*data));
	if (!data)
		return (NULL);
	data->imgs = imgs_data;
	data->player = player;
	data->map = map;
	return (data);
}

static void	init_screen(t_map *map, t_player *player)
{
	void		*mlx;
	void		*mlx_win;
	t_images	*imgs_data;
	t_objects	*data;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->width_blocs * 60,
			map->height_blocs * 60, "so_long");
	imgs_data = img_strct_print_map(mlx, mlx_win, map->map);
	data = create_object(map, player, imgs_data);
	data->mlx = mlx;
	data->mlx_win = mlx_win;
	start_game(data);
	mlx_loop(mlx);
}

static void	check_args_format(int argc, char **argv,
	t_map *map, t_player *player)
{
	if (argc != 2 || (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL))
	{	
		ft_printf(RED);
		if (argc != 2)
			ft_printf("Error\nNot enough arguments/too many arguments\n");
		else if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
			ft_printf("Error\nInvalid Format\n");
		ft_printf(WHITE);
		program_error_beginning(map, player);
	}
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_player	*player;

	map = NULL;
	player = NULL;
	check_args_format(argc, argv, map, player);
	map = read_map(argv);
	player = create_player();
	if (input_check(map, argv) == 0)
	{
		ft_printf(WHITE);
		program_error(map, player, map->map);
	}
	else if (map_validity(argv, player, map) == 0)
	{
		ft_printf(RED);
		ft_printf("Error\nNo valid path!\n");
		ft_printf(WHITE);
		program_error(map, player, map->map);
	}
	else
		init_screen(map, player);
	return (0);
}
