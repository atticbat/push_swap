/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 04:09:06 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/02 20:30:37 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

# define MAX 2147483647
# define MIN -2147483648

typedef enum t_current_stack { A = 0, B = 1 }	t_current_stack;

typedef struct s_array
{
	int	*array;
	int	end;
}	t_array;

typedef struct s_stacks
{
	t_array	s[2];
	int		lowest;
	int		second_lowest;
	int		highest;
	int		groups;
	int		seek;
	int		start_number;
	int		end_number;
	int		key[4];
	int		moves[3];
	int		oscillation;
}	t_stacks;

void		push(t_stacks *stack, t_current_stack to);
void		re(t_stacks *stack, t_current_stack s);
void		r(t_stacks *stack, t_current_stack s);
void		rrr(t_stacks *stack);
void		rr(t_stacks *stack);
void		rotate(t_stacks *stack, t_current_stack s);
void		reverse_rotate(t_stacks *stack, t_current_stack s);
void		ss(t_stacks *stack);
void		s(t_stacks *stack, t_current_stack s);
void		reindex(t_stacks *stack);
void		print_all(t_stacks *stack);
void		insertion_sort(t_stacks *stack);
int			check_continuity(t_stacks *stack);
int			second_lowest_operations(t_stacks *stack);
void		adjust_second_lowest_index(t_stacks *stack);
int			check_gap_condition(t_stacks *stack);
void		bring_up_lowest(t_stacks *stack);
void		parallel_operations(t_stacks *stack);
void		lowest_operations(t_stacks *stack);
int			check_sorted_a(int *stack, int end);
int			find_lowest(t_array s);
int			find_highest(t_array s);
int			ft_abs(int num);
t_array		ft_intdup(t_array s);
int			find_index(t_stacks *stack, int to_find);
void		find_lowest_index(t_stacks *stack);
int			find_lowest_index_array(long int *stack, int end);
void		hardcode_three_operations(t_stacks *stack);
void		push_all(t_stacks *stack);
int			get_move(t_stacks *stack);
int			get_weight(t_stacks *stack, int **moves, int *overlap);
int			find_path_to_top(t_stacks *stack, int idx);
void		reinsertion_sort(t_stacks *stack);
int			find_insertion_point(t_stacks *stack, int idx);
t_array		longest_increasing_subsequence(t_array s);
int			parse_input(t_stacks *stack, char **argv, int argc);
void		supplement_bounds(t_stacks *stack);
long int	ft_atoi_long(const char *str);
int			check_duplicate(t_stacks *stack, int holder, int wc);
int			check_sorted_array(int top, t_array sorted);

#endif
