#include"push_swap.h"

//find smallest already exists, lest see if it works


int	biggest_ss(t_stack *first_a, int smallest)
{
	t_stack	*start;
	int		next;
	int		i;
	int		len;

	i = 0;
	start = first_a;
	while(i < first_a->size)
	{
		first_a = start;
		next = find_max(first_a);
		len = stack_len(first_a);
		while (len-- > 0)
		{
			if (first_a->data < next && first_a->data > smallest)
				next = first_a->data;
			first_a = first_a->next;
		}
		if (next == smallest)
			i++;
		smallest = next;
		i++;
	}
	first_a = start;
	return (smallest);
}

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

void	initialise_position(t_stack **first)
{
	t_stack	*temp;
	int		biggest;
	int		pos;

	temp = (*first);
	biggest = find_max(*first);
	pos = 1;
	while (temp)
	{
		if (temp->data == biggest && biggest != find_smallest(temp))
		{
			temp->position = pos++;
			biggest = next_small(*first, biggest);
		}
		if (biggest == find_smallest(temp) && temp->data == biggest)
		{
			temp->position = pos;
			break ;
		}
		temp = temp->next;
	}
}

int	up_or_down(t_stack *first, int pos)
{
	int	nodes;
	int	count;

	if (!first || !first->next || !first->previous)
		return (-1);
	nodes = stack_len(first);
	count = 0;
	while (count <= nodes)
	{
		if (first->position == pos)
			break ;
		first = first->next;
		count++;
	}
	if (count < (nodes / 2))
		return (1); // close to top
	else if (count > (nodes / 2))
		return (2);
	return (0);
}

int	find_pos(t_stack *first, int ss)
{
	t_stack *start;
	int	pos;
	int	nodes;

	start = first;
	if (!first || !first->next || !first->previous)
		return (-1);
	nodes = stack_len(first);
	pos = 1;
	while(first->next && first && first != start)
	{
		if (first->stack == ss)
			break;
		first = first->next;
		pos++;
	}
	if (pos < (nodes / 2))
		return (1); // close to top
	else if (pos >= (nodes / 2))
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
		else if ((*first_a)->sub_stack != ss && (*first_a)->next && find_pos(*first_a, ss) == 1)
			moves("ra", first_a, first_b);
		else if ((*first_a)->sub_stack != ss && (*first_a)->previous && find_pos(*first_a, ss) == 2)
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
		if((*first_b)->next->position == pos)
		{
			moves("sb", first_a, first_b);
			moves("pa", first_a, first_b);
			pos++;
		}
		if ((*first_b)->previous->position == pos)
		{
			moves("rrb", first_a, first_b);
			moves("pa", first_a, first_b);
			pos++;
		}
		if (up_or_down(*first_b, pos) == 1)
			moves("rb", first_a, first_b);
		if (up_or_down(*first_b, pos) == 2)
			moves("rrb", first_a, first_b);
		else 
			break ;
	}
}
