/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:49:51 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/11/15 16:05:00 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

// stack.c

t_stack *ft_newlist(int val);
void    ft_add_front(t_stack **stack, t_stack *nw);
void    ft_add_back(t_stack **stack, t_stack *nw);
int     ft_stack_size(t_stack *stack);
void    ft_free_stack(t_stack **stack);

// 

#endif