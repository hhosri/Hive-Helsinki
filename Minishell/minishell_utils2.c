/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:03:55 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 17:00:16 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_len_s_quot_spe(char const *s, int i)
{
	int	k;
	int	init;

	init = i;
	k = (i + 1);
	while (s[k] != 39 && s[k] != '\0')
		k++;
	if (s[k] == '\0')
		return (1);
	return (k - init);
}

static int	ft_len_d_quot_spe(char const *s, int i)
{
	int	k;
	int	init;

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
	return (k - init);
}

int	ft_strlen_w_space(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		if (str[i] == 39)
			i += ft_len_s_quot_spe(str, i);
		else if (str[i] == 34)
			i += ft_len_d_quot_spe(str, i);
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (i);
}

int	wordcount_spac_spe(char const *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 39)
			i += ft_len_s_quot_spe(str, i);
		else if (str[i] == 34)
			i += ft_len_d_quot_spe(str, i);
		if (str[i] == '\0')
		{
			j++;
			break ;
		}
		if ((str[i] != ' ') && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}
