/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_collect_args.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:35:50 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/06 16:13:47 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_vars(t_env *env, int i, char *st)
{
	char	*var_name;
	char	*var_value;
	int		last_idx;
	int		var_len;

	var_len = 0;
	last_idx = 0;
	last_idx = i;
	last_idx = separator_char(st, last_idx);
	var_len = last_idx - i + 1;
	var_name = malloc((sizeof(char) * var_len) + 1);
	ft_strlcpy(var_name, (st + i), var_len);
	var_value = is_var_available(var_name, env);
	if (var_value)
		replace_var_val(env, var_value, var_len);
	else if (st[i++] == '?')
		handle_exlamation(env, st, i);
	else
		env->new_str = ft_strjoin_free(env->new_str, "");
	i = last_idx;
	free(var_name);
	return (i);
}

static int	single_dollar(t_env *env)
{
	env->new_str = ft_strjoin_c(env->new_str, '$');
	return (1);
}

static int	in_or_out(char *st, int i, t_env *env)
{
	if (st[i] == '\'' && !env->is_inside)
		env->is_inside = 1;
	else if (st[i] == '\'' && env->is_inside)
		env->is_inside = 0;
	return (1);
}

static int	helper(t_env *env, int i, char *st)
{
	if (st[i] == '$' && !env->is_inside)
		i = handle_vars(env, (i + 1), st);
	else if (st[i] == '$' && env->is_inside && env->is_inside_2
		&& single_inside_double(st, i))
		i = handle_vars(env, (i + 1), st);
	else
	{
		env->new_str = ft_strjoin_c(env->new_str, st[i]);
		i++;
	}
	return (i);
}

void	collect_args(char *st, t_env *env)
{
	int		i;

	i = 0;
	env->is_inside = 0;
	env->is_inside_2 = 0;
	while (st[i])
	{
		if (st[i] == '\\' && st[i + 1] == '\'' && env->is_inside == 0)
			i += 2;
		else if (st[i] == '\'')
		{
			env->new_str = ft_strjoin_c(env->new_str, st[i]);
			i += in_or_out(st, i, env);
		}
		else if (st[i] == '"')
		{
			env->new_str = ft_strjoin_c(env->new_str, st[i]);
			i += in_or_out_2(st, i, env);
		}
		else if (st[i] == '$' && (st[i + 1] == ' ' || st[i + 1] == '\0'))
			i += single_dollar(env);
		else
			i = helper(env, i, st);
	}
}
