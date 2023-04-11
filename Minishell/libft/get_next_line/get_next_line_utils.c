/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:40:47 by corellan          #+#    #+#             */
/*   Updated: 2022/12/19 16:49:13 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_detect_index(int fd, t_colector *sample)
{
	int	i;

	i = 0;
	if (fd == 0)
		return (i);
	else
	{
		if (sample[0].fds == 0)
			i++;
		while (sample[i].fds != 0 && i < MAX_FILES)
		{
			if (sample[i].fds == fd)
				return (i);
			i++;
		}
		sample[i].fds = fd;
		return (i);
	}
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	unsigned int		a;
	unsigned int		b;
	unsigned int		i;
	char				*dest;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = 0;
	dest = (char *)malloc(sizeof(char) * ((a + b) + 1));
	if (dest == NULL)
		return (NULL);
	while (i < (a + b))
	{
		if (i < a)
			dest[i] = s1[i];
		else
			dest[i] = s2[i - a];
		i++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}
