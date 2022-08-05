/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:34:27 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/17 00:07:37 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stacks *stack, t_current_stack s)
{
	int	i;
	int	buffer;

	if (stack->s[s].end < 2)
		return ;
	i = 0;
	while (i < stack->s[s].end - 1)
	{
		buffer = stack->s[s].array[i + 1];
		stack->s[s].array[i + 1] = stack->s[s].array[i];
		stack->s[s].array[i] = buffer;
		i++;
	}
}

void	rotate(t_stacks *stack, t_current_stack s)
{
	int	i;
	int	buffer;

	if (stack->s[s].end < 2)
		return ;
	i = stack->s[s].end - 1;
	while (i > 0)
	{
		buffer = stack->s[s].array[i - 1];
		stack->s[s].array[i - 1] = stack->s[s].array[i];
		stack->s[s].array[i] = buffer;
		i--;
	}
}

void	rr(t_stacks *stack)
{
	rotate(stack, A);
	rotate(stack, B);
	ft_printf("rr\n");
}

void	rrr(t_stacks *stack)
{
	reverse_rotate(stack, A);
	reverse_rotate(stack, B);
	ft_printf("rrr\n");
}
