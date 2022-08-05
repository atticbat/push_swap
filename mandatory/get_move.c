/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:48:01 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/01 22:03:48 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	perform_parallel_operations(t_stacks *stack, int **moves, \
	int *overlap, int best)
{
	while (overlap[best] > 0)
	{
		if (moves[best][A] > 0)
		{
			rr(stack);
			moves[best][A]--;
			moves[best][B]--;
		}
		else
		{
			rrr(stack);
			moves[best][A]++;
			moves[best][B]++;
		}
		overlap[best]--;
	}
}

static void	bring_to_top(t_stacks *stack, int **moves, int best)
{
	while (moves[best][B] > 0)
	{
		r(stack, B);
		moves[best][B]--;
	}
	while (moves[best][B] < 0)
	{
		re(stack, B);
		moves[best][B]++;
	}
}

static void	free_all(int **moves, int *overlap, int seek)
{
	int	i;

	i = 0;
	while (i < seek)
	{
		free (moves[i]);
		i++;
	}
	free (moves);
	free (overlap);
}

int	get_move(t_stacks *stack)
{
	int	**moves;
	int	best;
	int	*overlap;
	int	i;

	i = 0;
	moves = (int **) malloc (sizeof (int *) * stack->seek);
	overlap = (int *) malloc (sizeof (int) * stack->seek);
	while (i < stack->seek)
	{
		moves[i] = (int *) malloc (sizeof (int) * 2);
		overlap[i] = 0;
		i++;
	}
	best = get_weight(stack, moves, overlap);
	perform_parallel_operations(stack, moves, overlap, best);
	bring_to_top(stack, moves, best);
	if (stack->start_number > stack->s[B].array[stack->s[B].end - 1])
		stack->start_number = stack->s[B].array[stack->s[B].end - 1];
	if (stack->end_number < stack->s[B].array[stack->s[B].end - 1])
		stack->end_number = stack->s[B].array[stack->s[B].end - 1];
	i = moves[best][A];
	free_all(moves, overlap, stack->seek);
	return (i);
}

// static void	move_one(t_stacks *stack)
// {
// 	int	highest;
// 	int	highest_index;
// 	int	move_to;

// 	highest = find_highest(stack->s[B]);
// 	highest_index = find_index(stack, highest);
// 	move_to = get_move(stack);
// 	ft_printf("\nInput index: %d, Real value: %d, Return: %d\n", 
// 		highest_index, highest, move_to);
// 	while (move_to > 0)
// 	{
// 		r(stack, A);
// 		move_to--;
// 	}
// 	while (move_to < 0)
// 	{
// 		re(stack, A);
// 		move_to++;
// 	}
// 	push(stack, A);
// }

// int main(void)
// {
//     t_stacks    stack;
// 	int	array_a[] = { 98, 62, 39, 32, 28, 27, 23 };
// 	int	array_b[] = { 34,20,29,24,89,82,95,41,75,31,45,43,3,42,36,72,84,54,
// 		38,55,51,1,
// 		49,58,22,14,93,78,94,85,52,2,56,59,66,9,25,26,10,4,8,7,12,
// 		83,40,71,46,60,17,65,47,92,11,44,63,30,57,13,16,79,74,91,97,77,73,
// 		87,35,99,86,80,90,5,96,19,81,48,15,6,33,76,18,69,61,68,100,70,
// 		21,37,64,53,67,0,50	};
//     // int array_b[] = { 
// 	// 	71, 98, 67, 69, 99, 22, 10, 3, 0, 2, 
// 	// 	83, 37, 45, 53, 57, 92, 32, 27, 58, 55, 
// 	// 	30, 62, 13, 11, 49, 81, 84, 
// 	// 	75, 6, 23, 70, 95, 82, 17, 33, 90, 96, 
// 	// 	97, 44, 77, 86, 63, 26, 24, 5, 85, 93, 
// 	// 	47, 34, 43, 50, 38, 89, 42, 20, 40, 74, 
// 	// 	66, 48, 59, 25, 1, 56, 36, 46, 52, 
// 	// 	61, 64, 41, 79, 88, 60, 9, 87, 28, 65, 
// 	// 	29, 94, 31, 73, 68, 15, 14, 16, 35, 
// 	// 	76, 80, 19, 51, 78, 21, 54, 91, 72, 18 };
// 	int	lowest;
//     stack.s[A].array = (int *) malloc (100 * sizeof(int));
//     stack.s[B].array = (int *) malloc (100 * sizeof(int));
//     stack.s[A].end = 7;
//     stack.s[B].end = 93;
// 	stack.start_number = 23;
// 	stack.end_number = 98;
//     ft_memcpy(stack.s[A].array, array_a, sizeof(int) * 7);
//     ft_memcpy(stack.s[B].array, array_b, sizeof(int) * 93);
// 	for (int i = 0; i <= 93; i++)
// 	{
// 		print_all(&stack);
// 		move_one(&stack);
// 	}
// 	lowest = find_lowest(stack.s[A]);
// 	while (stack.s[A].array[stack.s[A].end - 1] != lowest)
// 		r(&stack, A);
// 	print_all(&stack);
//     return (0);
// }
