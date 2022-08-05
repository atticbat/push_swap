/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_p2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:00:03 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/17 01:03:43 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_gap_condition(t_stacks *stack)
{
	if ((ft_abs(stack->lowest - stack->second_lowest) == 2 || ft_abs(\
		stack->lowest - stack->second_lowest) == 3) && stack->lowest != \
		stack->s[A].end / 2)
		return (1);
	return (0);
}

void	bring_up_lowest(t_stacks *stack)
{
	int	i;

	i = stack->lowest;
	if (stack->s[A].end / 2 <= stack->lowest)
	{
		while (i < stack->s[A].end - 1)
		{
			r(stack, A);
		i++;
		}
	}
	else
	{
		while (i >= 0)
		{
			re(stack, A);
			i--;
		}
	}
}

void	parallel_operations(t_stacks *stack)
{
	adjust_second_lowest_index(stack);
	if (stack->s[A].array[stack->s[A].end - 1] > stack->s[A].array[\
		stack->s[A].end - 2] && stack->s[B].end > 2)
		ss(stack);
	else if (stack->s[B].end == 2)
	{
		if (stack->s[A].end / 2 >= stack->lowest)
			rr(stack);
		else
			rrr(stack);
	}
	else
		s(stack, B);
}

void	lowest_operations(t_stacks *stack)
{
	if (stack->lowest == stack->s[A].end - 2)
		s(stack, A);
	else if (stack->lowest == 0)
		re(stack, A);
	else
		bring_up_lowest(stack);
}
