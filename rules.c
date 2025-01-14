/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:50:34 by efittant          #+#    #+#             */
/*   Updated: 2025/01/14 18:50:36 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *first)
{
	int	temp;

	if (!first || !first->next)
		return ;
	temp = first->data;
	first->data = first->next->data;
	first->next->data = temp;
	temp = first->position;
	first->position = first->next->position;
	first->next->position = temp;
}

void	push(t_stack **from, t_stack **to)
{
	char	stack;
	t_stack	*temp;

	stack = 'a';
	if (!from || !*from)
		return ;
	if ((*from)->stack == 'a')
		stack = 'b';
	*to = new_first(to, (*from)->data, stack, (*from)->sub_stack);
	if (!*to)
		error(from, to, NULL);
	temp = *from;
	if (!(*from)->next)
		return (*from = NULL, free_stack(from));
	(*from) = (*from)->next;
	(*from)->previous = temp->previous;
	temp->previous->next = (*from);
	if ((*from)->next == (*from))
	{
		(*from)->next = NULL;
		(*from)->previous = NULL;
	}
	free(temp);
	temp = NULL;
}

t_stack	*rotate(t_stack *first)
{
	if (!first || !first->next)
		return (first);
	return (first->next);
}

t_stack	*rev_rot(t_stack *first)
{
	if (!first || !first->next)
		return (first);
	return (first->previous);
}
