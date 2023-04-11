/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:08:36 by corellan          #+#    #+#             */
/*   Updated: 2022/11/06 17:08:01 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtrim_aux(void)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * 2);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, "", 2);
	return (dest);
}

static char	*ft_strtrim_back(char const *s1, char const *set, int i, int lenset)
{
	int	len;

	len = ft_strlen(s1);
	while (len > 0 && lenset > 0)
	{
		while ((lenset > 0) && (s1[len - 1] != set[lenset - 1]))
			lenset--;
		if (lenset > 0)
		{
			lenset = ft_strlen(set);
			len--;
		}
	}
	return (ft_substr(s1, i, (len - i)));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		lenset;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	lenset = ft_strlen(set);
	while (s1[i] != '\0' && j < lenset)
	{
		while (set[j] != s1[i] && set[j] != '\0')
			j++;
		if (j < lenset)
		{
			j = 0;
			i++;
		}
	}
	if (i >= (int)ft_strlen(s1))
		return (ft_strtrim_aux());
	return (ft_strtrim_back(s1, set, i, lenset));
}
