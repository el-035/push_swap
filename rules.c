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
	t_stack	*temp;

	if (!from || !*from)
		return ;
	if (!*to)
		*to = new_not_free(*from);
	else
		*to = new_first(to, from);
	if (!*to)
		error(from, to, NULL);
	temp = *from;
	if (!(*from)->next)
		return (free_stack(from));
	(*from) = (*from)->next;
	(*from)->previous = temp->previous;
	temp->previous->next = (*from);
	if ((*from)->next == (*from))
	{
		(*from)->next = NULL;
		(*from)->previous = NULL;
	}
	free(temp);
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
