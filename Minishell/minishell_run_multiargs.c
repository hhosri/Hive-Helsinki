/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run_multiargs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:59:47 by corellan          #+#    #+#             */
/*   Updated: 2023/04/11 08:35:30 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_run_m_comman_a(char **cmd, t_env *env, char *path, t_m_arg *ar)
{
	handle_shortcuts2(2);
	(ar->pid[ar->wait - 1]) = fork();
	if ((ar->pid[ar->wait - 1]) == -1)
	{
		handle_shortcuts2(1);
		perror("minishell");
		ft_free_split(cmd);
		return (3);
	}
	if ((ar->pid[ar->wait - 1]) == 0)
	{
		ft_child(path, cmd, &(*env), &(*ar));
		exit (EXIT_SUCCESS);
	}
	free(path);
	ft_free_split(cmd);
	return (3);
}

static int	run_mult_com(char **cmd, t_env *env, t_m_arg *arg)
{
	char	*path;
	int		flag;

	path = NULL;
	if (find_special_cases(cmd) == 0)
	{
		path = ft_find_path(cmd, &(*env), &flag);
		if (path == NULL)
			return (ft_print_error_command(cmd, &(*env), flag));
	}
	return (ft_run_m_comman_a(cmd, &(*env), path, &(*arg)));
}

static int	ft_handle_spe_cases(int *ret, t_env *env, t_m_arg *arg)
{
	arg->pid[arg->wait] = -1;
	arg->pid[(arg->wait) + 1] = 0;
	(arg->wait) += 1;
	if (arg->lex_size == arg->n_redir && arg->i == 0)
	{
		if (ft_strncmp("exit\0", (env->arr[0]), 5) == 0)
			return (ft_exit_check_m2(env->arr, &(*ret), &(*env)));
		if ((ft_strncmp("export\0", (env->arr[0]), 7) == 0))
			return (ft_export(&(*env), env->arr));
		if ((ft_strncmp("unset\0", (env->arr[0]), 6) == 0))
			return (ft_unset(&(*env), env->arr));
		if ((ft_strncmp("cd\0", (env->arr[0]), 3) == 0))
			return (ft_cd(env->arr, &(*env)));
	}
	return (-1);
}

static int	ft_proc_and_check_mul(char *ar, int *ret, t_env *env, t_m_arg *arg)
{
	env->arr = ft_custom_split(ar);
	env->arr = ft_process_arg(env->arr, ar);
	env->ret = (*ret);
	if (env->arr[0] != NULL)
	{
		if (ft_handle_spe_cases(&(*ret), &(*env), &(*arg)) != -1)
			return (3);
		return (run_mult_com(env->arr, &(*env), &(*arg)));
	}
	ft_free_split(env->arr);
	return (3);
}

int	ft_iterate_mult_args(char **ar, int *re, t_env *env, t_m_arg *arg)
{
	ft_do_redirections(ar, &(*arg), &(*env));
	if (arg->c_pipe < arg->n_pipe)
		arg->lexe = arg->lexe->next;
	if (arg->flag_err == 0)
		ft_proc_and_check_mul(ar[arg->i], &(*re), &(*env), &(*arg));
	if (arg->flag_in == 1)
		close(arg->fdin);
	if (arg->flag_out == 1)
		close(arg->fdout);
	arg->idx = 0;
	while (arg->idx < arg->n_redir)
	{
		(arg->idx)++;
		(arg->i)++;
	}
	(arg->i)++;
	arg->flag_pipe = 1;
	(arg->c_pipe)++;
	return (3);
}
