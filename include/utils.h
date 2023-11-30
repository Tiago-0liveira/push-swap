/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:49:51 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/11/30 17:17:01 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include <stdbool.h>
# include <stdlib.h>

# define STDOUT 1
# define STDERR 2

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			cheapest;
	bool			above_median;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}		t_stack;

// utils.c
// static bool	valid_strs_numbers(char **strs, int arr_size);
void	print_stack(t_stack *stack);
void	ft_str_arr_to_stack(char **strs, int arr_size, t_stack **stack);
t_stack	*find_biggest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);

// utils2.c
t_stack	*get_cheapest(t_stack *stack);
t_stack	*find_last(t_stack *stack);
bool	stack_has_int(t_stack *stack, int ltmp);
void	error_and_exit(char *error, t_stack *a);

// stack.c
t_stack	*ft_newlist(int val);
void	ft_add_front(t_stack **stack, t_stack *nw);
void	ft_add_back(t_stack **stack, t_stack *nw);
int		ft_stack_size(t_stack *stack);
void	ft_free_stack(t_stack **stack);

// stack_ops.c
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);

// stack_ops2.c
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);

// stack_ops3.c
void	rrr(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **stack);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

// sort.c
bool	is_sorted(t_stack *stack);
void	sort_size_3(t_stack **a);
void	sort(t_stack **a, t_stack **b);

// sort_utils.c
void	current_index(t_stack *stack);
void	prepare_nodes_a(t_stack *a, t_stack *b);
void	assign_target_a(t_stack *a, t_stack *b);
void	calculate_push_cost(t_stack *a, t_stack *b);
void	calculate_cheapest(t_stack *stack);

// prepare.c
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	move_to_top(t_stack **stack, t_stack *top_node, char stack_name);
void	assign_target_b(t_stack *a, t_stack *b);
void	min_on_top(t_stack **a);

#endif