/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reindex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:28:15 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/31 09:29:13 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reindex(t_stacks *stack)
{
	long int	*buffer_stack;
	int			buffer_end;
	int			i;
	int			lowest;

	i = stack->s[A].end - 1;
	buffer_stack = (long int *) malloc (sizeof (long int) * stack->s[A].end);
	buffer_end = i;
	while (i >= 0)
	{
		buffer_stack[i] = stack->s[A].array[i];
		i--;
	}
	i = 0;
	while (i <= buffer_end)
	{
		lowest = find_lowest_index_array(buffer_stack, buffer_end + 1);
		stack->s[A].array[lowest] = i;
		buffer_stack[lowest] = MAX;
		buffer_stack[lowest] += 1;
		i++;
	}
	free (buffer_stack);
}
