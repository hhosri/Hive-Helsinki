/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:28:30 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/26 11:29:24 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	init_draw_stripe(t_data *data)
{
	data->tdata->offs = (float)data->tdata->tex->img_height \
	/ (float)data->tdata->height;
	data->tdata->tex_xi = data->tdata->tex_x;
	data->tdata->tex_yi = 0;
}

void	draw_stripe_helper(t_data *data)
{
	data->rays->ry = data->tdata->wall_top;
	data->tdata->tex_xi = (int) data->tdata->tex_x;
	data->tdata->mod_ofs = 0;
}
