/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:33:50 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/14 14:00:35 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	skip_white_and_fill(char **path, int setting_name_len, char *str)
{
	str += setting_name_len;
	while (*str == ' ' || *str == '\t')
		str++;
	*path = ft_strdup(str);
}

void	fill_color_xmp_paths(t_map *map)
{
	int		i;
	char	*str;

	i = 0;
	while (i <= 5)
	{
		str = map->all_2d[i];
		if (ft_strncmp("NO", map->all_2d[i], 2) == 0)
			skip_white_and_fill(&map->no_path, 2, str);
		else if (ft_strncmp("SO", map->all_2d[i], 2) == 0)
			skip_white_and_fill(&map->so_path, 2, str);
		else if (ft_strncmp("EA", map->all_2d[i], 2) == 0)
			skip_white_and_fill(&map->ea_path, 2, str);
		else if (ft_strncmp("WE", map->all_2d[i], 2) == 0)
			skip_white_and_fill(&map->we_path, 2, str);
		else if (ft_strncmp("C", map->all_2d[i], 1) == 0)
			skip_white_and_fill(&map->c_path, 1, str);
		else if (ft_strncmp("F", map->all_2d[i], 1) == 0)
			skip_white_and_fill(&map->f_path, 1, str);
		i++;
	}
}
