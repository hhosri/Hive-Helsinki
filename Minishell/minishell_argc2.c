/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_argc2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:19:28 by corellan          #+#    #+#             */
/*   Updated: 2023/04/11 10:31:17 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_stts_helper(t_env *env)
{
	if (WTERMSIG(env->status) == 10)
	{
		write(STDERR_FILENO, "Bus error: 10\n", 14);
		env->exit_stts = 138;
	}
	else if (WTERMSIG(env->status) == SIGINT)
		env->exit_stts = 130;
}

void	print_exit_stts(t_env *env)
{
	if (WTERMSIG(env->status) == 11)
	{
		write(STDERR_FILENO, "Segmentation fault: 11\n", 23);
		env->exit_stts = 139;
	}
	else if (WTERMSIG(env->status) == 3)
	{
		write(STDERR_FILENO, "Quit: 3\n", 8);
		env->exit_stts = 131;
	}
	else if (WTERMSIG(env->status) == 9)
	{
		write(STDERR_FILENO, "Killed: 9\n", 10);
		env->exit_stts = 137;
	}
	else if (WTERMSIG(env->status) == 6)
	{
		write(STDERR_FILENO, "Abort trap: 6\n", 14);
		env->exit_stts = 134;
	}
	exit_stts_helper(&(*env));
}

int	check_here_doc(char ***arr, t_lexer **lex, t_env *env)
{
	t_lexer	*temp;
	int		i;

	temp = (*lex);
	i = 1;
	if (temp->token == 0)
		temp = temp->next;
	while (((*arr)[i] != NULL) && (temp != NULL))
	{
		if (temp->token == 3)
			here_doc(&((*arr)[i]), &(*env));
		if (g_should_process == 0)
			break ;
		i++;
		temp = temp->next;
	}
	if (g_should_process == 0)
	{
		g_should_process = 1;
		ft_free_split(*(arr));
		ft_free_list_lexer(&(*lex));
		return (1);
	}
	return (0);
}
