/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_insertion_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 06:31:09 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/30 13:43:44 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	case_insert_ends(t_stacks *stack, int idx)
{
	int	i;
	int	j;
	int	jc;

	i = 0;
	j = stack->s[A].end - 1;
	jc = 0;
	while (stack->s[A].array[i] != stack->start_number)
		i++;
	i++;
	while (stack->s[A].array[j] != stack->start_number)
	{
		j--;
		jc++;
	}	
	if (i > jc)
		return (jc);
	else
		return (i * -1);
}

static int	case_insert_between(t_stacks *stack, int idx)
{
	int	i;
	int	j;
	int	jc;

	i = 0;
	j = stack->s[A].end - 1;
	jc = 0;
	while (stack->s[B].array[idx] > stack->s[A].array[i % stack->s[A].end] || \
		stack->s[B].array[idx] < stack->s[A].array[(i + 1) % stack->s[A].end])
		i++;
	i++;
	while (stack->s[B].array[idx] > stack->s[A].array[j % stack->s[A].end] || \
		stack->s[B].array[idx] < stack->s[A].array[(j + 1) % stack->s[A].end])
	{
		j--;
		jc++;
	}
	if (i > jc)
		return (jc);
	else
		return (i * -1);
}

int	find_insertion_point(t_stacks *stack, int idx)
{
	if (stack->s[B].array[idx] < stack->s[A].array[stack->s[A].end - 1] && \
		stack->s[B].array[idx] > stack->s[A].array[0])
		return (0);
	if (stack->s[B].array[idx] > stack->end_number || stack->s[B].array[idx] \
		< stack->start_number)
	{
		if (stack->s[A].array[stack->s[A].end - 1] == stack->start_number)
			return (0);
		return (case_insert_ends(stack, idx));
	}
	return (case_insert_between(stack, idx));
}

// int main(void)
// {
//     t_stacks    stack;
//     int array_a[] = { 10, 7, 3, 0, 13, 12 };
//     int array_b[] = { 11, 4, 5, 9, 6, 2 };
//     int i;
// 	int	highest;
// 	int	highest_index;
//     stack.s[A].array = (int *) malloc (12 * sizeof(int));
//     stack.s[B].array = (int *) malloc (12 * sizeof(int));
//     stack.s[A].end = 6;
//     stack.s[B].end = 6;
// 	stack.start_number = 0;
// 	stack.end_number = 13;
//     memcpy(stack.s[A].array, array_a, sizeof(int) * 6);
//     memcpy(stack.s[B].array, array_b, sizeof(int) * 6);
//     i = 0;
//     while (i < 6)
//     {
//         printf("%d ", stack.s[A].array[i]);
//         i++;
//     }
//     printf("\n");
//     i = 0;
//     while (i < 6)
//     {
//         printf("%d ", stack.s[B].array[i]);
//         i++;
//     }
// 	highest = find_highest(stack.s[B]);
// 	highest_index = find_index(&stack, highest);
// 	printf("\nInput index: %d, Real value: %d, Return: %d\n", 
// 		highest_index, highest, find_insertion_point(&stack, i));
// 	highest--;
// 	highest_index = find_index(&stack, highest);
// 	if (highest_index < stack.s[B].end)
// 		printf("\nInput index: %d, Real value: %d, Return: %d\n", 
// 		highest_index, highest, find_insertion_point(&stack, i));
// 	highest--;
// 	highest_index = find_index(&stack, highest);
// 	if (highest_index < stack.s[B].end)
// 		printf("\nInput index: %d, Real value: %d, Return: %d\n", 
// 		highest_index, highest, find_insertion_point(&stack, i));
//     return (0);
// }
