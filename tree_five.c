#include"push_swap.h"

void	sort_three(t_stack **first_a, t_stack **first_b)
{
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
		moves("ra", first_a, first_b);
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

void	sort_five(t_stack **first_a, t_stack **first_b, int len)
{
	if (len == 5)
		push_smallest(first_a, first_b);
	push_smallest(first_a, first_b);
	sort_three(first_a, first_b);
	if (len == 5)
		moves("pa", first_a, first_b);
	moves("pa", first_a, first_b);
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
		sort_five(first_a, first_b, len);
}
