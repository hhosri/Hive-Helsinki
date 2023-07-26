/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:28:59 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/24 17:04:43 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	close_all(t_data *data)
{
	free_text(&data->north);
	free_text(&data->south);
	free_text(&data->west);
	free_text(&data->east);
	exit (0);
}

int	keyhooks(int key, t_data *data)
{
	if (key == 53)
	{
		free_text(&data->north);
		free_text(&data->south);
		free_text(&data->west);
		free_text(&data->east);
		exit(0);
	}
	if (key == 13 || key == 1)
		w_s_keyhooks(key, data);
	if (key == 0 || key == 2)
		a_d_keyhooks(key, data);
	if (key == 123 || key == 124)
		turning_keyhooks(key, data);
	mlx_destroy_image(data->mlx_ptr, data->image->img_ptr);
	initialize_image(data);
	return (0);
}

void	shutdown(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

int	shutdown_int(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	init_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 17, 1L << 0, close_all, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, keyhooks, data);
}
