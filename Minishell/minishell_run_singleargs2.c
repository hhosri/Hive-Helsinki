/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run_singleargs2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:03:35 by corellan          #+#    #+#             */
/*   Updated: 2023/04/09 18:24:02 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setup_flag(int *flag, char **path, int i, char **array)
{
	if (array == NULL || array[0] == NULL)
	{
		(*flag) = 5;
		(*path) = NULL;
	}
	else if (i == ft_array_len(array))
	{
		(*flag) = 1;
		(*path) = NULL;
	}
}
