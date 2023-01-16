/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:27:26 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/05 14:38:20 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_any_position(t_stack *stack_a, int num)
{
	while (stack_a)
	{
		if (stack_a->number == num)
			return (stack_a->position);
		else
			stack_a = stack_a->next;
	}
	return (0);
}

void	push_any_totop_a(t_stack **stack_b, int num)
{
	int	num_position;
	int	list_len;

	num_position = find_any_position(*stack_b, num);
	list_len = ft_lstsize_stack(*stack_b);
	while ((*stack_b)->number != num)
	{	
		if (num_position <= list_len / 2)
			ft_rotate_a(stack_b);
		else
			ft_reverse_rotate_a(stack_b);
	}
}

void	push_any_totop_b(t_stack **stack_b, int num)
{
	int	num_position;
	int	list_len;

	num_position = find_any_position(*stack_b, num);
	list_len = ft_lstsize_stack(*stack_b);
	while ((*stack_b)->number != num)
	{	
		if (num_position <= list_len / 2)
			ft_rotate_b(stack_b);
		else
			ft_reverse_rotate_b(stack_b);
	}
}
