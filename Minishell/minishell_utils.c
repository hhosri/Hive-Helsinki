/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:48:36 by corellan          #+#    #+#             */
/*   Updated: 2023/04/06 17:53:31 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

int	ft_find_word_array(char **array, char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = ft_array_len(array);
	if (array == NULL)
		return (0);
	while ((i < j) && (ft_strncmp(needle, array[i], ft_strlen(needle)) != 0))
		i++;
	return (i);
}

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (0);
	while (array[i] != NULL)
		i++;
	return (i);
}

int	ft_check_symbols(char const *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '|') || (str[i] == '<') || (str[i] == '>'))
			j++;
		i++;
	}
	return (j);
}

int	ft_wordcount_space(char const *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ') && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}
