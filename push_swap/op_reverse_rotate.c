/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:49:27 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/02 17:25:28 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_x(t_stack **stack_x)
{
	t_stack	*last_node;
	t_stack	*before_last_node;

	if (!*stack_x || !((*stack_x)->next))
		return ;
	else
	{
		last_node = ft_lstlast_stack(*stack_x);
		before_last_node = ft_lst_before_last_stack(*stack_x);
		last_node->next = *stack_x;
		before_last_node->next = NULL;
		*stack_x = last_node;
	}
}

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*first_node;

	first_node = *stack_a;
	while (first_node)
	{
		first_node->position = (first_node->position) + 1;
		first_node = first_node->next;
	}
	ft_reverse_rotate_x(stack_a);
	(*stack_a)->position = 1;
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*first_node;

	first_node = *stack_b;
	while (first_node)
	{
		first_node->position = (first_node->position) + 1;
		first_node = first_node->next;
	}
	ft_reverse_rotate_x(stack_b);
	(*stack_b)->position = 1;
	ft_printf("rrb\n");
}

void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate_x(stack_a);
	ft_reverse_rotate_x(stack_b);
	ft_printf("rrr\n");
}
