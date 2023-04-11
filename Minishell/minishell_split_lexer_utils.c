/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_split_lexer_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:51:03 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:58:11 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_char(const char *str, int i)
{
	if (str[i] == '>' || str[i] == '<' || str[i] == '|')
		return (1);
	else
		return (0);
}

int	ft_check_s_quot_lexer(char const *str, int *i)
{
	int	k;

	k = ((*i) + 1);
	while (str[k] != 39 && str[k] != '\0')
		k++;
	if (str[k] == '\0')
		return (0);
	else
		(*i) = (k);
	return (1);
}

int	ft_check_d_quot_lexer(char const *str, int *i)
{
	int	k;

	k = ((*i) + 1);
	while (str[k] != 34 && str[k] != '\0')
	{
		if (str[k] == '\\' && str[k + 1] == 34)
			k++;
		k++;
	}
	if (str[k] == '\0')
		return (0);
	else
		(*i) = (k);
	return (1);
}

size_t	ft_len_s_quot_lexer(char const *s, int i)
{
	size_t	k;
	int		init;

	init = i;
	k = (i + 1);
	while (s[k] != 39 && s[k] != '\0')
		k++;
	if (s[k] == '\0')
		return (1);
	k = k + 1;
	return (k - (size_t)init);
}

size_t	ft_len_d_quot_lexer(char const *s, int i)
{
	size_t	k;
	int		init;

	init = i;
	k = (i + 1);
	while (s[k] != 34 && s[k] != '\0')
	{
		if (s[k] == '\\' && s[k + 1] == 34)
			k++;
		k++;
	}
	if (s[k] == '\0')
		return (1);
	k = k + 1;
	return (k - (size_t)init);
}
