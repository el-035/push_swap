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

/* void	initialise_ss(t_stack **first)
{
	static int	ss_count = 1;
	

} */

/* void	lets_sort(t_stack **first_a, t_stack **first_b)
{
	int	sub_stack;
	int	nodes;
	int	smallest;

	nodes = stack_len(*first_a);
	sub_stack = nodes / 10;
	smallest = find_smallest(*first_a);
	

} */