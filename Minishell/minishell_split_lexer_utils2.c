/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_split_lexer_utils2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:51:03 by corellan          #+#    #+#             */
/*   Updated: 2023/04/04 17:33:56 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_copy_d_qu_lex(char **d, const char *s, t_sp_arg *li, size_t si)
{
	size_t	k;

	k = (li->i + 1);
	while (s[k] != 34 && s[k] != '\0')
	{
		if (s[k] == '\\' && s[k + 1] == 34)
			k++;
		k++;
	}
	if (s[k] == '\0')
		return (1);
	(*d)[li->j] = s[li->i];
	li->i += 1;
	li->j += 1;
	while ((li->i < (si - 1)) && (s[li->i] != 34))
	{
		(*d)[li->j] = s[li->i];
		(li->j) += 1;
		(li->i) += 1;
	}
	(*d)[li->j] = 34;
	(li->j) += 1;
	(li->i) += 1;
	return (0);
}

int	ft_copy_s_qu_lex(char **d, const char *s, t_sp_arg *li, size_t si)
{
	size_t	k;

	k = (li->i + 1);
	while (s[k] != 39 && s[k] != '\0')
		k++;
	if (s[k] == '\0')
		return (1);
	(*d)[li->j] = s[li->i];
	li->i += 1;
	li->j += 1;
	while ((li->i < (si - 1)) && (s[li->i] != 39))
	{
		(*d)[li->j] = s[li->i];
		(li->j) += 1;
		(li->i) += 1;
	}
	(*d)[li->j] = 39;
	(li->j) += 1;
	(li->i) += 1;
	return (0);
}

int	ft_check_dash_split_lexer(const char *str, int *i, int *j)
{
	if (str[(*i)] == '\\' && check_char(str, ((*i) + 1)) == 1)
	{
		(*i) += 1;
		if (check_char(str, ((*i) + 1)) == 1)
			(*j) += 1;
		(*i) += 1;
		return (1);
	}
	return (0);
}
