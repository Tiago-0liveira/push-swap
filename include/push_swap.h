/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:01:03 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/11/15 16:03:57 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "utils.h"

# define USAGE "usage: ./push_swap \"numbers\"\n"

t_stacks	*init_stacks(void);
t_stack		*init_stack(void);
void		check_args(int argc, char *argv[]);
#endif
