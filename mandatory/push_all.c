/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 01:55:40 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/01 21:51:46 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	change_group(t_stacks *stack, int i)
{
	i += 2;
	stack->key[0] = (i - 2) * (stack->highest / stack->groups);
	stack->key[1] = (i - 1) * (stack->highest / stack->groups);
	stack->key[2] = (i - 1) * (stack->highest / stack->groups);
	stack->key[3] = i * (stack->highest / stack->groups);
	stack->oscillation = (stack->oscillation + 1) % 2;
	r(stack, A);
	return (2);
}

static int	check_boundary(t_stacks *stack, int lower, int upper, t_array lis)
{
	if (stack->s[A].array[stack->s[A].end - 1] >= stack->key[lower] && \
		stack->s[A].array[stack->s[A].end - 1] < stack->key[upper] && \
		!check_sorted_array(stack->s[A].array[stack->s[A].end - 1], lis))
		return (1);
	return (0);
}

static void	perform_rotate(t_stacks *stack, t_array lis, int mode)
{
	if (!stack->oscillation && check_boundary(stack, 0, 3, lis) && mode == 0)
		r(stack, B);
	else if (!stack->oscillation && mode == 0)
		rr(stack);
	if (stack->oscillation && check_boundary(stack, 0, 3, lis) && mode == 1)
		r(stack, B);
	else if (stack->oscillation && mode == 1)
		rr(stack);
}

static void	perform_push(t_stacks *stack, t_array lis)
{
	int	i;

	i = 2;
	while (!check_sorted_a(stack->s[A].array, stack->s[A].end))
	{
		supplement_bounds(stack);
		if (check_boundary(stack, 2, 3, lis))
		{
			push(stack, B);
			perform_rotate(stack, lis, 0);
		}
		else if (check_boundary(stack, 0, 1, lis))
		{
			push(stack, B);
			perform_rotate(stack, lis, 1);
		}
		else if (stack->start_number == stack->s[A].array[stack->s[A].end - 2])
			i += change_group(stack, i);
		else
			r(stack, A);
	}
}

void	push_all(t_stacks *stack)
{
	t_array	lis;

	stack->key[0] = 0;
	stack->key[1] = stack->highest / stack->groups;
	stack->key[2] = stack->highest / stack->groups;
	stack->key[3] = 2 * (stack->highest / stack->groups);
	stack->oscillation = 0;
	lis = longest_increasing_subsequence(stack->s[A]);
	stack->start_number = lis.array[0];
	stack->end_number = lis.array[lis.end - 1];
	while (stack->s[A].array[stack->s[A].end - 1] != stack->start_number)
		r(stack, A);
	perform_push(stack, lis);
	free (lis.array);
}
