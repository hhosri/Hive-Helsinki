/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:51:48 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/13 13:15:12 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(char const *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
			counter++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == c)
			i++;
	}
	return (counter);
}

static char	*malloc_substring_error(char **arr, int index)
{
	while (index >= 0)
	{
		free(arr[index]);
		index--;
	}
	free(arr);
	return (NULL);
}

static char	*ft_substring_creator(char const *s, char c, char **arr, int index)
{
	char	*sub_str;
	int		i;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	sub_str = (char *)malloc(sizeof(*sub_str) * (len + 1));
	if (!sub_str)
		return (malloc_substring_error(arr, index));
	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		s++;
	while (s[i] && s[i] != c)
	{
		sub_str[i] = s[i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	arr = (char **)malloc(sizeof(*arr) * (ft_word_counter(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			arr[i] = ft_substring_creator(s, c, arr, i);
			if (!arr[i])
				return (NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
