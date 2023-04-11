/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:08:42 by corellan          #+#    #+#             */
/*   Updated: 2023/04/10 17:23:12 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_start(char **environ)
{
	pid_t		pid;
	char		**str;

	str = ft_split("clear", ' ');
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
		execve("/usr/bin/clear", str, environ);
	else
	{
		wait(NULL);
		ft_free_split(str);
		printf("Welcome to minishell. Developed by corellan and hel-hosr. ");
		printf("Hive Helsinki. 2023.\n");
	}
	return (0);
}

static int	ft_setup_everything(int ac, char **av, char **envp, t_env *env)
{
	disable_characters(0);
	ac = 0;
	env->exit_stts = 0;
	if (av[ac] != NULL)
		ac = 0;
	env->flag = 0;
	env->set_f = 0;
	ft_copy_env(&(*env), envp);
	if (ft_start(env->env) == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	char	*str;
	int		ret;
	t_env	env;

	if (ft_setup_everything(ac, av, envp, &env) == 1)
		return (1);
	while (1)
	{
		handle_shortcuts();
		str = readline("minishell$ ");
		env.str = &str;
		ac = ft_line_checker(str, &(ret), &env);
		if (ac == 0)
			return (0);
		else if (ac == 1)
			return (ret);
		else if (ac == 2)
			return (255);
		else if (ac == 3)
		{
			free(env.new_str);
			free(str);
		}
	}
	return (0);
}
