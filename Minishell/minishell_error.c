/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:59:58 by corellan          #+#    #+#             */
/*   Updated: 2023/04/10 12:54:06 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_inside(char c, t_env *env)
{
	if (c == '\'' && !env->is_inside_q)
		env->is_inside_q = 1;
	else if (c == '\'' && env->is_inside_q)
		env->is_inside_q = 0;
	if (c == '"' && !env->is_inside_dq)
		env->is_inside_dq = 1;
	else if (c == '"' && env->is_inside_dq)
		env->is_inside_dq = 0;
	if (env->is_inside_q == 1 || env->is_inside_dq == 1)
		return (1);
	else
		return (0);
}

static int	first_or_both(char *st)
{
	if (st[0] == '|' && st[1] != '|')
		return (1);
	else if (st[0] == '|' && st[1] == '|')
		return (2);
	return (0);
}

static int	more_than_two(char *st, t_env *env)
{
	int	i;

	i = 0;
	while (st[i])
	{
		if (st[i] == 39)
			i += (int)ft_len_s_quot_lexer(st, i);
		else if (st[i] == 34)
			i += (int)ft_len_d_quot_lexer(st, i);
		else if (ft_strlen_out(st + i) == 3)
			return (3);
		else if (ft_strlen_out(st + i) > 3)
			return (4);
		else if (ft_strlen_pipe(st + i) == 2)
			return (5);
		else if (ft_strlen_pipe(st + i) == 3)
			return (6);
		else if (ft_strlen_pipe(st + i) > 3)
			return (7);
		else
			i++;
	}
	env->fl_mtt = 1;
	return (0);
}

static int	check_errors_helper(char *st, int i, int inside, t_env *env)
{
	env->fl_mtt = 0;
	while (st[i])
	{
		inside = is_inside(st[i], env);
		if (st[i] == '\\' && st[i + 1])
			i++;
		else if ((env->fl_mtt == 0) && (more_than_two(st, &(*env))))
			return (ft_error_more_than_two(more_than_two(st, &(*env))));
		else if (first_or_both(st) != 0)
			return (ft_error_pipe(first_or_both(st)));
		else if (((ft_strlen_in(st) > 2) && (!inside)) || \
			((st[i] == '&' && st[i + 1] == '&') && (!inside)))
			return (ft_error_unsupported());
		else if ((st[i] == '>' && st[i + 1] == '<') && (!inside))
			return (ft_error_redir(1, st, i));
		else if ((st[ft_strlen(st) - 1] == '<' || st[ft_strlen(st) - 1] == '>'))
			return (ft_error_redir(2, st, i));
		else if ((st[i] == '|' && !st[i + 1]) || (st[i] == '\\' && !st[i + 1]))
			return (ft_error_unsupported());
		i++;
	}
	return (0);
}

int	catch_errors(char *st, t_env *env)
{	
	int	i;
	int	inside;

	i = 0;
	inside = 0;
	env->is_inside_q = 0;
	env->is_inside_dq = 0;
	return (check_errors_helper(st, i, inside, env));
}
