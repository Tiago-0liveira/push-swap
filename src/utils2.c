/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:34:54 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/11/30 15:35:03 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_has_int(t_stack *stack, int ltmp)
{
	while (stack)
	{
		if (stack->value == ltmp)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void	error_and_exit(char *error, t_stack *a)
{
	ft_putstr_fd(error, STDERR);
	ft_free_stack(&a);
	exit(1);
}
