/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:49:51 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/11/23 18:36:00 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "bool.h"
# include "libft.h"
# include <stdlib.h>

# define STDOUT 1
# define STDERR 2

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}		t_stack;

// stack.c

t_stack	*ft_newlist(int val);
void	ft_add_front(t_stack **stack, t_stack *nw);
void	ft_add_back(t_stack **stack, t_stack *nw);
int		ft_stack_size(t_stack *stack);
void	ft_free_stack(t_stack **stack);
void	ft_str_arr_to_stack(char **strs, int arr_size, t_stack **stack);
void	print_stack(t_stack *stack);
//

#endif