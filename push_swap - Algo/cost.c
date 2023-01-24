/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:04:49 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/06 17:25:04 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_cost_b(t_stack *stack_b, int position, t_stack *node_b)
{
	int	last_pos;
	int	cost;

	cost = 0;
	last_pos = ft_lstsize_stack(stack_b);
	if (position <= last_pos / 2)
	{
		cost = position - 1;
		node_b->cost_b_type = 1;
	}
	else
	{
		cost = last_pos - position + 1;
		node_b->cost_b_type = -1;
	}
	return (cost + 1);
}

static int	get_cost_a(t_stack *stack_a, int target_pos, t_stack *node_b)
{
	int	last_pos;
	int	cost;

	cost = 0;
	last_pos = ft_lstsize_stack(stack_a);
	if (target_pos <= last_pos / 2)
	{
		cost = target_pos - 1;
		node_b->cost_a_type = 1;
	}
	else
	{
		cost = last_pos - target_pos + 1;
		node_b->cost_a_type = -1;
	}
	return (cost);
}

void	get_cost_full(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*node_b;
	t_stack	*node_a;

	node_a = stack_a;
	node_b = stack_b;
	while (node_b)
	{
		node_b->cost_b = get_cost_b(stack_b, node_b->position, node_b);
		node_b->cost_a = get_cost_a(stack_a, node_b->target_pos, node_b);
		node_b->full_cost = node_b->cost_a + node_b->cost_b;
		node_b = node_b->next;
	}
}
