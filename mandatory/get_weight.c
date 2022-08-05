/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_weight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:07:32 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/01 21:23:58 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_weight(t_stacks *stack, int **moves, int i)
{
	int	highest_b;
	int	index_b;

	highest_b = find_highest(stack->s[B]);
	index_b = find_index(stack, highest_b - i);
	if (index_b < stack->s[B].end)
	{
		moves[i][A] = find_insertion_point(stack, index_b);
		moves[i][B] = find_path_to_top(stack, index_b);
	}
	else
	{
		moves[i][A] = stack->s[B].end + stack->s[A].end;
		moves[i][B] = stack->s[B].end + stack->s[A].end;
	}
}

static int	compare_weight(t_stacks *stack, int *moves, int *overlap, \
	int *len)
{
	if (moves[A] < 0 && moves[B] < 0 || \
		moves[A] > 0 && moves[B] > 0)
	{
		if (ft_abs(moves[A]) > ft_abs(moves[B]))
			*overlap = ft_abs(moves[B]);
		else
			*overlap = ft_abs(moves[A]);
	}
	if (*len > ft_abs(moves[A]) + ft_abs(moves[B]) - *overlap)
	{
		*len = ft_abs(moves[A]) + ft_abs(moves[B]) - *overlap;
		return (1);
	}
	return (0);
}

int	get_weight(t_stacks *stack, int **moves, int *overlap)
{
	int	i;
	int	best;
	int	len;

	len = stack->s[B].end + stack->s[A].end;
	best = 0;
	i = 0;
	while (i < stack->seek)
	{
		set_weight(stack, moves, i);
		if (compare_weight(stack, moves[i], &overlap[i], &len))
			best = i;
		i++;
	}
	return (best);
}
