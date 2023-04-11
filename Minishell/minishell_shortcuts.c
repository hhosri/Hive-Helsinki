/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_shortcuts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:26:40 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/11 08:57:21 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_n(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
}

void	handle_shortcuts2(int flag)
{
	if (flag == 1)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
	}
	else if (flag == 2)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGINT, &print_n);
	}
}

int	handle_ctrl_d(char *str, t_env *env)
{
	printf("\033[1A");
	printf("\033[11C");
	printf("exit\n");
	free(str);
	ft_free_split(env->env);
	free(env->new_str);
	return (0);
}

static void	sigint_func(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 1);
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_on_new_line();
	}
}

void	handle_shortcuts(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_func);
}
