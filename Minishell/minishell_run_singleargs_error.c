/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run_singleargs_error.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:21:46 by corellan          #+#    #+#             */
/*   Updated: 2023/04/10 14:53:10 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error_cmd_aux2(char **cmd, t_env *env, int flag)
{
	if (flag == 5)
	{
		write(STDERR_FILENO, "minishell: ", 11);
		write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, strerror(2), ft_strlen(strerror(2)));
		write(STDERR_FILENO, "\n", 1);
		env->exit_stts = 127;
		return (3);
	}
	return (3);
}

static int	ft_print_error_command_aux(char **cmd, t_env *env, int flag)
{
	if (flag == 3)
	{
		write(STDERR_FILENO, "minishell: ", 11);
		write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
		write(STDERR_FILENO, "\n", 1);
		if (errno == 2)
			env->exit_stts = 127;
		else
			env->exit_stts = 126;
		return (3);
	}
	else if (flag == 4)
	{
		write(STDERR_FILENO, "minishell: ", 11);
		write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
		write(STDERR_FILENO, ": Permission denied\n", 20);
		ft_free_split(cmd);
		env->exit_stts = 126;
		return (3);
	}
	return (error_cmd_aux2(cmd, &(*env), flag));
}

int	ft_print_error_command(char **cmd, t_env *env, int flag)
{
	if (flag == 1)
	{
		write(STDERR_FILENO, "minishell: ", 11);
		write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
		write(STDERR_FILENO, ": command not found\n", 20);
		ft_free_split(cmd);
		env->exit_stts = 127;
		return (3);
	}
	else if (flag == 2)
	{
		write(STDERR_FILENO, "minishell: ", 11);
		write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
		write(STDERR_FILENO, ": is a directory\n", 17);
		ft_free_split(cmd);
		env->exit_stts = 126;
		return (3);
	}
	else
		return (ft_print_error_command_aux(cmd, &(*env), flag));
}
