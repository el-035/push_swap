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
	while(i < 10)
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

	min = find_smallest(*first);
	ss_count = 1;
	ss_max = biggest_ss((*first), min);
	while (ss_count <= (stack_len(*first) / 10) + 1)
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

//put position of 

void	initialise_position(t_stack **first)
{
	int	pos;

}

void	half_sort_b(t_stack **first_a, t_stack **first_b)
{
	int	i;
	int	n;

	initialise_ss(first_a);
	i = 1;
	n = 0;
	while (*first_a && first_a)
	{
		if ((*first_a)->sub_stack == i)
		{
			moves("pb", first_a, first_b);
			n++;
		}
		else
			moves("ra", first_a, first_b);
		if (n == 10)
		{
			n = 0;
			i++;
		}
	}
}

void	lets_sort(t_stack **first_a, t_stack **first_b)
{
	int	ss_len;

	ss_len = stack_len(*first_a) % 10;
	half_sort_b(first_a, first_b);


}