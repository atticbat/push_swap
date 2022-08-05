/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinsertion_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:40:19 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/01 21:52:44 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort(t_stacks *stack)
{
	int	move_to;

	move_to = 0;
	while (stack->s[B].end > 0)
	{
		move_to = get_move(stack);
		while (move_to > 0)
		{
			r(stack, A);
			move_to--;
		}
		while (move_to < 0)
		{
			re(stack, A);
			move_to++;
		}
		push(stack, A);
	}
}

static void	initialisation(t_stacks *stack)
{
	if (stack->s[A].end >= 100)
	{
		stack->groups = 4 + 7 * ((float)(stack->s[A].end - 100) / 400);
		stack->seek = 6 + 5 * ((float)(stack->s[A].end - 100) / 400);
	}
	else if (stack->s[A].end >= 500)
	{
		stack->groups = 11 + 9 * ((float)(stack->s[A].end - 500) / 1500);
		stack->seek = 11 + 9 * ((float)(stack->s[A].end - 500) / 1500);
	}
	else
	{
		stack->groups = 2 + 2 * ((float)(stack->s[A].end) / 100);
		stack->seek = 3 + 3 * ((float)(stack->s[A].end) / 100);
	}
	stack->highest = find_highest(stack->s[A]);
}

void	reinsertion_sort(t_stacks *stack)
{
	int	i;

	initialisation(stack);
	push_all(stack);
	stack->start_number = find_lowest(stack->s[A]);
	stack->end_number = find_highest(stack->s[A]);
	sort(stack);
	stack->start_number = 0;
	i = 0;
	while (stack->s[A].array[i] != stack->start_number)
		i++;
	if (i < stack->highest)
		while (stack->s[A].array[stack->s[A].end - 1] != stack->start_number)
			re(stack, A);
	else
		while (stack->s[A].array[stack->s[A].end - 1] != stack->start_number)
			r(stack, A);
}
