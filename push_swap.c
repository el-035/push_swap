//check input
	//no duplicates
	//int
//add data to the node
//rules
//

#include"push_swap.h"

void	check_duplicates(char **input)
{
	int	i;
	int	j;

	i = 0;
	while(input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (atoi_ps(input[i]) == atoi_ps(input[j]))
				error(NULL, NULL);
			j++;
		}
		i++;
	}
}

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

void test_print_combined(t_stack *stack_a, t_stack *stack_b)
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
}

int	main(int argc, char **argv)
{
	t_stack	*first_a;
	t_stack	*first_b;

	if (argc <= 2)	//???
		return (0);
	check_duplicates(argv);
	first_a = allocate_stack_a(argv);
	first_b = NULL;
	
	free_stack(&first_a);
	free_stack(&first_b);
}

