/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:01:03 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/11/14 16:45:03 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

# define USAGE "usage: ./push_swap \"numbers\"\n"

typedef struct s_node {
	int				i;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*node;
}	t_stack;

typedef struct s_stacks {
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

t_stacks	*init_stacks(void);
t_stack		*init_stack(void);
void		check_args(int argc, char *argv[]);
#endif
