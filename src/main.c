/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:05:00 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/11/14 16:48:26 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	check_args(argc, argv);
	stacks = init_stacks();
	if (!stacks)
		return (EXIT_SUCCESS);
	
	
}

void	check_args(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		ft_printf(USAGE);
		exit(EXIT_FAILURE);
	}
}

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = init_stack();
	if (!stacks->a)
	{
		free(stacks);
		return (NULL);
	}
	stacks->b = init_stack();
	if (!stacks->b)
	{
		free(stacks->a);
		free(stacks);
		return (NULL);
	}
	return (stacks);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->node = NULL;
	return (stack);
}
