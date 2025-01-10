#include "push_swap.h"

int	find_max(t_stack *first)
{
	int	max;
	int	start;

	start = first->data;
	max = first->data;
	first = first->next;
	while (first->data != start)
	{
		if (first->data > max)
			max = first->data;
		first = first->next;
	}
	return (max);
}
