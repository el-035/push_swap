#include"push_swap.h"

/* void test_print_combined(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *current_a = stack_a;
    t_stack *current_b = stack_b;
    int count_a = 0;
    int count_b = 0;

    printf("Stack a:              Stack b:\n");
    // Loop until both stacks are fully printed
    while (current_a || current_b)
    {
        if (current_a)
        {
            printf("%-22d", current_a->data); // Print data from stack_a, aligned to 22 spaces
            current_a = current_a->next;
            count_a++;
            if (current_a && current_a->data == stack_a->data)
                current_a = NULL; // Stop at the circular loop
        }
        else
            printf("%-22s", ""); // Empty space for stack_a
        if (current_b)
        {
            printf("%d", current_b->data); // Print data from stack_b
            current_b = current_b->next;
            count_b++;
            if (current_b && current_b->data == stack_b->data)
                current_b = NULL; // Stop at the circular loop
        }
        printf("\n");
    }
    printf("\n");
} */

int	biggest(t_stack	*first)
{
	int	start;
	int	second;
	int	last;

	if (!first || !first->next || !first->previous)
		return (-1);
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
		if (*first_b && (*first_b) == 0)
		{
			if ((*first_b)->data > (*first_b)->previous->data)
				moves("rb", first_a, first_b);
			else if(up_down(*first_b) == 1)		//if number is closer to bottom
			{									//reverse rotate and swap then when correct position rotate
				while ((*first_b)->data < (*first_b)->next->data && (*first_b)->data > (*first_b)->previous->data)
				{
					moves("rrb", first_a, first_b);
					moves("sb", first_a, first_b);
				}
				while (is_sorted(*first_b) == 0)
					moves("rb", first_a, first_b);
			}
			else if(up_down(*first_b) == 2)		//if number is closer to top
			{									//rotate and swap then when correct position rev rotate
				while ((*first_b)->data < (*first_b)->next->data && (*first_b)->data > (*first_b)->previous->data)
				{
					moves("sb", first_a, first_b);
					moves("rb", first_a, first_b);
				}
				while (is_sorted(*first_b) == 0)
					moves("rrb", first_a, first_b);
			}
		}
	}
	//test_print_combined(*first_a, *first_b);
	return(*first_b);
}
