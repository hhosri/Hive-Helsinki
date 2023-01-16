/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_except_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:45:30 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/06 17:25:32 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search(int min, int max, t_stack *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->index >= min && stack_a->index <= max)
			return (1);
		else
			stack_a = stack_a->next;
	}
	return (0);
}

static int	move_below_half(t_stack **stack_a, t_stack **stack_b,
	int lst_size, t_stack **node)
{
	int	pushed;

	pushed = 0;
	while (search(0, lst_size / 2, *node) == 1)
	{
		if ((*node)->index <= lst_size / 2)
		{
			push_any_totop_a(stack_a, (*node)->number);
			ft_push_b(stack_a, stack_b);
			*node = *stack_a;
			pushed = ft_lstsize_stack(*stack_a);
		}
		else
			*node = (*node)->next;
		if (pushed == 3)
			break ;
	}
	return (pushed);
}

void	move_except_3(t_stack **stack_a, t_stack **stack_b)
{
	int		lst_size;
	int		pushed;
	t_stack	*node;

	node = *stack_a;
	lst_size = ft_lstsize_stack(*stack_a) - 1;
	pushed = move_below_half(stack_a, stack_b, lst_size, &node);
	if (pushed == 3)
		return ;
	while (search((lst_size / 2 + 1), lst_size, node) == 1)
	{
		if (node->index > lst_size / 2)
		{
			push_any_totop_a(stack_a, node->number);
			ft_push_b(stack_a, stack_b);
			node = *stack_a;
			pushed = ft_lstsize_stack(*stack_a);
		}
		else
			node = node->next;
		if (pushed == 3)
			break ;
	}
}
