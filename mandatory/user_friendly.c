/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_friendly.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:00:13 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/17 00:49:59 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	r(t_stacks *stack, t_current_stack s)
{
	rotate(stack, s);
	if (s == A)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	re(t_stacks *stack, t_current_stack s)
{
	reverse_rotate(stack, s);
	if (s == A)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

void	print_all(t_stacks *stack)
{
	int	i;

	if (stack->s[0].end > stack->s[1].end)
		i = stack->s[0].end - 1;
	else
		i = stack->s[1].end - 1;
	ft_printf("---------------------------------\n");
	ft_printf("|stack:\t| a\t|\t| b\t|\n---------------------------------\n");
	while (i >= 0)
	{
		if (i < stack->s[0].end)
			ft_printf("|\t|% 2d\t|", stack->s[0].array[i]);
		else
			ft_printf("|\t|\t|");
		if (i < stack->s[1].end)
			ft_printf("\t|% 2d\t|", stack->s[1].array[i]);
		else
			ft_printf("\t|\t|");
		ft_printf("\n");
		i--;
	}
	ft_printf("---------------------------------\n");
}
