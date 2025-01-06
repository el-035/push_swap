#include "push_swap.h"

void	swap(t_stack *first)
{
	int	temp;

	if (!first || !first->next)
		return ;
	temp = first->data;
	first->data = first->next->data;
	first->next->data = temp;
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
	*to = new_first(to, (*from)->data, stack);
	if (!*to)
		error(from, to);
	temp = *from;
	if (!(*from)->next)
		return (*from = NULL, free(*from));
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
