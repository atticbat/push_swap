/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 03:29:50 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/05 17:09:24 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	free_all(t_stacks *stack)
{
	if (stack->s[A].array)
		free (stack->s[A].array);
	if (stack->s[B].array)
		free (stack->s[B].array);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc < 2)
		return (0);
	else if (argc == 2 && !argv[2])
		return (0);
	if (!parse_input(&stack, argv, argc))
	{
		write(2, "Error\n", 6);
		return (free_all(&stack));
	}
	reindex(&stack);
	if (stack.s[A].end < 16)
		insertion_sort(&stack);
	else
		reinsertion_sort(&stack);
	return (free_all(&stack));
}
