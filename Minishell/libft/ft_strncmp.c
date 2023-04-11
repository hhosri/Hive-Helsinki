/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:06:31 by corellan          #+#    #+#             */
/*   Updated: 2022/11/06 12:12:50 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *str1, char const *str2, size_t n)
{
	size_t	i;
	int		s1;
	int		s2;

	i = 0;
	while ((str1[i] == str2[i]) && (str1[i] != '\0') && (str2[i] != '\0') && \
			(i < (n - 1)))
	{
		i++;
	}
	s1 = (unsigned const char)str1[i];
	s2 = (unsigned const char)str2[i];
	if (n == 0)
		return (0);
	if (s1 == s2)
		return (0);
	else
		return (s1 - s2);
}
