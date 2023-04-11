/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_process_args.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:13:14 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:54:29 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_work_in_arg_aux(char **array, int pos, int *j, char **str)
{
	int	flag;

	flag = 0;
	while ((*j) < pos)
	{
		if (flag == 0)
		{
			(*str) = ft_strdup(array[(*j)]);
			flag = 1;
		}
		else
			(*str) = ft_strjoin_free((*str), array[(*j)]);
		(*j)++;
	}
}

static char	*ft_work_in_arg(char **array, int pos, int *j)
{
	char		*str;

	if ((pos - (*j)) == 1)
	{
		str = ft_strdup(array[(*j)]);
		(*j) += 1;
		return (str);
	}
	else if (pos == (*j))
	{
		str = ft_strdup("");
		return (str);
	}
	else
		ft_work_in_arg_aux(array, pos, &(*j), &str);
	return (str);
}

static char	**ft_process_arg_aux(char **ar, char **tem, int len, t_args **arg)
{
	t_args	*args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	args = (*arg);
	while (i < len)
	{
		tem[i] = ft_work_in_arg(ar, args->pos, &j);
		if (args->next != NULL)
			args = args->next;
		i++;
	}
	args = (*arg);
	if (args != NULL)
		ft_free_list_args(&args);
	ft_free_split(ar);
	return (tem);
}

char	**ft_process_arg(char **array, char *str)
{
	t_args	*args;
	char	**temp;
	int		len;

	args = NULL;
	ft_wordcount_args(str, &args);
	len = ft_listsize_args(&args);
	temp = (char **)malloc(sizeof(char *) * (len + 1));
	if (temp == NULL)
		return (NULL);
	temp[len] = NULL;
	return (ft_process_arg_aux(array, temp, len, &args));
}
