/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:48:28 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/12/29 13:31:35 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting_three(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*stack_a)->number;
	mid = (*stack_a)->next->number;
	bottom = (*stack_a)->next->next->number;
	if (mid > top && mid > bottom && bottom > top)
	{
		ft_reverse_rotate_a(stack_a);
		ft_swap_a(*stack_a);
	}
	else if (mid < top && mid < bottom && bottom > top)
		ft_swap_a(*stack_a);
	else if (mid > top && mid > bottom && top > bottom)
		ft_reverse_rotate_a(stack_a);
	else if (mid < bottom & mid < top && top > bottom)
		ft_rotate_a(stack_a);
	else if (top > mid && mid > bottom)
	{
		ft_swap_a(*stack_a);
		ft_reverse_rotate_a(stack_a);
	}
}

static void	ft_sorting_four(t_stack **stack_a, t_stack **stack_b)
{
	push_min_totop_a(stack_a);
	ft_push_b(stack_a, stack_b);
	ft_sorting_three(stack_a);
	ft_push_a(stack_a, stack_b);
}

static void	ft_sorting_five(t_stack **stack_a, t_stack **stack_b)
{
	push_min_totop_a(stack_a);
	ft_push_b(stack_a, stack_b);
	ft_sorting_four(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
}

void	ft_sort_small(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize_stack(*stack_a) == 2)
		ft_swap_a(*stack_a);
	else if (ft_lstsize_stack(*stack_a) == 3)
		ft_sorting_three(stack_a);
	else if (ft_lstsize_stack(*stack_a) == 4)
		ft_sorting_four(stack_a, stack_b);
	else if (ft_lstsize_stack(*stack_a) == 5)
		ft_sorting_five(stack_a, stack_b);
}
