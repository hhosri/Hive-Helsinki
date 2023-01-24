/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:29:11 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/09 12:20:35 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack_a)
{
	int	list_size;
	int	min;

	min = stack_a->number;
	list_size = ft_lstsize_stack(stack_a);
	while (stack_a)
	{
		if (stack_a->number < min)
		{
			min = stack_a->number;
		}			
		stack_a = stack_a->next;
	}
	return (min);
}

int	find_min_position(t_stack *stack_a)
{
	int	list_size;
	int	min;
	int	min_position;

	min = stack_a->number;
	list_size = ft_lstsize_stack(stack_a);
	while (stack_a)
	{
		if (stack_a->number < min)
		{
			min = stack_a->number;
			min_position = stack_a->position;
		}			
		stack_a = stack_a->next;
	}
	return (min_position);
}

void	push_min_totop_a(t_stack **stack_a)
{
	int	min;
	int	min_position;
	int	list_len;

	min = find_min(*stack_a);
	min_position = find_min_position(*stack_a);
	list_len = ft_lstsize_stack(*stack_a);
	while ((*stack_a)->number != min)
	{	
		if (min_position <= list_len / 2)
			ft_rotate_a(stack_a);
		else
			ft_reverse_rotate_a(stack_a);
	}
}
