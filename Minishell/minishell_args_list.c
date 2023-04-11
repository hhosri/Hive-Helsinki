/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_args_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:06:30 by corellan          #+#    #+#             */
/*   Updated: 2023/04/05 16:49:55 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_list_args(t_args **lst)
{
	t_args	*temp;
	t_args	*temp2;

	temp2 = (*lst)->next;
	temp = (*lst);
	while (temp->next != NULL)
	{
		free(temp);
		temp = temp2;
		temp2 = temp2->next;
	}
	free(temp);
}

static t_args	*ft_listnew_args(int content)
{
	t_args	*new;

	new = (t_args *)malloc(sizeof(t_args));
	if (new == NULL)
		return (NULL);
	new->pos = content;
	new->next = NULL;
	return (new);
}

void	ft_add_to_list_args(t_args **begin, int num)
{
	t_args	*new;
	t_args	*iter;

	iter = *begin;
	new = ft_listnew_args(num);
	if (*begin == NULL)
		*begin = new;
	else
	{
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = new;
	}
}

int	ft_listsize_args(t_args **lst)
{
	int		i;
	t_args	*temp;

	i = 0;
	temp = *lst;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_print_list_args(t_args **a)
{
	t_args	*temp;

	temp = *a;
	while (temp != NULL)
	{
		ft_printf("%d -> ", temp->pos);
		temp = temp->next;
	}
	ft_printf("\n");
}
