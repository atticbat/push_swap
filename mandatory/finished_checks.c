/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finished_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:48:44 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/01 21:51:18 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sorted_array(int top, t_array sorted)
{
	int	i;

	i = 0;
	while (i < sorted.end)
	{
		if (sorted.array[i] == top)
			return (1);
		i++;
	}
	return (0);
}

int	check_continuity(t_stacks *stack)
{
	int	i;

	i = stack->s[B].end - 1;
	while (i > 0)
	{
		if (stack->s[B].array[i] < stack->s[B].array[i - 1])
			return (0);
		i--;
	}
	if (i >= 0 && stack->s[B].array[stack->s[B].end - 1] > \
		stack->s[A].array[stack->s[A].end - 1])
		return (0);
	i = stack->s[A].end - 1;
	while (i > 0)
	{
		if (stack->s[A].array[i] > stack->s[A].array[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	check_sorted_a(int *stack, int end)
{
	int	i;

	i = end - 1;
	while (i > 0)
	{
		if (stack[i] > stack[i - 1])
			return (0);
		i--;
	}
	return (1);
}
