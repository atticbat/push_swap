/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glossary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:54:09 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/01 23:26:23 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	swaps(t_stacks *stack, char *buffer)
{
	if (!ft_strncmp(buffer, "sb\n", 3))
		swap(stack, B);
	else if (!ft_strncmp(buffer, "sa\n", 3))
		swap(stack, A);
	else if (!ft_strncmp(buffer, "ss\n", 3))
	{
		swap(stack, A);
		swap(stack, B);
	}
	else
		return (0);
	return (1);
}

static int	rotates(t_stacks *stack, char *buffer)
{
	if (!ft_strncmp(buffer, "ra\n", 3))
		rotate(stack, A);
	else if (!ft_strncmp(buffer, "rra\n", 4))
		reverse_rotate(stack, A);
	else if (!ft_strncmp(buffer, "rb\n", 3))
		rotate(stack, B);
	else if (!ft_strncmp(buffer, "rrb\n", 4))
		reverse_rotate(stack, B);
	else if (!ft_strncmp(buffer, "rrr\n", 4))
	{
		reverse_rotate(stack, A);
		reverse_rotate(stack, B);
	}
	else if (!ft_strncmp(buffer, "rr\n", 3))
	{
		rotate(stack, A);
		rotate(stack, B);
	}
	else
		return (0);
	return (1);
}

static int	pushes(t_stacks *stack, char *buffer)
{
	if (!ft_strncmp(buffer, "pa\n", 3))
		push_silent(stack, A);
	else if (!ft_strncmp(buffer, "pb\n", 3))
		push_silent(stack, B);
	else
		return (0);
	return (1);
}

int	move_glossary(t_stacks *stack, char *buffer)
{
	if (buffer[0] == 's')
		return (swaps(stack, buffer));
	else if (buffer[0] == 'r')
		return (rotates(stack, buffer));
	else if (buffer[0] == 'p')
		return (pushes(stack, buffer));
	else
		return (0);
}
