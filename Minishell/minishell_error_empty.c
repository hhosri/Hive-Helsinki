/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error_empty.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:29:01 by corellan          #+#    #+#             */
/*   Updated: 2023/04/08 13:58:06 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error_middle(int token, char **arr, char **tempo)
{
	write(STDERR_FILENO, "minishell: syntax error near unexpected ", 40);
	write(STDERR_FILENO, "token `", 7);
	if (token == 5)
		write(STDERR_FILENO, "|'\n", 3);
	else if (token == 1)
		write(STDERR_FILENO, "<'\n", 3);
	else if (token == 2)
		write(STDERR_FILENO, ">'\n", 3);
	else if (token == 3)
		write(STDERR_FILENO, "<<'\n", 4);
	else if (token == 4)
		write(STDERR_FILENO, ">>'\n", 4);
	else if (token == 6)
		write(STDERR_FILENO, "<>'\n", 4);
	ft_free_split(arr);
	ft_free_split(tempo);
	return ;
}

static int	catch_except(t_lexer **lex)
{
	t_lexer	*temp;

	temp = (*lex);
	if ((temp->next != NULL) && ((temp->token == 5) && \
		((temp->next->token > 0 && temp->next->token < 5) || \
		(temp->next->token == 6))))
		return (1);
	return (0);
}

static int	catch_empty_aux(char **arr, t_lexer **lex, char *st)
{
	int		i;
	char	**tempo;
	t_lexer	*temp;

	temp = (*lex);
	tempo = ft_split_lexer(st);
	tempo = ft_process_lexer(tempo, st);
	if (temp->token == 0)
		temp = temp->next;
	i = 1;
	while (tempo[i] != NULL && temp != NULL)
	{
		if ((catch_except(&temp) == 0) && \
			(ft_count_space(tempo[i]) == (int)ft_strlen(tempo[i])))
		{
			temp = temp->next;
			print_error_middle(temp->token, arr, tempo);
			ft_free_list_lexer(&(*lex));
			return (1);
		}
		i++;
		temp = temp->next;
	}
	ft_free_split(tempo);
	return (0);
}

static void	print_error_last(int token)
{
	if (token == 5)
	{
		write(STDERR_FILENO, "\nNOT SUPPORTED.\n", 16);
		write(STDERR_FILENO, "Please upgrade to premium version.\n\n", 36);
		return ;
	}
	write(STDERR_FILENO, "minishell: syntax error near unexpected ", 40);
	write(STDERR_FILENO, "token `", 7);
	write(STDERR_FILENO, "newline'\n", 9);
}

int	catch_empty(char **arr, t_lexer **lex, char *st)
{
	int		i;
	t_lexer	*temp;

	i = ft_array_len(arr);
	temp = (*lex);
	if ((i >= 2) && (ft_count_space(arr[i - 1]) == (int)ft_strlen(arr[i - 1])))
	{
		print_error_last(ft_lexlast(&temp)->token);
		ft_free_split(arr);
		ft_free_list_lexer(&(*lex));
		return (1);
	}
	return (catch_empty_aux(arr, &(*lex), st));
}
