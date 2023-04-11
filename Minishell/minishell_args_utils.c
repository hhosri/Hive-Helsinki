/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_args_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:23:24 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:50:22 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_s_quot_args(char const *str, int *i, int *j, t_args **ar)
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
		if (str[(*i)] == 32 || str[(*i)] == '\0')
			ft_add_to_list_args(&(*ar), (*j));
	}
	return (1);
}

static int	ft_check_d_quot_args(char const *str, int *i, int *j, t_args **ar)
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
		if (str[(*i)] == 32 || str[(*i)] == '\0')
			ft_add_to_list_args(&(*ar), (*j));
	}
	return (1);
}

static void	ft_increment_args_aux(const char *str, int *i, int *j, t_args **ar)
{
	if ((check_char_now(str, (*i)) == 1) && \
		(check_char_after(str, ((*i) + 1)) == 1))
	{
		(*j)++;
		if (str[(*i) + 1] == ' ' || str[(*i) + 1] == '\0')
			ft_add_to_list_args(&(*ar), (*j));
	}
	(*i)++;
}

static int	ft_incrementer_args(const char *str, int *i, int *j, t_args **ar)
{
	if ((str[(*i)] == 39 && str[(*i) + 1] == 39) || \
		(str[(*i)] == 34 && str[(*i) + 1] == 34))
	{
		(*i) += 2;
		if (str[(*i)] == 32 || str[(*i)] == '\0')
			ft_add_to_list_args(&(*ar), (*j));
		return (0);
	}
	else if ((str[(*i)] != 32 && str[(*i)] != 39 && str[(*i)] != 34) && \
		(str[(*i) + 1] == 32 || str[(*i) + 1] == 39 || str[(*i) + 1] == 34 || \
		str[(*i) + 1] == '\0'))
	{
		(*j)++;
		(*i)++;
		if (str[(*i)] == 32 || str[(*i)] == '\0')
			ft_add_to_list_args(&(*ar), (*j));
		return (0);
	}
	else
		ft_increment_args_aux(str, &(*i), &(*j), &(*ar));
	return (0);
}

size_t	ft_wordcount_args(char const *str, t_args **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\' && ((str[i + 1] == 39) || str[i + 1] == 34))
			i += 1;
		else if ((str[i] == 39) && \
			(ft_check_s_quot_args(str, &(i), &(j), &(*args)) == 1))
			continue ;
		else if ((str[(i)] == 34) && \
			(ft_check_d_quot_args(str, &(i), &(j), &(*args)) == 1))
			continue ;
		ft_incrementer_args(str, &i, &j, &(*args));
	}
	return (j);
}
