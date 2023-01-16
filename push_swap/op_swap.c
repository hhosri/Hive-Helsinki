/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:25:23 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/06 17:25:15 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_x(t_stack *stack_x)
{
	int	temp;
	int	temp2;

	if (!stack_x || !(stack_x->next))
		return ;
	else
	{
		temp = stack_x->number;
		temp2 = stack_x->index;
		stack_x->number = (stack_x->next)->number;
		(stack_x->next)->number = temp;
		stack_x->index = (stack_x->next)->index;
		(stack_x->next)->index = temp2;
	}
}

void	ft_swap_a(t_stack *stack_a)
{
	ft_swap_x(stack_a);
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack *stack_b)
{
	ft_swap_x(stack_b);
	ft_printf("sb\n");
}

void	ft_swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap_x(stack_a);
	ft_swap_x(stack_b);
	ft_printf("ss\n");
}
