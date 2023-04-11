/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_redirections_out.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:17:03 by corellan          #+#    #+#             */
/*   Updated: 2023/04/10 14:46:23 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_process_reout(t_m_arg *arg)
{
	if (arg->flag_out == 1)
		dup2(arg->fdout, STDOUT_FILENO);
	else if ((arg->flag_out == 0) && (arg->c_pipe < (arg->n_pipe)))
		dup2(arg->fd[arg->c_pipe][1], STDOUT_FILENO);
}

void	ft_redirect_out_append(char **ar, t_m_arg *arg, t_env *env)
{
	char	**temp;

	temp = NULL;
	if (arg->lexe->token == 4 && arg->flag_err == 0)
	{
		if (arg->flag_out == 1)
			close(arg->fdout);
		temp = ft_custom_split(ar[(arg->i) + arg->idx + 1]);
		temp = ft_process_arg(temp, ar[(arg->i) + 1 + arg->idx]);
		arg->fdout = open(temp[0], O_RDWR | O_CREAT | O_APPEND, 0644);
		if (arg->fdout == -1 && arg->flag_err == 0)
		{
			arg->flag_err = 1;
			write(STDERR_FILENO, "minishell: ", 11);
			write(STDERR_FILENO, temp[0], ft_strlen(temp[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
			write(STDERR_FILENO, "\n", 1);
			env->exit_stts = 1;
		}
		ft_free_split(temp);
		arg->flag_out = 1;
	}
}

void	ft_redirections_output(char **ar, t_m_arg *arg, t_env *env)
{
	char	**temp;

	temp = NULL;
	if (arg->lexe->token == 2 && arg->flag_err == 0)
	{
		if (arg->flag_out == 1)
			close(arg->fdout);
		temp = ft_custom_split(ar[(arg->i) + arg->idx + 1]);
		temp = ft_process_arg(temp, ar[(arg->i) + 1 + arg->idx]);
		arg->fdout = open(temp[0], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (arg->fdout == -1 && arg->flag_err == 0)
		{
			arg->flag_err = 1;
			write(STDERR_FILENO, "minishell: ", 11);
			write(STDERR_FILENO, temp[0], ft_strlen(temp[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
			write(STDERR_FILENO, "\n", 1);
			env->exit_stts = 1;
		}
		ft_free_split(temp);
		arg->flag_out = 1;
	}
}
