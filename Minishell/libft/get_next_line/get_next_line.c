/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:39:24 by corellan          #+#    #+#             */
/*   Updated: 2022/12/16 11:23:53 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_line_check(char *stack, int *a, int *b)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(stack);
	i = 0;
	while (stack[i] != '\0' && stack[i] != '\n')
		i++;
	if (i < len)
	{
		*a = 0;
		*b = i;
	}
	else
	{
		*a = 1;
		*b = 0;
	}
}

static char	*ft_trim_stack(char *stack, char *line, t_struct col)
{
	size_t	len;
	char	*stackcopy;

	len = ft_strlen(stack);
	stackcopy = NULL;
	stackcopy = (char *)malloc(sizeof(char) * (len + 1));
	if (stackcopy == NULL)
		return (NULL);
	ft_line_check(stack, &col.flag, &col.n_position);
	if (col.flag == 1)
	{
		ft_strlcpy(stackcopy, (ft_strchr(stack, '\0')), (len + 1));
		ft_strlcpy(stack, stackcopy, (len + 1));
	}
	else
	{
		ft_strlcpy(stackcopy, (ft_strchr(stack, '\n') + 1), (len + 1));
		ft_strlcpy(stack, stackcopy, (len + 1));
	}
	free(stackcopy);
	return (line);
}

static char	*ft_write_line(char *stack, t_struct col)
{
	char	*line;
	size_t	len;

	ft_line_check(stack, &col.flag, &col.n_position);
	if (col.flag == 1)
		len = ft_strlen(stack);
	else
		len = col.n_position;
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, stack, (len + 2));
	return (line);
}

static char	*ft_read_line(int fd, char *stack, char *buf, t_struct col)
{
	int		ret;

	ret = 1;
	if (stack == 0)
	{
		stack = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		stack[0] = '\0';
	}
	while (col.flag > 0 && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			col.flag = 0;
		else
		{
			buf[ret] = '\0';
			stack = ft_strjoin_free(stack, buf);
			ft_line_check(stack, &col.flag, &col.n_position);
		}
	}
	free(buf);
	return (stack);
}

char	*get_next_line(int fd)
{
	static t_colector	sample[MAX_FILES];
	char				*line;
	char				*buf;
	t_struct			col;
	int					index;

	col.flag = 1;
	col.n_position = 0;
	line = NULL;
	index = ft_detect_index(fd, sample);
	if (BUFFER_SIZE < 0 || fd == -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	sample[index].stack = ft_read_line(fd, sample[index].stack, buf, col);
	if (sample[index].stack[0] == '\0')
	{
		free(sample[index].stack);
		sample[index].stack = NULL;
		return (NULL);
	}
	line = ft_write_line(sample[index].stack, col);
	return (ft_trim_stack(sample[index].stack, line, col));
}
