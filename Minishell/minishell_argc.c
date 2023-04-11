/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_argc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:35:02 by corellan          #+#    #+#             */
/*   Updated: 2023/04/11 08:40:43 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_process_single_cmd(char *st, int *ret, t_env *env)
{
	char	**array;

	collect_args(st, &(*env));
	array = ft_custom_split(env->new_str);
	array = ft_process_arg(array, env->new_str);
	if (array[0] != NULL)
	{
		if (ft_strncmp("exit\0", (array[0]), 5) == 0)
			return (ft_exit_check(array, st, &(*ret), &(*env)));
		if (ft_strncmp("echo\0", (array[0]), 5) == 0)
			return (ft_echo(array, env));
		if ((ft_strncmp("pwd\0", (array[0]), 4) == 0))
			return (ft_pwd(env));
		if ((ft_strncmp("cd\0", (array[0]), 3) == 0))
			return (ft_cd(array, &(*env)));
		if ((ft_strncmp("env\0", (array[0]), 4) == 0))
			return (ft_env(&(*env), array));
		if ((ft_strncmp("export\0", (array[0]), 7) == 0))
			return (ft_export(&(*env), array));
		if ((ft_strncmp("unset\0", (array[0]), 6) == 0))
			return (ft_unset(&(*env), array));
		return (ft_run_single_command(array, &(*env)));
	}
	ft_free_split(array);
	return (3);
}

static void	wait_for_p_close(char **ar, t_m_arg *arg, t_lexer **be, t_env *env)
{
	arg->i = 0;
	close_pipes(&(*arg));
	while ((arg->wait) > 0 && arg->pid[arg->i] != 0)
	{
		if (arg->pid[(arg->i) + 1] == 0)
		{
			waitpid(arg->pid[((arg->i))], &(env->status), 0);
			if (WIFSIGNALED(env->status) == 0 && arg->pid[arg->i] != -1)
				env->exit_stts = WEXITSTATUS(env->status);
			else
				print_exit_stts(&(*env));
		}
		else
			waitpid(arg->pid[((arg->i))], &(env->status), 0);
		(arg->i) += 1;
	}
	ft_free_split(ar);
	arg->lexe = (*be);
	ft_free_list_lexer(&(arg->lexe));
	disable_characters(0);
}

static int	ft_process_multi_cmd(char **ar, int *ret, t_env *env, t_lexer **le)
{
	t_m_arg	arg;

	arg.lexe = (*le);
	arg.begin = (*le);
	if (arg.lexe->token == 0)
		arg.lexe = arg.lexe->next;
	arg.i = 0;
	arg.wait = 0;
	arg.len = ft_array_len(ar);
	arg.n_pipe = count_pipes(&(*le));
	arg.c_pipe = 0;
	arg.flag_pipe = 0;
	if (prepare_pipe_fd(&(arg.fd), &(arg)) == -1)
		return (3);
	while (arg.c_pipe < arg.n_pipe)
	{
		if (create_pipes(&(arg.fd), &(arg.c_pipe), &(*le), ar) == -1)
			return (3);
	}
	arg.c_pipe = 0;
	while (ar[arg.i] != NULL)
		ft_iterate_mult_args(ar, &(*ret), &(*env), &arg);
	wait_for_p_close(ar, &arg, &(*le), &(*env));
	ft_free_pipes(&(arg.fd));
	return (3);
}

static int	ft_replace_dol_multi(char **ar, int *ret, t_env *env, t_lexer **le)
{
	int	i;

	i = 0;
	disable_characters(1);
	g_should_process = 1;
	ar = ft_process_lexer(ar, (*(env->str)));
	if (check_here_doc(&ar, &(*le), &(*env)) == 1)
		return (3);
	while (ar[i] != NULL)
	{
		if (i >= 1)
			env->new_str = ft_strdup("");
		collect_args(ar[i], &(*env));
		free(ar[i]);
		ar[i] = ft_strdup(env->new_str);
		i++;
		if (ar[i] != NULL)
			free(env->new_str);
	}
	env->c_arg = &ar;
	return (ft_process_multi_cmd(ar, &(*ret), &(*env), &(*le)));
}

int	ft_line_checker(char *st, int *ret, t_env *env)
{
	t_lexer	*lex;

	lex = NULL;
	env->args = NULL;
	env->new_str = ft_strdup("");
	if (st != NULL && ft_strlen(st) > 0)
		add_history(st);
	if (st == (void *)0)
		return (handle_ctrl_d(st, env));
	if (catch_errors(st, env) == 1)
		return (3);
	ft_tokens_recognition(st, &lex);
	if (lex != NULL && size_lex(&lex) == 1 && lex->token == 0)
	{
		ft_free_list_lexer(&lex);
		return (ft_process_single_cmd(st, &(*ret), &(*env)));
	}
	else if (lex != NULL)
	{
		env->args = ft_split_lexer(st);
		if (catch_empty(env->args, &lex, st) == 1)
			return (3);
		return (ft_replace_dol_multi(env->args, &(*ret), &(*env), &lex));
	}
	return (3);
}
