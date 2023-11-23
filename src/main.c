/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:05:00 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/11/23 18:35:17 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		ft_putstr_fd(USAGE, STDERR);
		return (EXIT_FAILURE);
	}
	stack_a = NULL;
	stack_b = init_stack();
	if (!stack_b)
		return (EXIT_SUCCESS);
	load_args(argc, argv, &stack_a);
	print_stack(stack_a);
}

void	load_args(int argc, char *argv[], t_stack **stack)
{
	char	**ss;
	int		i;

	if (argc == 2)
	{
		ss = ft_split(argv[1], ' ');
		i = 0;
		while (ss[i])
			i++;
		ft_str_arr_to_stack(ss, i, stack);
	}
	else
	{
		ft_str_arr_to_stack(++argv, argc - 1, stack);
	}
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->next = NULL;
	return (stack);
}
