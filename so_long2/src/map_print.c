/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:54:53 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/20 11:11:53 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_p(void *mlx, void *mlx_win, t_images *imgs_data)
{
	mlx_put_image_to_window(mlx, mlx_win, imgs_data->space_img,
		imgs_data->img_x, imgs_data->img_y);
	mlx_put_image_to_window(mlx, mlx_win, imgs_data->character_img,
		imgs_data->img_x, imgs_data->img_y);
}

static void	print_img(void *mlx, void *mlx_win, t_images *imgs_data, char c)
{
	if (c == '0')
		mlx_put_image_to_window(mlx, mlx_win, imgs_data->space_img,
			imgs_data->img_x, imgs_data->img_y);
	else if (c == '1')
		mlx_put_image_to_window(mlx, mlx_win, imgs_data->wall_img,
			imgs_data->img_x, imgs_data->img_y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(mlx, mlx_win, imgs_data->space_img,
			imgs_data->img_x, imgs_data->img_y);
		mlx_put_image_to_window(mlx, mlx_win, imgs_data->collectible_img,
			imgs_data->img_x, imgs_data->img_y);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(mlx, mlx_win, imgs_data->space_img,
			imgs_data->img_x, imgs_data->img_y);
		mlx_put_image_to_window(mlx, mlx_win, imgs_data->exit_img,
			imgs_data->img_x, imgs_data->img_y);
	}
	else if (c == 'P')
		print_p(mlx, mlx_win, imgs_data);
}

static void	print_map(void *mlx, void *mlx_win,
	t_images *imgs_data, char **arr_map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (arr_map[i])
	{
		x = 0;
		j = 0;
		while (arr_map[i][j])
		{
			imgs_data->img_x = x;
			imgs_data->img_y = y;
			print_img(mlx, mlx_win, imgs_data, arr_map[i][j]);
			j++;
			x += 60;
		}
		y += 60;
		i++;
	}
}

t_images	*img_strct_print_map(void *mlx, void *mlx_win, char **arr_map)
{
	t_images	*imgs_data;

	imgs_data = (t_images *)malloc(sizeof(*imgs_data));
	if (!imgs_data)
		return (NULL);
	fill_imgs_data(imgs_data, mlx);
	print_map(mlx, mlx_win, imgs_data, arr_map);
	return (imgs_data);
}
