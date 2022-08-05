/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:54:43 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/05 18:31:19 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line.h"

void	push_silent(t_stacks *stack, t_current_stack to);
void	swap(t_stacks *stack, t_current_stack s);
int		move_glossary(t_stacks *stack, char *buffer);
int		get_lines(t_stacks *stack);

#endif
