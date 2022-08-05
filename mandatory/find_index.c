/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:50:36 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/28 08:01:07 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_index(t_stacks *stack, int to_find)
{
	int	i;

	i = stack->s[B].end - 1;
	while (i >= 0)
	{
		if (stack->s[B].array[i] == to_find)
			return (i);
		i--;
	}
	return (stack->s[B].end);
}

int	find_lowest_index_array(long int *stack, int end)
{
	int	i;
	int	lowest;

	lowest = end - 1;
	i = 0;
	while (i <= end - 1)
	{
		if (stack[i] < stack[lowest])
			lowest = i;
		i++;
	}
	return (lowest);
}

void	find_lowest_index(t_stacks *stack)
{
	int	i;

	stack->lowest = stack->s[A].end - 1;
	stack->second_lowest = stack->s[A].end - 1;
	i = 0;
	while (i < stack->s[A].end)
	{
		if (stack->s[A].array[i] < stack->s[A].array[stack->lowest])
		{
			stack->second_lowest = stack->lowest;
			stack->lowest = i;
		}
		i++;
	}
}

int	second_lowest_operations(t_stacks *stack)
{
	int	second_lowest_commit;

	second_lowest_commit = 0;
	if (stack->second_lowest == stack->s[A].end - 1)
	{
		push(stack, B);
		second_lowest_commit = 1;
	}
	else if (stack->second_lowest == stack->s[A].end - 2 && \
			check_gap_condition(stack))
	{
		r(stack, A);
		push(stack, B);
		second_lowest_commit = 1;
	}
	else if (stack->second_lowest == 0 && check_gap_condition(stack))
	{
		re(stack, A);
		push(stack, B);
		second_lowest_commit = 1;
	}
	find_lowest_index(stack);
	return (second_lowest_commit);
}

void	adjust_second_lowest_index(t_stacks *stack)
{
	int	i;

	i = 0;
	if (stack->lowest == stack->second_lowest)
		stack->second_lowest = (stack->second_lowest + 1) % stack->s[A].end;
	while (i < stack->s[A].end)
	{
		if (stack->s[A].array[i] < stack->s[A].array[stack->second_lowest] && \
			i != stack->lowest)
			stack->second_lowest = i;
		i++;
	}
}
