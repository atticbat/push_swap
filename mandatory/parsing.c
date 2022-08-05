/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:08:10 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/02 19:37:35 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_split(char *buffer)
{
	int		i;
	char	*allowed;

	allowed = (char *) malloc (sizeof(char) * 14);
	if (!allowed)
		return (0);
	ft_strlcpy(allowed, "0123456789+- ", 14);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (!ft_strchr(allowed, buffer[i]))
		{
			free(allowed);
			return (0);
		}
		i++;
	}
	free(allowed);
	return (1);
}

static int	initiate_parse(t_stacks *stack, char **argv, int argc)
{
	int	buffer;
	int	wc;
	int	i;

	i = 1;
	wc = 0;
	while (i < argc)
	{
		buffer = ft_word_count(argv[i], ' ');
		if (!buffer)
			return (0);
		wc += buffer;
		i++;
	}
	stack->s[A].array = (int *) malloc (sizeof (int) * wc);
	if (!stack->s[A].array)
		return (0);
	stack->s[A].end = wc;
	stack->s[B].array = (int *) malloc (sizeof (int) * wc);
	if (!stack->s[B].array)
		return (0);
	stack->s[B].end = 0;
	return (wc);
}

static int	free_all(char **buffer, int j)
{
	while (buffer[j] != NULL)
	{
		free (buffer[j]);
		j++;
	}
	free (buffer);
	return (0);
}

static int	fill_array(t_stacks *stack, char **argv, int wc, int i)
{
	int			j;
	char		**buffer;
	long int	holder;

	buffer = ft_split(argv[i], ' ');
	if (!buffer)
		return (0);
	j = 0;
	while (buffer[j] != NULL)
	{
		if (!check_split(buffer[j]))
			return (free_all(buffer, j));
		holder = ft_atoi_long(buffer[j]);
		if (holder <= MAX && holder >= MIN && \
			check_duplicate(stack, holder, wc))
			stack->s[A].array[wc - 1] = holder;
		else
			return (free_all(buffer, j));
		free (buffer[j]);
		wc--;
		j++;
	}
	free (buffer);
	return (1);
}

int	parse_input(t_stacks *stack, char **argv, int argc)
{
	int	i;
	int	wc;
	int	holder;

	wc = initiate_parse(stack, argv, argc);
	if (wc == 0)
		return (0);
	i = 1;
	while (i < argc)
	{
		holder = wc - fill_array(stack, argv, wc, i);
		if (wc == holder)
			return (0);
		else
			wc = holder;
		i++;
	}
	return (1);
}
