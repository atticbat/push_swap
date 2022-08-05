/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:29:38 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/05 18:47:39 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	free_table(char **table, int len)
{
	int	i;

	i = 0;
	if (table)
	{
		while (i < len)
		{
			if (table[i])
				free (table[i]);
			i++;
		}
		free (table);
	}
	return (0);
}

static char	**ft_append(char **table, char *str, int length)
{
	char	**out;

	out = (char **) malloc (sizeof (char *) * (length + 1));
	out[length] = str;
	while (length - 1 > 0)
	{
		out[length - 1] = ft_strdup(table[length - 1]);
		free(table[length - 1]);
		length--;
	}
	out[0] = ft_strdup(table[0]);
	free(table[0]);
	free(table);
	table = NULL;
	return (out);
}

static char	**init_table(void)
{
	char	**table;
	int		len;

	len = 1;
	table = (char **) malloc (sizeof (char *) * len);
	if (!table)
		return (NULL);
	table[0] = get_next_line(0);
	if (!table[0])
	{
		free_table(table, len);
		return (NULL);
	}
	return (table);
}

static int	make_moves(t_stacks *stack, char **table, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!move_glossary(stack, table[i]))
		{
			free_table(table, len);
			return (0);
		}
		i++;
	}
	free_table(table, len);
	return (1);
}

int	get_lines(t_stacks *stack)
{
	char	*buffer;
	char	**table;
	int		len;

	len = 1;
	table = init_table();
	if (!table)
		return (1);
	while (1)
	{
		buffer = get_next_line(0);
		if (!buffer)
			break ;
		len++;
		table = ft_append(table, buffer, len - 1);
	}
	return (make_moves(stack, table, len));
}
