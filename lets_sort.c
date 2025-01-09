#include"push_swap.h"

//find smallest already exists, lest see if it works

int	biggest_ss(t_stack *first_a, int smallest)
{
	t_stack	*start;
	int		next;
	int		i;
	int		len;

	i = 1;
	start = first_a;
	while(i < 10)
	{
		next = 2147483647;
		first_a = start;
		len = stack_len(first_a);
		while (len-- > 0)
		{
			if (first_a->data < next && first_a->data > smallest)
				next = first_a->data;
			first_a = first_a->next;
		}
		smallest = next;
		i++;
	}
	return (smallest);
}

void	initialise_ss(t_stack **first)
{
	int		ss_count;
	int		ss_max;
	int		len;

	ss_count = 1;
	len = stack_len(*first);
	ss_max = biggest_ss((*first), find_smallest(*first));
	while (len-- > 0)
	{
		if ((*first)->data >= ss_max && (*first)->data <= find_smallest(*first))
			(*first)->sub_stack = ss_count;
		(*first) = (*first)->next;
	}
	while (ss_count <= stack_len(*first) / 10)
	{
		ss_count++;
		len = stack_len(*first);
		while (len-- > 0)
		{
			if ((*first)->data >= ss_max && (*first)->data <= find_smallest(*first))
				(*first)->sub_stack = ss_count;
			(*first) = (*first)->next;
		}
		
	}

}

/* void	lets_sort(t_stack **first_a, t_stack **first_b)
{
	int	sub_stack;
	int	nodes;
	int	smallest;

	nodes = stack_len(*first_a);
	sub_stack = nodes / 10;
	smallest = find_smallest(*first_a);
	

} */