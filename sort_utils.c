/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:36:19 by efittant          #+#    #+#             */
/*   Updated: 2025/01/14 22:36:23 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_ss(t_stack *first_a, int smallest)
{
	t_stack	*start;
	int		next;
	int		i;
	int		len;

	i = 0;
	start = first_a;
	while (i < first_a->size)
	{
		first_a = start;
		next = find_max(first_a);
		len = stack_len(first_a);
		while (len-- > 0)
		{
			if (first_a->data < next && first_a->data > smallest)
				next = first_a->data;
			first_a = first_a->next;
		}
		if (next == smallest)
			i++;
		smallest = next;
		i++;
	}
	first_a = start;
	return (smallest);
}

int	top_bottom(t_stack *first, int target)
{
	int		nodes;
	int		count;

	if (!first || !first->next || !first->previous)
		return (-1);
	count = 0;
	nodes = stack_len(first);
	while (count <= nodes)
	{
		if (first->position == target)
			break ;
		first = first->next;
		count++;
	}
	if (count < (nodes / 2))
		return (1);
	else if (count >= (nodes / 2))
		return (2);
	return (0);
}

int	find_smallest(t_stack *first)
{
	int	smallest;
	int	start;

	start = first->data;
	smallest = first->data;
	first = first->next;
	while (first->data != start)
	{
		if (first->data < smallest)
			smallest = first->data;
		first = first->next;
	}
	return (smallest);
}
