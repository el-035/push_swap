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
