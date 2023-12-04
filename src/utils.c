/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:46:23 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/12/04 14:57:41 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

static bool	valid_strs_numbers(char **strs, int arr_size)
{
	int		i;

	i = 0;
	while (strs[i] && i < arr_size)
	{
		if (!ft_isint(strs[i]))
			return (false);
		i++;
	}
	return (true);
}

void	ft_str_arr_to_stack(char **strs, int arr_size, t_stack **stack)
{
	int		i;
	long	ltmp;
	t_stack	*tmp;

	if (!valid_strs_numbers(strs, arr_size))
		return (error_and_exit("Error\n", *stack));
	i = 0;
	while (strs[i] && i < arr_size)
	{
		ltmp = ft_atol(strs[i]);
		tmp = ft_newlist(ltmp);
		if (ltmp < (long) INT_MIN || ltmp > (long) INT_MAX
			|| stack_has_int(*stack, ltmp) || !tmp)
			return (error_and_exit("Error\n", *stack));
		if (!(*stack))
			*stack = tmp;
		else
		{
			tmp->prev = find_last(*stack);
			tmp->prev->next = tmp;
		}
		tmp = NULL;
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("|\n");
}

t_stack	*find_biggest(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_smallest(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
