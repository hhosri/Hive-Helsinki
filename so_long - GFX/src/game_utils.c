/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:30:29 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/23 11:18:55 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_exit(t_objects *data)
{
	free_2d_arr(data->map->map);
	free(data->map);
	free(data->player);
	free_all_imgs(data);
	free(data->imgs);
	mlx_clear_window(data->mlx, data->mlx_win);
	free(data);
	ft_printf(YELLOW);
	ft_printf("GAME QUIT SUCCESFULLY\n");
	ft_printf(WHITE);
	exit(0);
}

int	close_window(t_objects *data)
{
	handle_exit(data);
	return (1);
}

void	winning_splash(t_objects *data)
{
	int	width;
	int	height;
	int	x;
	int	y;

	y = 0;
	x = 0;
	width = data->map->width_blocs * 60;
	height = data->map->height_blocs * 60;
	while (x < width - 200)
	{
		y = 0;
		while (y < height - 200)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->imgs->win_img, x, y);
			y = y + 100;
		}
		x = x + 100;
	}
}

void	moves_counter(t_objects *data)
{
	if (data->map->map[data->player->y_target][data->player->x_target] != 'E')
	{
		data->player->moves += 1;
		ft_printf(PEACH);
		ft_printf("number of moves: %d\n", data->player->moves);
		ft_printf(WHITE);
	}
}

void	player_almost_wins(t_objects *data)
{
	ft_printf(RED);
	ft_printf("You can NOT EXIT!, you have %d candies left!\n",
		data->map->collectible);
	ft_printf(WHITE);
}
