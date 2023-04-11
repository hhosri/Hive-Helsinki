/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run_singleargs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:59:47 by corellan          #+#    #+#             */
/*   Updated: 2023/04/11 08:39:53 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_ex_analyzer(int *flag, char **cmd)
{
	char	*path;
	int		fd;

	path = NULL;
	fd = open(cmd[0], O_RDONLY);
	if (fd == -1)
		(*flag) = 3;
	else if (access(cmd[0], F_OK) == 0 && access(cmd[0], X_OK) == -1)
	{
		(*flag) = 4;
		close(fd);
	}
	return (path);
}

static char	*ft_find_path_aux(char **cmd, t_env *env, int *flag, char **array)
{
	char	*path;
	int		i;

	path = NULL;
	array = NULL;
	i = ft_find_word_array(env->env, "PATH=");
	if (i < ft_array_len(env->env))
		array = ft_split(env->env[i] + 5, ':');
	i = 0;
	while (array != NULL && array[i] != NULL)
	{
		path = ft_strjoin(array[i], "/");
		path = ft_strjoin_free(path, cmd[0]);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		i++;
	}
	ft_setup_flag(&(*flag), &path, i, array);
	if (array != NULL)
		ft_free_split(array);
	return (path);
}

char	*ft_find_path(char **cmd, t_env *env, int *flag)
{
	char	*path;
	char	**array;
	char	pwd[BUFFER];

	path = NULL;
	array = NULL;
	getcwd(pwd, sizeof(pwd));
	if (access(cmd[0], X_OK) == 0)
	{
		if (chdir(cmd[0]) == 0)
		{
			chdir(pwd);
			(*flag) = 2;
			return (path);
		}
		path = ft_strdup(cmd[0]);
		return (path);
	}
	else if (ft_strnstr(cmd[0], "./", ft_strlen(cmd[0])))
		return (ft_ex_analyzer(&(*flag), cmd));
	return (ft_find_path_aux(cmd, &(*env), &(*flag), &(*array)));
}

static int	ft_run_s_command_aux(char **cmd, t_env *env, char *path, pid_t pid)
{
	handle_shortcuts2(2);
	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		ft_free_split(cmd);
		return (3);
	}
	if (pid == 0)
	{
		handle_shortcuts2(1);
		ft_child_s(path, cmd, &(*env));
		exit (EXIT_SUCCESS);
	}
	else
		waitpid(pid, &(env->status), 0);
	free(path);
	ft_free_split(cmd);
	if (WIFSIGNALED(env->status) == 0)
		env->exit_stts = WEXITSTATUS(env->status);
	else
		print_exit_stts(&(*env));
	disable_characters(0);
	return (3);
}

int	ft_run_single_command(char **cmd, t_env *env)
{
	pid_t	pid;
	char	*path;
	int		flag;

	pid = 1;
	path = ft_find_path(cmd, &(*env), &flag);
	if (path == NULL)
		return (ft_print_error_command(cmd, &(*env), flag));
	return (ft_run_s_command_aux(cmd, &(*env), path, pid));
}
