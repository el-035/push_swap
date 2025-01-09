#include"push_swap.h"

int	biggest(t_stack	*first)
{
	int	start;
	int	second;
	int	last;

	if (!first)
		return (-1);
	if (!first->next || !first->previous)
		return (1);
	start = first->data;
	second = first->next->data;
	last = first->previous->data;
	if (start > second && start > last)
		return (1);
	else if (second > start && second > last)
		return (2);
	else if (last > start && last > second)
		return (3);
	return (0);
}

int	up_down(t_stack *first)
{
	int	nodes;
	int	count;
	int	data;

	if (!first || !first->next || !first->previous)
		return (-1);
	nodes = stack_len(first);
	data  = first->data;
	first = first->next;
	count = 0;
	while (first->data < data)
	{
		count++;
		first = first->next;
	}
	if (count > (nodes / 2))
		return (1);	//closer to bottom, rr
	else
		return (2); //closer to top, r
	return (count);
}
void	push_biggest_a(t_stack **first_a, t_stack **first_b)
{
	if (biggest(*first_a) == 1)
	{
		if (*first_b && (*first_b)->next && (*first_b)->data > (*first_b)->next->data)
    		moves("sb", first_a, first_b);
		moves("pb", first_a, first_b);
	}
	else if (biggest(*first_a) == 2)
	{
		if (*first_b && (*first_b)->next && (*first_b)->data > (*first_b)->next->data)
			moves("ss", first_a, first_b);
		else
			moves("sa", first_a, first_b);
		moves("pb", first_a, first_b);
	}
	else if (biggest(*first_a) == 3)
	{
		if (*first_b && (*first_b)->next && (*first_b)->data > (*first_b)->next->data)
			moves("sb", first_a, first_b);
		moves("rra", first_a, first_b);
		moves("pb", first_a, first_b);
	}
}

void	order_b(t_stack **first_a, t_stack **first_b)
{
	if ((*first_b)->data > (*first_b)->previous->data)
		moves("rb", first_a, first_b);
	else if(up_down(*first_b) == 1)		//if number is closer to bottom
	{									//reverse rotate and swap then when correct position rotate
		while ((*first_b)->data < (*first_b)->previous->data)
		{
			moves("rrb", first_a, first_b);
			moves("sb", first_a, first_b);
		}
		while (is_sorted(*first_b) == 0)
			moves("rb", first_a, first_b);
	}
	else if(up_down(*first_b) == 2)		//if number is closer to top
	{									//rotate and swap then when correct position rev rotate
		while ((*first_b)->data > (*first_b)->next->data)
		{
			moves("sb", first_a, first_b);
			moves("rb", first_a, first_b);
		}
		while (is_sorted(*first_b) == 0)
			moves("rrb", first_a, first_b);
	}
}

t_stack	*algorithm(t_stack **first_a, t_stack **first_b)
{
	if (is_sorted(*first_a) == 1)
		return (*first_a);
	moves("pb", first_a, first_b);
	moves("pb", first_a, first_b);

	while(*first_a != NULL || is_sorted(*first_b) == 0)
	{
		if (*first_a)
			push_biggest_a(first_a, first_b);
		if (*first_b && is_sorted(*first_b) == 0)
			order_b(first_a, first_b);
	}
	return(*first_b);
}
