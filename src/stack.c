/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:54:59 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/12/04 19:29:02 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

t_stack	*ft_newlist(int val)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = val;
	stack->next = NULL;
	stack->prev = NULL;
	stack->target = NULL;
	stack->cheapest = false;
	return (stack);
}

void	ft_add_front(t_stack **stack, t_stack *nw)
{
	if (!stack || !nw)
		return ;
	nw->next = *stack;
	*stack = nw;
}

void	ft_add_back(t_stack **stack, t_stack *nw)
{
	t_stack	*tmp;

	if (!stack || !nw)
		return ;
	if (!*stack)
	{
		*stack = nw;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nw;
}

int	ft_stack_size(t_stack *stack)
{
	int		r;

	if (!stack)
		return (0);
	r = 0;
	while (stack)
	{
		stack = stack->next;
		r++;
	}
	return (r);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
