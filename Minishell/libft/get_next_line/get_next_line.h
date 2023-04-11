/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:00:18 by corellan          #+#    #+#             */
/*   Updated: 2022/12/30 17:18:40 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define MAX_FILES 200

# include "../libft.h"

typedef struct s_struct
{
	int		flag;
	int		n_position;

}t_struct;

typedef struct s_colector
{
	char	*stack;
	int		fds;

}t_colector;

char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char const *s2);
int		ft_detect_index(int fd, t_colector *sample);

#endif
