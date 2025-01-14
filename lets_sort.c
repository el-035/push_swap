/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:49:41 by efittant          #+#    #+#             */
/*   Updated: 2025/01/14 18:49:43 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_ss(t_stack *first)
{
	int		ss_count;
	int		ss_max;
	int		len;
	int		min;
	int		tot_ss;

	tot_ss = stack_len(first) / (first)->size;
	if (stack_len(first) % (first)->size != 0)
		tot_ss = stack_len(first) / (first)->size + 1;
	min = find_smallest(first);
	ss_count = 1;
	ss_max = biggest_ss((first), min);
	while (ss_count <= tot_ss)
	{
		len = stack_len(first);
		while (len-- > 0)
		{
			if ((first)->data <= ss_max && (first)->data >= min)
				(first)->sub_stack = ss_count;
			(first) = (first)->next;
		}
		ss_count++;
		min = ss_max;
		ss_max = biggest_ss((first), min);
	}
}

int	next_small(t_stack *first, int biggest)
{
	t_stack	*temp;
	int		next;

	temp = first;
	next = find_smallest(first);
	while (1)
	{
		if (first->data > next && first->data < biggest)
			next = first->data;
		first = first->next;
		if (temp == first)
			break ;
	}
	return (next);
}

void	half_sort_b(t_stack **first_a, t_stack **first_b)
{
	int	size;
	int	ss;
	int	n;

	ss = 1;
	n = 0;
	size = (*first_a)->size;
	while (*first_a)
	{
		if ((*first_a)->sub_stack == ss && *first_a)
		{
			moves("pb", first_a, first_b);
			n++;
		}
		else if ((*first_a)->sub_stack != ss && (*first_a)->next)
			moves("ra", first_a, first_b);
		if (n == size)
		{
			n = 0;
			ss++;
		}
	}
}

void	sort_a(t_stack **first_a, t_stack **first_b)
{
	int	pos;
	int	len;

	pos = 1;
	len = stack_len(*first_b);
	while (first_b && pos <= len)
		pos = back_to_a(first_a, first_b, pos);
}

int	back_to_a(t_stack **first_a, t_stack **first_b, int pos)
{
	if ((*first_b)->position == pos)
	{
		moves("pa", first_a, first_b);
		pos++;
	}
	else if ((*first_b)->next->position == pos)
	{
		moves("sb", first_a, first_b);
		moves("pa", first_a, first_b);
		pos++;
	}
	else if ((*first_b)->previous->position == pos)
	{
		moves("rrb", first_a, first_b);
		moves("pa", first_a, first_b);
		pos++;
	}
	else if ((*first_b)->next != (*first_b)->previous && \
	top_bottom(*first_b, pos) == 1)
		moves("rb", first_a, first_b);
	else if ((*first_b)->next != (*first_b)->previous && \
	top_bottom(*first_b, pos) == 2)
		moves("rrb", first_a, first_b);
	return (pos);
}
