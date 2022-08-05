/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:34:04 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/17 00:31:09 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stacks *stack, t_current_stack s)
{
	int	buffer;

	if (stack->s[s].end < 2)
		return ;
	buffer = stack->s[s].array[stack->s[s].end - 1];
	stack->s[s].array[stack->s[s].end - 1] = stack->s[s].array[stack->s[s].end \
		- 2];
	stack->s[s].array[stack->s[s].end - 2] = buffer;
}

void	s(t_stacks *stack, t_current_stack s)
{
	swap(stack, s);
	if (s == A)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	ss(t_stacks *stack)
{
	swap(stack, A);
	swap(stack, B);
	ft_printf("ss\n");
}
