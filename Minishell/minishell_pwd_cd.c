/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pwd_cd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:10:18 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/05 16:54:56 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_env_update_oldpwd(t_env *env, char **array, int i)
{
	if (env->set_f == 1)
	{
		env->set_f = 0;
		env->oldpwd[0] = '\0';
	}
	if (env->flag == 2)
	{
		i = ft_find_word_array(env->env, "OLDPWD=");
		array = ft_split(env->env[i], '=');
		if (array == NULL)
			return ;
		free(env->env[i]);
		array[0] = ft_strjoin_free(array[0], "=");
		env->env[i] = ft_strjoin(array[0], env->oldpwd);
		ft_free_split(array);
	}
	else if (env->flag == 1)
	{
		i = ft_find_word_array(env->env, "OLDPWD");
		env->env[i] = ft_strjoin_free(env->env[i], "=");
		env->env[i] = ft_strjoin_free(env->env[i], env->oldpwd);
		env->flag = 2;
	}
}

static void	ft_env_update(t_env *env)
{
	char	**array;
	int		i;

	array = NULL;
	i = ft_find_word_array(env->env, "PWD=");
	if (i < ft_array_len(env->env))
	{
		array = ft_split(env->env[i], '=');
		if (array == NULL)
			return ;
		free(env->env[i]);
		array[0] = ft_strjoin_free(array[0], "=");
		env->env[i] = ft_strjoin(array[0], env->newpwd);
		ft_free_split(array);
	}
	else
		env->set_f = 1;
	if (ft_find_word_array(env->env, "OLDPWD=") < ft_array_len(env->env))
	{
		env->flag = 2;
		ft_env_update_oldpwd(&(*env), array, i);
	}
	else if (ft_find_word_array(env->env, "OLDPWD") < ft_array_len(env->env))
		ft_env_update_oldpwd(&(*env), array, i);
}

int	ft_pwd(t_env *env)
{
	char	path[BUFFER];

	if (getcwd(path, sizeof(path)))
	{
		printf("%s\n", path);
		env->exit_stts = 0;
	}
	else
	{
		perror("minishell");
		env->exit_stts = 1;
	}
	return (3);
}

static int	ft_find_home_path(char ***path, t_env *env, int *i)
{
	if ((*i) != 1)
		return (0);
	(*i) = 0;
	(*i) = ft_find_word_array((env->env), "HOME=");
	if (env->env[(*i)] != NULL)
	{
		ft_free_split((*path));
		(*path) = ft_split(env->env[(*i)], '=');
		if ((*path) == NULL)
			return (1);
	}
	else
	{
		write(STDERR_FILENO, "minishell: cd: ", 15);
		write(STDERR_FILENO, "HOME not set\n", 13);
		env->exit_stts = 1;
		return (1);
	}
	return (0);
}

int	ft_cd(char **path, t_env *env)
{
	int	i;

	i = 0;
	env->exit_stts = 0;
	getcwd(env->oldpwd, sizeof(env->oldpwd));
	i = ft_array_len(path);
	if (i == 1 && ft_find_home_path(&path, &(*env), &i) == 1)
		return (3);
	if (chdir(path[1]) == 0)
	{
		getcwd(env->newpwd, sizeof(env->newpwd));
		ft_env_update(&(*env));
	}
	else
	{
		env->exit_stts = 1;
		write(STDERR_FILENO, "minishell: cd: ", 15);
		write(STDERR_FILENO, path[1], ft_strlen(path[1]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
		write(STDERR_FILENO, "\n", 1);
	}
	ft_free_split(path);
	return (3);
}
