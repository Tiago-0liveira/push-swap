/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/11/30 15:08:06 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/11/30 15:08:55 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	prepare_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	assign_target_a(a, b);
	calculate_push_cost(a, b);
	calculate_cheapest(a);
}

void	assign_target_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp_b;
	t_stack	*target;
	long	best_index;

	while (a)
	{
		best_index = LONG_MIN;
		tmp_b = b;
		while (tmp_b)
		{
			if (tmp_b->value < a->value && tmp_b->value > best_index)
			{
				best_index = tmp_b->value;
				target = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (best_index == LONG_MIN)
			a->target = find_biggest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	calculate_push_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_size(a);
	len_b = ft_stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	calculate_cheapest(t_stack *stack)
{
	long	cheapest;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
