/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_split_arg_utils2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:38:45 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:57:43 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlcpy_arg(char *d, char const *s, size_t size, t_sp_arg *sp)
{
	sp->i = 0;
	sp->j = 0;
	sp->len = ft_strlen(s);
	if (size == 0)
		return (sp->len);
	else
	{
		while ((sp->i < (size - 1)) && s[sp->i] != '\0')
		{
			if (sp->t == 2 && s[sp->i] == '\\' && (s[sp->i + 1] == 34))
				(sp->i)++;
			else if (sp->t == 0 && s[sp->i] == '\\' && (s[sp->i + 1] != 124 || \
				s[sp->i + 1] != 60 || s[sp->i + 1] != 62 || \
				s[sp->i + 1] != '\0'))
				(sp->i)++;
			d[sp->j] = s[sp->i];
			(sp->i)++;
			(sp->j)++;
		}
		d[sp->j] = '\0';
	}
	return (sp->len);
}

char	**ft_custom_split_free(char **array, size_t i)
{
	while (i > 0)
	{
		free(array[i--]);
		array[i] = NULL;
	}
	free(array);
	return (NULL);
}

int	check_char_now(const char *str, int i)
{
	if (str[i] == 39 || str[i] == 34)
		return (1);
	else
		return (0);
}

int	check_char_after(const char *str, int i)
{
	if (str[i] == 39 || str[i] == 34 || str[i] == 32 || str[i] == 0)
		return (1);
	else
		return (0);
}
