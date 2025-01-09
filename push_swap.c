#include"push_swap.h"

//./push_swap 1 -1 0 2 3 4 6 7 	why error
//./push_swap 1 0 2 3 4 6 7		why error
//./push_swap 1 -1 0 2 3 4 6 7

t_stack	*allocate_stack_a(char **input)
{
	t_stack	*first;
	t_stack	*stack;
	int		i;

	i = 1;
	first = new(atoi_ps(input[i++]), 'a');
	if (!first)
		error(NULL, NULL);
	stack = new_last(first, atoi_ps(input[i++]), 'a');
	if (!stack)
		error(&first, NULL);
	first->next = stack;
	while(input[i])
	{
		stack->next = new_last(stack, atoi_ps(input[i++]), 'a');
		if (!stack->next)
		{
			free(first);
			error(&stack, NULL);
		}
		stack = stack->next;
	}
	stack->next = first;
	first->previous = stack;
	return (first);
}


int	main(int argc, char **argv)
{
	t_stack	*first_a;
	t_stack	*first_b;

	if (argc <= 2)
		return (0);
	check_duplicates(argv);
	first_a = allocate_stack_a(argv);
	first_b = NULL;
	if (stack_len(first_a) <= 5)
		three_five(&first_a, &first_b);

	/* else
		algorithm(&first_a, &first_b);
	//test_print_combined(first_a, first_b);
	if (is_sorted(first_b) == 1)
		ft_printf("COOL"); */
	free_stack(&first_a);
	free_stack(&first_b);
}
