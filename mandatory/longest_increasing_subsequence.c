/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 03:35:48 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/30 09:43:00 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/push_swap.h"

static t_array	assume_no_skips(t_array s, int index)
{
	t_array	buffer;
	int		last_i;
	int		i;

	buffer.array = (int *) malloc (sizeof(int) * s.end);
	buffer.array[0] = s.array[index];
	buffer.end = 1;
	i = index - 1;
	last_i = index;
	while (i >= 0)
	{
		if (s.array[last_i] < s.array[i])
		{
			buffer.array[buffer.end] = s.array[i];
			last_i = i;
			buffer.end++;
		}
		i--;
	}
	return (buffer);
}

static t_array	complete_sequence(t_array s, int index, int to_ignore)
{
	t_array	result;
	int		last_i;
	int		i;

	result.array = (int *) malloc (sizeof(int) * s.end);
	result.array[0] = s.array[index];
	i = 1;
	while (i <= to_ignore)
	{
		s.array[index - i] = 0;
		i++;
	}
	result.end = 1;
	last_i = index;
	while (index > 0)
	{
		if (s.array[last_i] < s.array[index - 1])
		{
			result.array[result.end] = s.array[index - 1];
			last_i = index - 1;
			result.end++;
		}
		index--;
	}
	return (result);
}

static t_array	assume_skips(t_array s, int index)
{
	t_array	editable;
	t_array	buffer;
	t_array	result;
	int		i;

	i = 0;
	result.array = NULL;
	editable = ft_intdup(s);
	while (i < index)
	{
		buffer = complete_sequence(editable, index, i);
		if (result.end < buffer.end)
		{
			if (result.array)
				free(result.array);
			result = buffer;
		}
		else
			free (buffer.array);
		i++;
	}
	free (editable.array);
	return (result);
}

static t_array	decide_skip(t_array s, int i)
{
	t_array	buffer;
	t_array	buffer2;

	buffer = assume_no_skips(s, i);
	buffer2 = assume_skips(s, i);
	if (buffer2.end > buffer.end)
	{
		free (buffer.array);
		buffer = buffer2;
	}
	else
		free (buffer2.array);
	return (buffer);
}

t_array	longest_increasing_subsequence(t_array s)
{
	t_array	store;
	t_array	buffer;
	int		i;

	store.array = (int *) malloc (sizeof (int) * s.end);
	i = s.end - 1;
	store.end = 0;
	while (i > 0)
	{
		buffer = decide_skip(s, i);
		if (buffer.end > store.end)
		{
			free (store.array);
			store = buffer;
		}
		else
			free (buffer.array);
		i--;
	}
	return (store);
}

//adapt this main some time to actually work
// int main(void)
// {
//    int array[] = {8, 7, 5, 3, 2, 4, 6, 1};
//    int end = 8;
//    int lis_end;
//    int *lis;
//    lis_end = 0;
//    lis = longest_increasing_subsequence(array, end, &lis_end);
//    // lis = assume_skips(array, end, &lis_end, end - 1);
//    printf("lis_end: %d\n", lis_end);
//    printf("Input:\n");
//    for (int i = 0; i < end; i++)
//        printf("%d ", array[i]);
//    printf("\nLongest increasing subsequence:\n");
//    for (int i = 0; i < lis_end; i++)
//        printf("%d ", lis[i]);
//    printf("\n");
//    return (0);
// }
