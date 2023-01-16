/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:22:02 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/06 17:27:43 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	look_for_smallest(t_stack *stack_a)
{
	int		smallest;
	t_stack	*smallest_ptr;

	smallest = stack_a->index;
	smallest_ptr = stack_a;
	while (stack_a)
	{
		if (stack_a->index < smallest)
		{
			smallest = stack_a->index;
			smallest_ptr = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (smallest_ptr->position);
}

static int	look_for_closest_bigger(t_stack *stack_a, int index)
{
	int		i;
	int		target;
	t_stack	*node;

	i = 1;
	node = stack_a;
	while (1)
	{
		while (node)
		{
			if (node->index == index + i)
			{
				target = node->index;
				return (node->position);
			}
			else
				node = node->next;
		}
		node = stack_a;
		i++;
	}
}

static int	is_any_bigger(t_stack *stack_a, int index)
{
	while (stack_a)
	{
		if (stack_a->index > index)
			return (1);
		else
			stack_a = stack_a->next;
	}
	return (0);
}

void	find_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*node_b;
	t_stack	*node_a;

	node_b = stack_b;
	node_a = stack_a;
	while (node_b)
	{
		if (is_any_bigger(node_a, node_b->index) == 1)
			node_b->target_pos = look_for_closest_bigger(node_a, node_b->index);
		else
			node_b->target_pos = look_for_smallest(node_a);
		node_b = node_b->next;
	}		
}
