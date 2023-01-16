/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:13:16 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/09 11:59:52 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast_stack(t_stack *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_stack(t_stack *first, t_stack *new_list)
{
	t_stack	*node;

	if (!first)
	{
		first = new_list;
		return ;
	}
	node = ft_lstlast_stack(first);
	node->next = new_list;
}

t_stack	*ft_create_node_stack(int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->number = content;
	node->next = NULL;
	node->index = 0;
	node->position = -1;
	node->target_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->cost_a_type = 0;
	node->cost_b_type = 0;
	node->full_cost = 0;
	return (node);
}

t_stack	*ft_lst_before_last_stack(t_stack *lst)
{
	while (lst)
	{
		if (lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize_stack(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
