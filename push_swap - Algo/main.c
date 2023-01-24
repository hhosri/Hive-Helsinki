/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:16:13 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/09 17:05:34 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_sorting(t_stack **stack_a, t_stack **stack_b)
{	
	if (ft_lstsize_stack(*stack_a) <= 5)
		ft_sort_small(stack_a, stack_b);
	else
		ft_sort_large(stack_a, stack_b);
}

static void	ft_push_swap(int index, char **input)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (!(ft_check_input(index, input)))
		write(2, "Error\n", 6);
	else
	{
		stack_a = ft_fill_stack_a(index, input);
		ft_indexing_stack(stack_a, ft_lstsize_stack(stack_a));
		if (ft_is_sorted(stack_a))
		{
			clear_stack(&stack_a);
			return ;
		}
		else
			handle_sorting(&stack_a, &stack_b);
		clear_stack(&stack_a);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	**str_args;

	i = 0;
	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (0);
		str_args = ft_split(argv[1], ' ');
		ft_push_swap(0, str_args);
		while (str_args[i])
		{
			free(str_args[i]);
			i++;
		}
		free(str_args);
	}
	else
	{
		ft_push_swap(1, argv);
	}
	return (0);
}
