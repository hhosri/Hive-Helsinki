/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:39:12 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/06 18:37:55 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_b(t_stack **stack_b, int cost_b, t_stack **cheapest_node)
{
	if ((*cheapest_node)->cost_b_type == 1)
	{
		while (cost_b > 1)
		{
			ft_rotate_b(stack_b);
			cost_b--;
		}
	}
	else if ((*cheapest_node)->cost_b_type == -1)
	{
		while (cost_b > 1)
		{
			ft_reverse_rotate_b(stack_b);
			cost_b--;
		}
	}
}

static void	move_a(t_stack **stack_a, t_stack **stack_b,
	int cost_a, t_stack **cheapest_node)
{
	if ((*cheapest_node)->cost_a_type == 1)
	{
		while (cost_a > 0)
		{
			ft_rotate_a(stack_a);
			cost_a--;
		}
	}
	else if ((*cheapest_node)->cost_a_type == -1)
	{
		while (cost_a > 0)
		{
			ft_reverse_rotate_a(stack_a);
			cost_a--;
		}
	}
	ft_push_a(stack_a, stack_b);
}

static void	optimized_move(t_stack **stack_a, t_stack **stack_b,
	int cost, int cost_type)
{
	if (cost_type == 1)
	{
		while (cost > 0)
		{
			ft_rotate_ab(stack_a, stack_b);
			cost--;
		}
	}
	else if (cost_type == -1)
	{
		while (cost > 0)
		{
			ft_reverse_rotate_ab(stack_a, stack_b);
			cost--;
		}
	}
	ft_push_a(stack_a, stack_b);
}

void	do_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_b;
	int		cheapest;
	t_stack	*cheapest_node;

	cheapest_node = *stack_b;
	node_b = *stack_b;
	cheapest = INT_MAX;
	while (node_b)
	{
		if (node_b->full_cost < cheapest)
		{
			cheapest = node_b->full_cost;
			cheapest_node = node_b;
		}
		node_b = node_b->next;
	}
	if (cheapest_node->cost_a == (cheapest_node->cost_b) - 1
		&& cheapest_node->cost_a_type == cheapest_node->cost_b_type)
		optimized_move(stack_a, stack_b, cheapest_node->cost_a,
			cheapest_node->cost_a_type);
	else
	{
		move_b(stack_b, cheapest_node->cost_b, &cheapest_node);
		move_a(stack_a, stack_b, cheapest_node->cost_a, &cheapest_node);
	}
}
