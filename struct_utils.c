#include "push_swap.h"

t_stack	*new(int data, char stack)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return NULL;	//free + error
	new->data = data;
	new->stack = stack;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*new_last(t_stack *prev, int data, char stack)
{
	t_stack	*last;

	last = (t_stack *) malloc(sizeof(t_stack));
	if (!last)
		return NULL;	//free + error
	last->data = data;
	last->stack = stack;
	last->previous = prev;
	last->next = NULL;
	return (last);
}

t_stack	*new_first(t_stack **first, int data, char stack)
{
	t_stack	*add;

	if (!*first)
		return(new(data, stack));
	add = (t_stack *) malloc(sizeof(t_stack));
	if (!add)
		return NULL;
	add->data = data;
	add->stack = stack;
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
