/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_collect_args_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:53:38 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/10 16:41:15 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	in_or_out_2(char *st, int i, t_env *env)
{
	if (st[i] == '"' && !env->is_inside_2)
		env->is_inside_2 = 1;
	else if (st[i] == '"' && env->is_inside_2)
		env->is_inside_2 = 0;
	return (1);
}

int	single_inside_double(char *st, int i)
{
	while (st[i])
	{
		if (st[i] == '\'')
			return (1);
		else if (st[i] == '"')
			return (0);
		i++;
	}
	return (0);
}

int	separator_char(char *st, int last_idx)
{
	while (st[last_idx] != ' ' && st[last_idx] != '\'' && st[last_idx] != '\0'
		&& st[last_idx] != '$' && st[last_idx] != '\"' && st[last_idx] != ','
		&& st[last_idx] != '.' && st[last_idx] != '<' && st[last_idx] != '>'
		&& st[last_idx] != '/' && st[last_idx] != ':' && st[last_idx] != '@'
		&& st[last_idx] != '#' && st[last_idx] != '%' && st[last_idx] != '^'
		&& st[last_idx] != '*' && st[last_idx] != '-' && st[last_idx] != '+'
		&& st[last_idx] != '=' && st[last_idx] != '\n')
		last_idx++;
	return (last_idx);
}
