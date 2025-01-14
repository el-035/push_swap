/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:50:43 by efittant          #+#    #+#             */
/*   Updated: 2025/01/14 18:50:45 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new(int data, char stack, int sub_stack)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return (error(NULL, NULL, NULL), NULL);
	new->data = data;
	new->stack = stack;
	new->sub_stack = sub_stack;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*new_last(t_stack *prev, int data, char stack)
{
	t_stack	*last;

	last = (t_stack *) malloc(sizeof(t_stack));
	if (!last)
		return (error(&prev, NULL, NULL), NULL);
	last->data = data;
	last->stack = stack;
	last->previous = prev;
	last->next = NULL;
	return (last);
}

t_stack	*new_first(t_stack **first, int data, char stack, int sub_stack)
{
	t_stack	*add;

	if (!*first)
		return (new(data, stack, sub_stack));
	add = (t_stack *) malloc(sizeof(t_stack));
	if (!add)
		return (error(first, NULL, NULL), NULL);
	add->data = data;
	add->stack = stack;
	add->sub_stack = sub_stack;
	if (*first && !(*first)->next)
	{
		add->previous = (*first);
		add->next = (*first);
		(*first)->next = add;
		(*first)->previous = add;
	}
	else
	{
		add->previous = (*first)->previous;
		add->next = (*first);
		(*first)->previous->next = add;
		(*first)->previous = add;
	}
	return (add);
}

int	stack_len(t_stack *first)
{
	int	nodes;
	int	data;

	if (!first)
		return (0);
	nodes = 1;
	if (!first->next)
		return (nodes);
	data = first->data;
	first = first->next;
	while (first->data != data)
	{
		nodes++;
		first = first->next;
	}
	return (nodes);
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
