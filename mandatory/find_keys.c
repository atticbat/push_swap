/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:05:01 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/28 05:04:16 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_lowest(t_array s)
{
	int	lowest;
	int	i;

	i = s.end - 1;
	lowest = s.array[i];
	while (i >= 0)
	{
		if (s.array[i] < lowest)
			lowest = s.array[i];
		i--;
	}
	return (lowest);
}

int	find_highest(t_array s)
{
	int	highest;
	int	i;

	i = s.end - 1;
	highest = s.array[i];
	while (i >= 0)
	{
		if (s.array[i] > highest)
			highest = s.array[i];
		i--;
	}
	return (highest);
}
