/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_args_lexer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:18:18 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 09:34:57 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_fill_list_lex_aux(char const *str, int i, int j, t_lexer **lex)
{
	if (str[i] == '<' && str[i + 1] == '>')
		ft_add_to_list_lexer(&(*lex), IN_OUT, j);
	else if (str[i] == '|' && str[i + 1] == '<')
	{
		ft_add_to_list_lexer(&(*lex), PIPE, j);
		ft_add_to_list_lexer(&(*lex), RE_IN, j);
	}
	else if (str[i] == '|' && str[i + 1] == '>')
	{
		ft_add_to_list_lexer(&(*lex), PIPE, j);
		ft_add_to_list_lexer(&(*lex), RE_OUT, j);
	}
	else if (str[i] == '>' && str[i + 1] != '>')
		ft_add_to_list_lexer(&(*lex), RE_OUT, j);
	else if (str[i] == '>' && str[i + 1] == '|')
		ft_add_to_list_lexer(&(*lex), RE_OUT, j);
	else if (str[i] == '<' && str[i + 1] != '<')
		ft_add_to_list_lexer(&(*lex), RE_IN, j);
	else if (str[i] == '>' && str[i + 1] == '>')
		ft_add_to_list_lexer(&(*lex), RERE_OUT, j);
	else if (str[i] == '<' && str[i + 1] == '<')
		ft_add_to_list_lexer(&(*lex), RERE_IN, j);
	else if (str[i] == '|' && str[i + 1] != '|')
		ft_add_to_list_lexer(&(*lex), PIPE, j);
}

static void	ft_fill_list_lexer(char const *str, int i, int j, t_lexer **lex)
{
	if (str[i] == '\0')
		return ;
	else if (str[i + 1] == '\0')
		ft_fill_list_lex_aux(str, i, j, &(*lex));
	else if (str[i] == '|' && str[i + 1] == '<' && str[i + 2] == '<')
	{
		ft_add_to_list_lexer(&(*lex), PIPE, j);
		ft_add_to_list_lexer(&(*lex), RERE_IN, j);
	}
	else if (str[i] == '|' && str[i + 1] == '>' && str[i + 2] == '>')
	{
		ft_add_to_list_lexer(&(*lex), PIPE, j);
		ft_add_to_list_lexer(&(*lex), RERE_OUT, j);
	}
	else
		ft_fill_list_lex_aux(str, i, j, &(*lex));
}

static void	ft_check_first_arg(char const *str, t_lexer **lex)
{
	if (str[0] == '\0')
		return ;
	if (str[0] == '<' && str[1] == '>')
		ft_add_to_list_lexer(&(*lex), IN_OUT, 0);
	else if (str[0] == '>' && str[1] != '>')
		ft_add_to_list_lexer(&(*lex), RE_OUT, 0);
	else if (str[0] == '<' && str[1] != '<')
		ft_add_to_list_lexer(&(*lex), RE_IN, 0);
	else if (str[0] == '>' && str[1] == '>')
		ft_add_to_list_lexer(&(*lex), RERE_OUT, 0);
	else if (str[0] == '<' && str[1] == '<')
		ft_add_to_list_lexer(&(*lex), RERE_IN, 0);
	else
		ft_add_to_list_lexer(&(*lex), NORM_START, 0);
}

static int	ft_check_dash_tok_lex(const char *str, t_lex_i *idx, t_lexer **le)
{
	if (str[idx->i] == '\\' && check_char(str, ((idx->i) + 1)) == 1)
	{
		(idx->i) += 1;
		if (check_char(str, ((idx->i) + 1)) == 1)
			(idx->j) += 1;
		(idx->i) += 1;
		if (idx->k != idx->j)
			ft_fill_list_lexer(str, idx->i, idx->j, &(*le));
		idx->k = idx->j;
		return (1);
	}
	return (0);
}

void	ft_tokens_recognition(char const *str, t_lexer **lex)
{
	t_lex_i	idx;

	idx.i = 0;
	idx.j = 0;
	idx.k = 0;
	ft_check_first_arg(str, &(*lex));
	while (str[idx.i] != '\0')
	{
		if (str[idx.i] == 39 && ft_check_s_quot_lexer(str, &(idx.i)) == 1)
			idx.i = (idx.i + 1 - 1);
		else if (str[idx.i] == 34 && ft_check_d_quot_lexer(str, &(idx.i)) == 1)
			idx.i = (idx.i + 1 - 1);
		else if (ft_check_dash_tok_lex(str, &idx, &(*lex)) == 1)
			continue ;
		if ((str[idx.i] == '\0') || (check_char(str, idx.i) == 0 && \
			(check_char(str, (idx.i + 1)) == 1 || str[idx.i + 1] == '\0')))
			(idx.j)++;
		if (str[idx.i] != '\0')
			(idx.i)++;
		if (idx.k != idx.j)
			ft_fill_list_lexer(str, idx.i, idx.j, &(*lex));
		idx.k = idx.j;
	}
}
