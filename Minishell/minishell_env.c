/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:14:47 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:51:28 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_update_shlvl(int i, t_env *env)
{
	char	**array;
	char	*number;
	int		level;

	if (i == ft_array_len(env->env))
	{
		ft_add_variables(&(*env), "SHLVL");
		i = ft_find_word_array(env->env, "SHLVL");
		env->env[i] = ft_strjoin_free(env->env[i], "=");
		env->env[i] = ft_strjoin_free(env->env[i], "0");
	}
	array = ft_split(env->env[i], '=');
	if (array == NULL)
		return ;
	level = ft_atoi(array[1]);
	number = ft_itoa(level + 1);
	free(env->env[i]);
	array[0] = ft_strjoin_free(array[0], "=");
	env->env[i] = ft_strjoin(array[0], number);
	free(number);
	ft_free_split(array);
}

static void	ft_copy_env_aux(t_env *env, int i)
{
	if (env->flag == 0)
	{
		ft_add_variables(&(*env), "OLDPWD");
		env->flag = 1;
	}
	if (ft_find_word_array(env->env, "PWD") == ft_array_len(env->env))
	{
		getcwd(env->newpwd, sizeof(env->newpwd));
		ft_add_variables(&(*env), "PWD");
		i = ft_find_word_array(env->env, "PWD");
		env->env[i] = ft_strjoin_free(env->env[i], "=");
		env->env[i] = ft_strjoin_free(env->env[i], env->newpwd);
	}
	i = ft_find_word_array(env->env, "SHLVL=");
	ft_update_shlvl(i, &(*env));
}

void	ft_copy_env(t_env *env, char **envp)
{
	int	i;

	i = ft_array_len(envp);
	env->env = (char **)malloc(sizeof(char *) * (i + 1));
	if (env->env == NULL)
		exit(1);
	env->env[i] = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("OLDPWD=", envp[i], 7) == 0)
		{
			env->env[i] = ft_strdup("OLDPWD");
			env->flag = 1;
		}
		else
			env->env[i] = ft_strdup(envp[i]);
		i++;
	}
	i = 0;
	ft_copy_env_aux(&(*env), i);
}

static int	ft_print_env_error(char **array, t_env *env)
{
	env->exit_stts = 127;
	write(STDERR_FILENO, "env: ", 5);
	write(STDERR_FILENO, array[1], ft_strlen(array[1]));
	write(STDERR_FILENO, ": No such file or directory\n", 28);
	ft_free_split(array);
	return (3);
}

int	ft_env(t_env *env, char **array)
{
	int	i;

	i = ft_array_len(array);
	env->exit_stts = 0;
	if (i > 1)
		return (ft_print_env_error(array, &(*env)));
	while (env->env[i] != NULL)
	{
		if (ft_strchr(env->env[i], '=') != NULL)
		{
			if (ft_strncmp("_=", env->env[i], 2) == 0)
				printf("_=/usr/bin/env\n");
			else
				printf("%s\n", env->env[i]);
		}
		i++;
	}
	ft_free_split(array);
	return (3);
}
