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

t_stack	*new(int data, char stack, int sub_stack, char **input)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return (error(NULL, NULL, input), NULL);
	new->data = data;
	new->stack = stack;
	new->sub_stack = sub_stack;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*new_not_free(t_stack *from)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return (error(&from, NULL, NULL), NULL);
	new->data = from->data;
	new->stack = from->stack;
	new->sub_stack = from->sub_stack;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*new_last(t_stack *prev, int data, char stack, char **input)
{
	t_stack	*last;

	last = (t_stack *) malloc(sizeof(t_stack));
	if (!last)
		return (error(&prev, NULL, input), NULL);
	last->data = data;
	last->stack = stack;
	last->previous = prev;
	last->next = NULL;
	return (last);
}

t_stack	*new_first(t_stack **first, t_stack **from)
{
	t_stack	*add;

	add = (t_stack *) malloc(sizeof(t_stack));
	if (!add)
		return (error(first, from, NULL), NULL);
	add->data = (*from)->data;
	add->stack = (*from)->stack;
	add->sub_stack = (*from)->sub_stack;
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
