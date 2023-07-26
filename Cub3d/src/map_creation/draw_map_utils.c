/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:44:14 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/26 11:30:46 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	slen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	init_hor_ray_data(t_data *data)
{
	data->rays->dof = 0;
	data->rays->dis_h = 100000000;
	data->rays->hx = data->player->pos_x;
	data->rays->hy = data->player->pos_y;
	data->rays->a_tan = -1 / tan(data->rays->ra);
}

void	init_ver_ray_data(t_data *data)
{
	data->rays->dof = 0;
	data->rays->dis_v = 100000000;
	data->rays->vx = data->player->pos_x;
	data->rays->vy = data->player->pos_y;
	data->rays->n_tan = -tan(data->rays->ra);
}
