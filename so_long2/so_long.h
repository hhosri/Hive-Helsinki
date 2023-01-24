/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:06:36 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/23 11:18:32 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h> 

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define PEACH "\033[38;5;217m"
# define WHITE "\033[1;37m"
# define YELLOW "\033[0;33m"

//map dimensions are counter form 1
typedef struct s_map
{
	char	**map;
	int		exit;
	int		start;
	int		collectible;
	int		collectible_check;
	int		reach_exit;
	int		width_blocs;
	int		height_blocs;
	int		validity;
}				t_map;

//player x and y are counted from 0
typedef struct s_player
{
	int		player_x;
	int		player_y;
	int		x_target;
	int		y_target;
	int		win;
	int		moves;
}				t_player;

typedef struct s_images
{
	void	*wall_img;
	void	*space_img;
	void	*character_img;
	void	*exit_img;
	void	*collectible_img;
	void	*win_img;
	char	*win_path;
	char	*wall_path;
	char	*space_path;
	char	*character_path;
	char	*exit_path;
	char	*collectible_path;
	int		img_x;
	int		img_y;

}				t_images;

typedef struct s_objects
{
	t_map		*map;
	t_player	*player;
	t_images	*imgs;
	void		*mlx;
	void		*mlx_win;
}				t_objects;

void		program_error(t_map	*map, t_player *player, char **map_arr);
void		program_error_beginning(t_map	*map, t_player *player);
void		program_success(t_map	*map, t_player *player, char **map_arr);
t_map		*read_map(char **argv);
t_map		*create_map(char **argv);
int			map_size(char **argv);
char		*map_to_str(char **argv);
char		**mapstr_to_arr(char *str_map);
int			is_wall_surround(char **argv, t_map *map);
void		free_2d_arr(char **arr);
void		free_arr_str(char **arr, char *str);
t_player	*create_player(void);
void		player_position(char **argv, t_player *player);
int			map_validity(char **argv, t_player *player, t_map *map);
void		check_valid_path(int column, int row, char **maze, t_map *map);
int			input_check(t_map *map, char **argv);
t_images	*img_strct_print_map(void *mlx, void *mlx_win, char **arr_map);
void		start_game(t_objects *obj_data);
void		do_move(int keycode, t_objects *data);
void		do_move_collect(int keycode, t_objects *data);
void		handle_exit(t_objects *data);
int			close_window(t_objects *data);
void		winning_splash(t_objects *data);
void		moves_counter(t_objects *data);
void		free_all_imgs(t_objects *data);
void		fill_imgs_data(t_images *imgs_data, void *mlx);
void		player_almost_wins(t_objects *data);
#endif