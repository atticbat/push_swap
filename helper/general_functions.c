/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:12:18 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/02 19:25:33 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicate(t_stacks *stack, int holder, int wc)
{
	int	i;

	i = stack->s[A].end - 1;
	while (i >= wc)
	{
		if (stack->s[A].array[i] == holder)
			return (0);
		i--;
	}
	return (1);
}

long int	ft_atoi_long(const char *str)
{
	long int	total;
	int			negate;

	total = 0;
	negate = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negate = negate * -1;
		str++;
	}
	if (!ft_isdigit(*str))
		return ((long int) MAX + 1);
	while (ft_isdigit(*str))
	{
		total = total * 10 + (*str - 48);
		str++;
		if (total * negate > 2147483647)
			return (total);
		if (total * negate < -2147483648)
			return (total);
	}
	if (*str != '\0')
		return ((long int) MAX + 1);
	return (total * negate);
}

void	supplement_bounds(t_stacks *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->s[A].end)
	{
		if (stack->s[A].array[i] <= stack->key[1] && stack->s[A].array[i] >= \
			stack->key[0])
			j++;
		i++;
	}
	if (j < (stack->key[1] - stack->key[0]) / 20)
		stack->key[1] += stack->highest / 20;
	i = 0;
	j = 0;
	while (i < stack->s[A].end)
	{
		if (stack->s[A].array[i] <= stack->key[3] && stack->s[A].array[i] >= \
			stack->key[2])
			j++;
		i++;
	}
	if (j < (stack->key[1] - stack->key[0]) / 20)
		stack->key[3] += stack->highest / 20;
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

t_array	ft_intdup(t_array s)
{
	int		i;
	t_array	result;

	result.array = (int *) malloc (sizeof(int) * s.end);
	result.end = s.end;
	i = 0;
	while (i < s.end)
	{
		result.array[i] = s.array[i];
		i++;
	}
	return (result);
}
