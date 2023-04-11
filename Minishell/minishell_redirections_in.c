/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_redirections_in.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:14:43 by corellan          #+#    #+#             */
/*   Updated: 2023/04/10 14:43:59 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_process_rein(t_m_arg *arg)
{
	if (arg->flag_in == 1)
		dup2(arg->fdin, STDIN_FILENO);
	else if (arg->flag_pipe == 1 && arg->flag_in == 0)
		dup2(arg->fd[(arg->c_pipe) - 1][0], STDIN_FILENO);
}

void	ft_reredirect_input(char **ar, t_m_arg *arg)
{
	int	fd[RE_OUT];

	if (arg->lexe->token == 3 && arg->flag_err == 0)
	{
		if (arg->flag_in == 1)
			close(arg->fdin);
		if (pipe(fd) == -1)
		{
			arg->flag_err = 1;
			perror("minishell");
			return ;
		}
		write(fd[1], ar[(arg->i) + arg->idx + 1], \
			ft_strlen(ar[(arg->i) + arg->idx + 1]));
		close(fd[1]);
		arg->fdin = fd[0];
		arg->flag_in = 1;
	}
}

void	ft_redirections_input(char **ar, t_m_arg *arg, t_env *env)
{
	char	**temp;

	temp = NULL;
	if (arg->lexe->token == 1 && arg->flag_err == 0)
	{
		if (arg->flag_in == 1)
			close(arg->fdin);
		temp = ft_custom_split(ar[(arg->i) + arg->idx + 1]);
		temp = ft_process_arg(temp, ar[(arg->i) + 1 + arg->idx]);
		arg->fdin = open(temp[0], O_RDONLY);
		if (arg->fdin == -1 && arg->flag_err == 0)
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
		arg->flag_in = 1;
	}
}
