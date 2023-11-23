/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:46:23 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/11/23 18:57:25 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

static t_bool	valid_strs_numbers(char **strs, int arr_size)
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
		return ; // invalid "numbers"
	i = 0;
	while (strs[i] && i < arr_size)
	{
		ltmp = ft_atol(strs[i]);
		printf("ltmp: %ld|%d|%d\n", ltmp, ltmp < (long) INT_MIN, ltmp > (long) INT_MAX);
		if (ltmp < (long) INT_MIN || ltmp > (long) INT_MAX)
			return ; // invalid "numbers"
		tmp = ft_newlist(ltmp);
		if (!tmp)
			return ; // malloc error
		if (*stack == NULL)
			*stack = tmp;
		else
			ft_add_back(stack, tmp);
		tmp = NULL;
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}

