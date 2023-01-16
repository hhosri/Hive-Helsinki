/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:21:33 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/06 18:29:28 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_large(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;
	int	lst_size;

	move_except_3(stack_a, stack_b);
	ft_sorting_three(stack_a);
	while (*stack_b)
	{
		find_targets(*stack_a, *stack_b);
		get_cost_full(*stack_a, *stack_b);
		do_cheapest(stack_a, stack_b);
	}
	min_pos = find_min_position(*stack_a);
	lst_size = ft_lstsize_stack(*stack_a);
	while (ft_is_sorted(*stack_a) == 0)
	{
		if (min_pos <= lst_size / 2)
			ft_rotate_a(stack_a);
		else
			ft_reverse_rotate_a(stack_a);
	}
}
