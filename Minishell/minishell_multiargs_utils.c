/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_multiargs_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:42:11 by corellan          #+#    #+#             */
/*   Updated: 2023/04/08 20:45:17 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_special_cases(char **cmd)
{
	if (ft_strncmp("exit\0", (cmd[0]), 5) == 0)
		return (1);
	else if (ft_strncmp("echo\0", (cmd[0]), 5) == 0)
		return (1);
	else if ((ft_strncmp("pwd\0", (cmd[0]), 4) == 0))
		return (1);
	else if ((ft_strncmp("cd\0", (cmd[0]), 3) == 0))
		return (1);
	if ((ft_strncmp("env\0", (cmd[0]), 4) == 0))
		return (1);
	else if ((ft_strncmp("export\0", (cmd[0]), 7) == 0))
		return (1);
	else if ((ft_strncmp("unset\0", (cmd[0]), 6) == 0))
		return (1);
	return (0);
}
