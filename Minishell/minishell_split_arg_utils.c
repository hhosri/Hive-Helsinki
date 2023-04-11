/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_split_arg_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:01:50 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:57:34 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_single_quot(char const *str, int *i, int *j)
{
	int	k;

	k = ((*i) + 1);
	if (str[k] == 39)
		return (0);
	while (str[k] != 39 && str[k] != '\0')
		k++;
	if (str[k] == '\0')
		return (0);
	else
	{
		(*i) = (k + 1);
		(*j) += 1;
	}
	return (1);
}

int	ft_check_double_quot(char const *str, int *i, int *j)
{
	int	k;

	k = ((*i) + 1);
	if (str[k] == 34)
		return (0);
	while (str[k] != 34 && str[k] != '\0')
	{
		if (str[k] == '\\' && str[k + 1] == 34)
			k++;
		k++;
	}
	if (str[k] == '\0')
		return (0);
	else
	{
		(*i) = (k + 1);
		(*j) += 1;
	}
	return (1);
}

size_t	ft_len_single_quot(char const *s, size_t *st, t_sp_arg *sp)
{
	size_t	k;

	k = 1;
	while (s[k] != 39 && s[k] != '\0')
		k++;
	if (s[k] == '\0')
	{
		sp->p = 0;
		return (1);
	}
	else
	{
		k -= 1;
		(*st) += 1;
		sp->p = 1;
		sp->t = 1;
	}
	return (k);
}

size_t	ft_len_double_quot(char const *s, size_t *st, t_sp_arg *sp)
{
	size_t	k;

	k = 1;
	while (s[k] != 34 && s[k] != '\0')
	{
		if (s[k] == '\\' && s[k + 1] == 34)
		{
			k += 1;
			sp->q += 1;
		}
		k++;
	}
	if (s[k] == '\0')
	{
		sp->p = 0;
		return (1);
	}
	else
	{
		sp->p = 1;
		k -= 1;
		(*st) += 1;
		sp->t = 2;
	}
	return (k);
}

size_t	ft_count_char_arg(char const *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (i);
	if (str[i + 1] == '\0')
	{
		while (str[i] == 32)
			i++;
	}
	else
	{
		while (str[i] == 32 || (str[i] == 39 && str[i + 1] == 39) || \
		(str[i] == 34 && str[i + 1] == 34))
		{
			if (str[i] == 39 && str[i + 1] == 39)
				i += 2;
			else if (str[i] == 34 && str[i + 1] == 34)
				i += 2;
			else
				i++;
		}
	}
	return (i);
}
