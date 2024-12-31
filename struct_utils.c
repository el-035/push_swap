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

	add = (t_stack *) malloc(sizeof(t_stack));
	if (!add)
		return NULL;
	if (!first)
	add->data = data;
	add->stack = stack;
	add->previous = (*first)->previous;
	(*first)->previous = add;
	add->next = (*first);
	return (add);
}