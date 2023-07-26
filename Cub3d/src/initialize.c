/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:42:14 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/26 11:32:39 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	init_player(t_player *player)
{
	player->pos_x = 0;
	player->pos_y = 0;
	player->pa = 0;
	player->pdx = 0;
	player->pdy = 0;
	player->x_start = 0;
	player->y_start = 0;
	player->color = 0xFFFFFF;
}

void	init_raycaster(t_rays *rays)
{
	rays->r = 0;
	rays->curx = 0;
	rays->cury = 0;
	rays->mp = 0;
	rays->mx = 0;
	rays->my = 0;
	rays->dof = 0;
	rays->rx = 0;
	rays->ry = 0;
	rays->ra = 0;
	rays->xo = 0;
	rays->yo = 0;
	rays->hx = 0;
	rays->hy = 0;
	rays->vx = 0;
	rays->vy = 0;
}

t_keys	*init_keys(void)
{
	t_keys	*keys;

	keys = malloc(sizeof(t_keys));
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
	return (keys);
}

void	init_textures(t_data *data)
{
	data->east.img_height = 0;
	data->east.img_width = 0;
	data->east.text_data = NULL;
	data->west.img_height = 0;
	data->west.img_width = 0;
	data->west.text_data = NULL;
	data->north.img_height = 0;
	data->north.img_width = 0;
	data->north.text_data = NULL;
	data->south.img_height = 0;
	data->south.img_width = 0;
	data->south.text_data = NULL;
}

void	init_data(t_data *data)
{
	t_image		*image;
	t_player	*player;
	t_rays		*rayc;
	t_texdata	*tdata;

	image = malloc(sizeof(t_image));
	player = malloc(sizeof(t_player));
	rayc = malloc(sizeof(t_rays));
	tdata = malloc(sizeof(t_texdata));
	init_textures(data);
	init_player(player);
	init_raycaster(rayc);
	data->keys = init_keys();
	data->image = image;
	data->player = player;
	data->rays = rayc;
	data->map->wall_color = 0xFF8080;
	tdata->tex = NULL;
	tdata->x = 0;
	data->tdata = tdata;
}
