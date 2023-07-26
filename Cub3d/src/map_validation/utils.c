/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:54:51 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/03 11:38:58 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	init_settings(t_map *map)
{
	map->is_c = 0;
	map->is_f = 0;
	map->is_ea = 0;
	map->is_no = 0;
	map->is_so = 0;
	map->is_we = 0;
	map->player_num = 0;
}
