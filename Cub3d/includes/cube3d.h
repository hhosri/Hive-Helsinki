/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:06:36 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/26 11:49:15 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../src/libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h> 
# include <math.h>

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define PEACH "\033[38;5;217m"
# define WHITE "\033[1;37m"
# define YELLOW "\033[0;33m"
# define WIN_WIDTH 720
# define WIN_HEIGHT 540
# define GRID_SIZE 15
# define PI 3.1415926535
# define PLANE 60
# define DEGREE 0.0174533
# define H_DEGREE 0.00872665

typedef struct s_map
{
	int		fd;
	int		file_size;
	char	*all_arr;
	char	**all_2d;
	char	**map_2d;
	char	**all_2d_white;
	char	**map_2d_white;
	char	**map_2d_complete;
	int		map_size;
	int		y_size;
	int		*x_size;
	int		x_size_max;
	int		map_x;
	int		map_y;
	int		is_no;
	int		is_so;
	int		is_ea;
	int		is_we;
	int		is_f;
	int		is_c;
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	char	*f_path;
	char	*c_path;
	int		floor_color;
	int		ceil_color;
	int		player_num;
	int		wall_color;
}				t_map;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_arrow
{
	int	x;
	int	y;
	int	endx;
	int	endy;
	int	brx;
	int	bry;
	int	brdx;
	int	brdy;
	int	stepx;
	int	stepy;
	int	error;
	int	err2;
}			t_arrow;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	pdx;
	float	pdy;
	float	pa;
	int		x_start;
	int		y_start;
	char	direction;
	int		color;
}				t_player;

typedef struct s_rays
{
	int		r;
	int		curx;
	int		cury;
	int		mp;
	int		mx;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	dis_v;
	float	dis_h;
	float	fin_dist;
	float	a_tan;
	float	n_tan;
}				t_rays;

typedef struct s_texture
{
	int		**text_data;
	int		img_width;
	int		img_height;
}				t_texture;

typedef struct s_texdata
{
	t_texture	*tex;
	float		tex_x;
	float		tex_y;
	int			tex_xi;
	int			tex_yi;
	int			height;
	int			wall_top;
	int			wall_bottom;
	int			draw_end;
	float		offs;
	float		mod_ofs;
	int			x;
}				t_texdata;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_keys;

typedef struct s_data
{
	t_map		*map;
	t_image		*image;
	t_player	*player;
	t_rays		*rays;
	t_texdata	*tdata;
	t_keys		*keys;
	void		*win_ptr;
	void		*mlx_ptr;
	t_texture	north;
	t_texture	east;
	t_texture	south;
	t_texture	west;
}				t_data;

//file validation
int		is_file_valid(int argc, char **argv, t_map *map);
int		is_settings_available(char **argv, t_map *map);
int		map_size(t_map *map);
void	map_to_arr(char **argv, t_map *map);
void	map_to_2d(t_map *map);
void	init_settings(t_map *map);
void	fill_color_xmp_paths(t_map *map);
int		is_settings_correct(t_map *map);
void	copy_map(t_map *map);
int		is_map_valid(t_map *map);
int		is_surrounded(t_map *map);
int		is_all_surrounded(t_map *map);
int		map_height(t_map *map);
int		can_player_move(t_map *map);
int		get_size(t_map *map);
void	color_to_int(t_map *map);
int		clr_vald_helper(int i, t_map *map);
int		empty_line_exist(t_map *map);
int		is_it_player(char c);
//error-exit-free
void	ft_error_exit(char *msg, int success_status);
void	free_2d_arr(char **arr);
void	free_all(t_map *map);
void	free_almost_all(t_map *map);
void	free_all_post_validation(t_map *map);
void	free_text(t_texture *tex);
//keys
void	init_hooks(t_data *data);
int		a_d_keyhooks(int key, t_data *data);
int		w_s_keyhooks(int key, t_data *data);
int		turning_keyhooks(int key, t_data *data);
//initialize
void	init_data(t_data *data);
//image
void	initialize_image(t_data *data);
void	draw_player(t_data *data);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	draw_map(t_data *data);
//textures
void	assign_textures(t_data *data);
void	set_wall_size(t_data *data);
void	draw_walls(t_data *data, int rays);
//texture utils
void	draw_stripe_helper(t_data *data);
void	init_draw_stripe(t_data *data);
//raycaster
void	draw_rays(t_data *data);
void	draw_vert_ray(t_data *data);
void	draw_hor_ray(t_data *data);
float	ray_distance(t_data *data);
//raycaster utils
void	vert_is_it_a_wall(t_data *data);
void	hor_is_it_a_wall(t_data *data);
void	check_ray_len_overflow(t_data *data);
//map utils
int		slen(char *str);
int		get_map_rows(t_data *data);
void	init_hor_ray_data(t_data *data);
void	init_ver_ray_data(t_data *data);
int		check_if_player_in_map(t_data *data);
//player
void	set_player_looking_dir(t_data *data);
void	find_player(t_data *data);
int		check_if_player_in_map(t_data *data);
#endif