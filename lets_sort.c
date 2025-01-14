#include"push_swap.h"



void	initialise_ss(t_stack **first)
{
	int		ss_count;
	int		ss_max;
	int		len;
	int		min;
	int		tot_ss;

	tot_ss = stack_len(*first) / (*first)->size;
	if (stack_len(*first) % (*first)->size != 0)
		tot_ss = stack_len(*first) / (*first)->size + 1;
	min = find_smallest(*first);
	ss_count = 1;
	ss_max = biggest_ss((*first), min);
	while (ss_count <= tot_ss)
	{
		len = stack_len(*first);
		while (len-- > 0)
		{
			if ((*first)->data <= ss_max && (*first)->data >= min)
				(*first)->sub_stack = ss_count;
			(*first) = (*first)->next;
		}
		ss_count++;
		min = ss_max;
		ss_max = biggest_ss((*first), min);
	}
}

int	next_small(t_stack *first, int biggest)
{
	t_stack	*temp;
	int		next;

	temp = first;
	next = find_smallest(first);
	while (1)
	{
		if (first->data > next && first->data < biggest)
			next = first->data;
		first = first->next;
		if (temp == first)
			break ;
	}
	return (next);
}

int	top_bottom(t_stack *first, int target, int flag)
{
	int	nodes;
	int	count;

	if (!first || !first->next || !first->previous)
		return (-1);
	count = flag;
	nodes = stack_len(first);
	while (count <= nodes)
	{
		if (flag == 0 && first->position == target)
			break ;
		else if (flag == 1 && first->sub_stack == target)
			break ;
		first = first->next;
		count++;
	}
	if (count < (nodes / 2))
		return (1); // close to top
	else if (count >= (nodes / 2))
		return (2);
	return (0);
}

void	half_sort_b(t_stack **first_a, t_stack **first_b)
{
	int	size;
	int	ss;
	int	n;

	ss = 1;
	n = 0;
	size = (*first_a)->size;
	initialise_ss(first_a);
	while (*first_a)
	{
		if ((*first_a)->sub_stack == ss && *first_a)
		{
			moves("pb", first_a, first_b);
			n++;
		}
		else if ((*first_a)->sub_stack != ss && (*first_a)->next && top_bottom(*first_a, ss, 1) == 1)
			moves("ra", first_a, first_b);
		else if ((*first_a)->sub_stack != ss && (*first_a)->previous && top_bottom(*first_a, ss, 1) == 2)
			moves("rra", first_a, first_b);
		if (n == size)
		{
			n = 0;
			ss++;
		}
	}
}

void	back_to_a(t_stack **first_a, t_stack **first_b)
{
	int	pos;

	pos = 1;
	while (*first_b)
	{
		if ((*first_b)->position == pos)
		{
			moves("pa", first_a, first_b);
			pos++;
		}
		else if((*first_b)->next->position == pos)
		{
			moves("sb", first_a, first_b);
			moves("pa", first_a, first_b);
			pos++;
		}
		else if ((*first_b)->previous->position == pos)
		{
			moves("rrb", first_a, first_b);
			moves("pa", first_a, first_b);
			pos++;
		}
		else if ((*first_b)->next != (*first_b)->previous && top_bottom(*first_b, pos, 0) == 1)
			moves("rb", first_a, first_b);
		else if ((*first_b)->next != (*first_b)->previous && top_bottom(*first_b, pos, 0) == 2)
			moves("rrb", first_a, first_b);
	}
}
