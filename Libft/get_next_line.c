/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:33:00 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/11/23 11:56:24 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_get_last_line(char **str, char **line)
{
	*line = ft_strdup(*str);
	free(*str);
	*str = NULL;
}

static void	ft_get_line(char **str, char **line)
{
	int		nl_pos;
	char	*old_str;

	nl_pos = 0;
	old_str = *str;
	while ((*str)[nl_pos] != '\n')
		nl_pos++;
	*line = ft_substr(*str, 0, nl_pos + 1);
	*str = ft_strdup(*str + (nl_pos + 1));
	free(old_str);
}

static int	ft_reading(int fd, char **buff, char **str, char **line)
{
	int		rd;
	char	*old_str;

	rd = 1;
	while (!(ft_strchr(*str, '\n')) && rd)
	{
		rd = read(fd, *buff, BUFFER_SIZE);
		(*buff)[rd] = '\0';
		old_str = *str;
		*str = ft_strjoin(*str, *buff);
		free(old_str);
	}
	free(*buff);
	if (ft_strchr(*str, '\n'))
		ft_get_line(str, line);
	else
		ft_get_last_line(str, line);
	return (rd);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str;
	char		*line;
	int			reading_status;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(*buff) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (read(fd, buff, 0) < 0)
	{
		free(buff);
		return (NULL);
	}
	if (!str)
		str = ft_strdup("\0");
	reading_status = ft_reading(fd, &buff, &str, &line);
	if (reading_status == 0 && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
