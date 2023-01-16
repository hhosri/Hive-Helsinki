/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:14:43 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/02 17:25:48 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_x(t_stack **stack_x)
{
	t_stack	*last_node;
	t_stack	*temp;

	if (!*stack_x || !((*stack_x)->next))
		return ;
	else
	{
		last_node = ft_lstlast_stack(*stack_x);
		temp = (*stack_x)->next;
		last_node->next = *stack_x;
		(*stack_x)->next = NULL;
		*stack_x = temp;
	}
}

void	ft_rotate_a(t_stack **stack_a)
{
	int		last_position;
	t_stack	*first_node;

	last_position = ft_lstsize_stack(*stack_a);
	(*stack_a)->position = last_position;
	ft_rotate_x(stack_a);
	first_node = *stack_a;
	while ((first_node->position <= last_position) && first_node->next != NULL)
	{
		first_node->position = (first_node->position) - 1;
		first_node = first_node->next;
	}
	ft_printf("ra\n");
}

void	ft_rotate_b(t_stack **stack_b)
{
	int		last_position;
	t_stack	*first_node;

	last_position = ft_lstsize_stack(*stack_b);
	(*stack_b)->position = last_position;
	ft_rotate_x(stack_b);
	first_node = *stack_b;
	while ((first_node->position <= last_position) && first_node->next != NULL)
	{
		first_node->position = (first_node->position) - 1;
		first_node = first_node->next;
	}
	ft_printf("rb\n");
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_x(stack_a);
	ft_rotate_x(stack_b);
	ft_printf("rr\n");
}
