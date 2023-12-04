/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:08:13 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/12/04 19:54:23 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (false);
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_size_3(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if (biggest_node == (*a)->next)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort(t_stack **a, t_stack **b)
{
	int	a_len;

	a_len = ft_stack_size(*a);
	if (a_len-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	if (a_len-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	while (a_len-- > 3 && !is_sorted(*a))
	{
		prepare_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_size_3(a);
	while (*b)
	{
		current_index(*a);
		current_index(*b);
		assign_target_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
