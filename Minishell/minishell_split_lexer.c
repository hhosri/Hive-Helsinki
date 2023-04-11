/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_split_lexer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:01:50 by corellan          #+#    #+#             */
/*   Updated: 2023/04/04 18:11:44 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_count_char(char const *str)
{
	size_t	i;

	i = 0;
	while (check_char(str, i) == 1)
		i++;
	return (i);
}

static size_t	ft_strlen_char(char const *str, t_sp_arg *li)
{
	size_t	i;

	i = 0;
	li->q = 0;
	while (str[i] != '\0' && check_char(str, i) == 0)
	{
		if (str[i] == 39)
			i += ft_len_s_quot_lexer(str, i);
		else if (str[i] == 34)
			i += ft_len_d_quot_lexer(str, i);
		else if (str[i] == '\\' && check_char(str, (i + 1)) == 1)
		{
			i += 2;
			li->q += 1;
		}
		else
			i++;
	}
	return (i - li->q);
}

static size_t	ft_wordcount(char const *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 39 && ft_check_s_quot_lexer(str, &(i)) == 1)
			i = (i + 1 - 1);
		else if (str[i] == 34 && ft_check_d_quot_lexer(str, &(i)) == 1)
			i = (i + 1 - 1);
		else if (ft_check_dash_split_lexer(str, &(i), &(j)) == 1)
			continue ;
		if ((str[i] == '\0') || (check_char(str, i) == 0 && \
			(check_char(str, (i + 1)) == 1 || str[i + 1] == '\0')))
		{
			j++;
			if (str[i] == '\0')
				break ;
		}
		i++;
	}
	return ((size_t)j);
}

size_t	ft_strlcpy_lexer(char *d, char const *s, size_t size, t_sp_arg *li)
{
	li->i = 0;
	li->j = 0;
	li->len = ft_strlen(s);
	if (size == 0)
		return (li->len);
	else
	{
		while ((li->i < (size - 1)) && s[li->i] != '\0')
		{
			if (s[li->i] == 39 && ft_copy_s_qu_lex(&d, s, &(*li), size) == 0)
				continue ;
			else if (s[li->i] == 34 && \
				ft_copy_d_qu_lex(&d, s, &(*li), size) == 0)
				continue ;
			if ((s[li->i] == '\\' && (check_char(s, (li->i + 1)) == 1)))
				(li->i)++;
			d[li->j] = s[li->i];
			(li->i)++;
			(li->j)++;
		}
		d[li->j] = '\0';
	}
	return (li->len);
}

char	**ft_split_lexer(char const *s)
{
	char		**array;
	size_t		i;
	size_t		character;
	size_t		store;
	t_sp_arg	li;

	i = ft_wordcount(s);
	store = ft_count_char(s);
	array = (char **)malloc(sizeof(char *) * (i + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < ft_wordcount(s))
	{
		li.temp = ft_strlen_char((s + store), &li);
		character = ft_count_char((s + store + li.temp + li.q));
		array[i] = (char *)malloc(sizeof(char) * (li.temp + 1));
		if (array[i] == NULL)
			return (ft_custom_split_free(array, i));
		ft_strlcpy_lexer(array[i], (s + store), (li.temp + li.q + 1), &li);
		store = store + (li.temp + character + li.q);
		i++;
	}
	array[i] = NULL;
	return (array);
}
