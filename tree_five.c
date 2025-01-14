#include"push_swap.h"

void	sort_three(t_stack **first_a, t_stack **first_b)
{
	if (is_sorted(*first_a))
		return ;
	if (biggest(*first_a) == 3)
		moves("sa", first_a, first_b);
	else if (biggest(*first_a) == 2 && (*first_a)->data < (*first_a)->previous->data)
	{
		moves("sa", first_a, first_b);
		moves("ra", first_a, first_b);
	}
	else if (biggest(*first_a) == 2 && (*first_a)->data > (*first_a)->previous->data)
		moves("rra", first_a, first_b);
	else if (biggest(*first_a) == 1 && (*first_a)->next->data < (*first_a)->previous->data)
		moves("ra", first_a, first_b);
	else if (biggest(*first_a) == 1 && (*first_a)->next->data > (*first_a)->previous->data)
	{
		moves("ra", first_a, first_b);
		moves("sa", first_a, first_b);
	}
}
void	push_smallest(t_stack **first_a, t_stack **first_b)
{
	int		count;
	int		smallest;
	t_stack	*temp;

	temp = *first_a;
	smallest = find_smallest(*first_a);
	count = 0;
	while (temp->data != smallest)
	{
		count++;
		temp = temp->next;
	}
	if (count < 3)
	{
		while ((*first_a)->data != smallest)
			moves("ra", first_a, first_b);
	}
	else
	{
		while ((*first_a)->data != smallest)
			moves("rra", first_a, first_b);
	}
	moves("pb", first_a, first_b);
}

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

void	three_five(t_stack **first_a, t_stack **first_b)
{
	int	len;

	len = stack_len(*first_a);
	if (is_sorted(*first_a) == 1)
		return;
	else if (len == 2 && is_sorted(*first_a) == 0)
		moves("sa", first_a, first_b);
	else if (len == 3)
		sort_three(first_a, first_b);
	if 	(len == 4 || len == 5)
	{
		if (len == 5)
			push_smallest(first_a, first_b);
		push_smallest(first_a, first_b);
		sort_three(first_a, first_b);
		if (len == 5)
			moves("pa", first_a, first_b);
		moves("pa", first_a, first_b);
	}
}
