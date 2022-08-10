/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:29:37 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/10 03:17:56 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	insertion_operations(t_stacks *stack)
{
	int	second_lowest_commit;

	second_lowest_commit = 0;
	find_lowest_index(stack);
	if (stack->s[A].end >= 5 && !check_continuity(stack) && stack->lowest < \
		stack->s[A].end - 2 && stack->lowest > 0)
	{
		adjust_second_lowest_index(stack);
		second_lowest_commit = second_lowest_operations(stack);
	}
	lowest_operations(stack);
	if (!check_continuity(stack))
	{
		push(stack, B);
		if (second_lowest_commit)
			parallel_operations(stack);
	}
}

static void	push_back(t_stacks *stack)
{
	while (stack->s[B].end)
		push(stack, A);
}

void	hardcode_three_operations(t_stacks *stack)
{
	if (stack->s[A].end != 3)
		return ;
	if (stack->s[A].array[2] < stack->s[A].array[1] && stack->s[A].array[1] > \
		stack->s[A].array[0] && stack->s[A].array[2] < stack->s[A].array[0])
	{
		s(stack, A);
		r(stack, A);
	}
	if (stack->s[A].array[2] > stack->s[A].array[1] && stack->s[A].array[1] < \
		stack->s[A].array[0] && stack->s[A].array[2] < stack->s[A].array[0])
		s(stack, A);
	if (stack->s[A].array[2] < stack->s[A].array[1] && stack->s[A].array[1] > \
		stack->s[A].array[0] && stack->s[A].array[2] > stack->s[A].array[0])
		re(stack, A);
	if (stack->s[A].array[2] > stack->s[A].array[1] && stack->s[A].array[1] < \
		stack->s[A].array[0] && stack->s[A].array[2] > stack->s[A].array[0])
		r(stack, A);
	if (stack->s[A].array[2] > stack->s[A].array[1] && stack->s[A].array[1] > \
		stack->s[A].array[0] && stack->s[A].array[2] > stack->s[A].array[0])
	{
		s(stack, A);
		re(stack, A);
	}
}

static void	hardcode_two_operations(t_stacks *stack)
{
	if (stack->s[A].end != 2)
		return ;
	if (stack->s[A].array[1] > stack->s[A].array[0])
		s(stack, A);
}

void	insertion_sort(t_stacks *stack)
{
	while (1)
	{
		hardcode_two_operations(stack);
		hardcode_three_operations(stack);
		if (check_continuity(stack))
		{
			push_back(stack);
			break ;
		}
		insertion_operations(stack);
	}
}
