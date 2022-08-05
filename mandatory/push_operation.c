/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:30:58 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/31 19:53:06 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	shift_down(t_stacks *stack, t_current_stack s)
{
	stack->s[s].end += 1;
}

static void	shift_up(t_stacks *stack, t_current_stack s)
{
	stack->s[s].end -= 1;
}

void	push(t_stacks *stack, t_current_stack to)
{
	t_current_stack	from;

	from = (t_current_stack)((int)to + 1) % 2;
	if (stack->s[from].end < 1)
		return ;
	shift_down(stack, to);
	stack->s[to].array[stack->s[to].end - 1] = stack->s[from].array[stack->s[\
		from].end - 1];
	shift_up(stack, from);
	if (to == A)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	push_silent(t_stacks *stack, t_current_stack to)
{
	t_current_stack	from;

	from = (t_current_stack)((int)to + 1) % 2;
	if (stack->s[from].end < 1)
		return ;
	shift_down(stack, to);
	stack->s[to].array[stack->s[to].end - 1] = stack->s[from].array[stack->s[\
		from].end - 1];
	shift_up(stack, from);
}
