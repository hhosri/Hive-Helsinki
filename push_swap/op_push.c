/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:10:13 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/02 17:25:17 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	re_position_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_a_temp;
	t_stack	*stack_b_temp;
	int		i;

	stack_a_temp = *stack_a;
	stack_b_temp = *stack_b;
	i = 1;
	while (stack_a_temp)
	{
		stack_a_temp->position = i;
		stack_a_temp = stack_a_temp->next;
		i++;
	}
	i = 1;
	while (stack_b_temp)
	{
		stack_b_temp->position = i;
		stack_b_temp = stack_b_temp->next;
		i++;
	}
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	else
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_a = *stack_b;
		*stack_b = temp;
	}
	ft_printf("pa\n");
	re_position_stacks(stack_a, stack_b);
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	else
	{	
		temp = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = temp;
	}
	ft_printf("pb\n");
	re_position_stacks(stack_a, stack_b);
}
