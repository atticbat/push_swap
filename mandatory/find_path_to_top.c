/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:23:07 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/31 09:24:24 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ascend(t_stacks *stack, int idx)
{
	int	moves;

	moves = 0;
	while (idx != stack->s[B].end - 1)
	{
		idx--;
		moves--;
		if (idx < 0)
			return (moves);
	}
	return (moves);
}

static int	descend(t_stacks *stack, int idx)
{
	int	moves;

	moves = 0;
	while (idx != stack->s[B].end - 1)
	{
		idx++;
		moves++;
		if (idx == stack->s[B].end)
			return (moves);
	}
	return (moves);
}

int	find_path_to_top(t_stacks *stack, int idx)
{
	if (idx == stack->s[B].end - 1)
		return (0);
	if (idx < stack->s[B].end / 2)
		return (ascend(stack, idx));
	else
		return (descend(stack, idx));
}
