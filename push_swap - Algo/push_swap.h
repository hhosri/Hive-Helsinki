/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:54:43 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/09 12:17:39 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				position;
	int				index;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				cost_a_type;
	int				cost_b_type;
	int				full_cost;
	struct s_stack	*next;
}					t_stack;

//check input
int		ft_check_input(int index, char **input);
long	ft_atoi_zero(const char *str);
int		ft_is_zero(char *number);
//fill stack A
t_stack	*ft_fill_stack_a(int index, char **input);
t_stack	*ft_lstlast_stack(t_stack *lst);
void	ft_lstadd_back_stack(t_stack *first, t_stack *new_list);
t_stack	*ft_create_node_stack(int content);
void	ft_indexing_stack(t_stack *stack_a, int stack_size);
//check if sorted
int		ft_is_sorted(t_stack *stack);
//op-swap
void	ft_swap_a(t_stack *stack_a);
void	ft_swap_b(t_stack *stack_b);
void	ft_swap_ab(t_stack *stack_a, t_stack *stack_b);
//op-push
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);
//op-rotate
t_stack	*ft_lstlast_stack(t_stack *lst);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
//op - reverse rotate
t_stack	*ft_lst_before_last_stack(t_stack *lst);
void	ft_reverse_rotate_a(t_stack **stack_a);
void	ft_reverse_rotate_b(t_stack **stack_b);
void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
//pre-sorting utils
void	ft_sorting_three(t_stack **stack_a);
void	ft_sort_small(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_large(t_stack **stack_a, t_stack **stack_b);
void	move_except_3(t_stack **stack_a, t_stack **stack_b);
//sorting utils
int		ft_lstsize_stack(t_stack *lst);
int		find_min(t_stack *stack_a);
int		find_min_position(t_stack *stack_a);
void	push_min_totop_a(t_stack **stack_a);
int		find_any_position(t_stack *stack_a, int num);
void	push_any_totop_a(t_stack **stack_b, int num);
void	push_any_totop_b(t_stack **stack_b, int num);
void	clear_stack(t_stack **stack_a);
void	find_max_node(t_stack *stack_a, int index);
//advanced-sorting utils
void	find_targets(t_stack *stack_a, t_stack *stack_b);
void	get_cost_full(t_stack *stack_a, t_stack *stack_b);
void	do_cheapest(t_stack **stack_a, t_stack **stack_b);
#endif
