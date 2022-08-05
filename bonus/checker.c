/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:46:57 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/05 18:39:31 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	free_stacks(t_stacks *stack)
{
	if (stack->s[A].array)
		free (stack->s[A].array);
	if (stack->s[B].array)
		free (stack->s[B].array);
	return (0);
}

static int	initialise(t_stacks *stack, char **argv, int argc)
{
	if (argc < 2)
		return (0);
	else if (argc == 2 && !argv[2])
		return (0);
	if (!parse_input(stack, argv, argc))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (!initialise(&stack, argv, argc))
		return (free_stacks(&stack));
	if (!get_lines(&stack))
	{
		write(2, "Error\n", 6);
		return (free_stacks(&stack));
	}
	if (check_sorted_a(stack.s[A].array, stack.s[A].end))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (free_stacks(&stack));
}
