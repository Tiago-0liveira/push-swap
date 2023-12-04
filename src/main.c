/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:05:00 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/12/04 19:55:03 by tiagoliv         ###   ########.fr       */
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
	stack_b = NULL;
	load_args(argc, argv, &stack_a);
	if (!is_sorted(stack_a))
	{
		if (ft_stack_size(stack_a) == 2)
			sa(&stack_a, false);
		else if (ft_stack_size(stack_a) == 3)
			sort_size_3(&stack_a);
		else
			sort(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	return (EXIT_SUCCESS);
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
		i = 0;
		while (ss[i])
			free(ss[i++]);
		free(ss);
	}
	else
	{
		ft_str_arr_to_stack(++argv, argc - 1, stack);
	}
}
