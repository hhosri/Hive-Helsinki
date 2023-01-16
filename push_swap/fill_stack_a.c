/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:01:52 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/06 16:08:20 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexing_stack(t_stack *stack_a, int stack_size)
{
	t_stack	*node;
	t_stack	*highest;
	int		number;

	while (--stack_size > 0)
	{
		node = stack_a;
		number = INT_MIN;
		highest = NULL;
		while (node)
		{
			if (node->number == INT_MIN && node->index == 0)
				node->index = 0;
			if (node->number > number && node->index == 0)
			{
				number = node->number;
				highest = node;
				node = stack_a;
			}
			else
				node = node->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

t_stack	*ft_fill_stack_a(int position, char **input)
{
	int		i;
	t_stack	*first_node;
	t_stack	*node;
	int		stack_position;

	stack_position = 1;
	i = position;
	first_node = ft_create_node_stack(ft_atoi(input[i]));
	first_node->position = stack_position;
	stack_position++;
	i++;
	while (input[i])
	{
		node = ft_create_node_stack(ft_atoi(input[i]));
		node->position = stack_position;
		ft_lstadd_back_stack(first_node, node);
		stack_position++;
		i++;
	}
	return (first_node);
}
