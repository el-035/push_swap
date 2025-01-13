#include"push_swap.h"

t_stack	*allocate_stack_a(char **input)
{
	t_stack	*first;
	t_stack	*stack;
	int		i;

	i = 0;
	first = new(atoi_ps(input[i++]), 'a', 0);
	if (!first)
		error(NULL, NULL);
	stack = new_last(first, atoi_ps(input[i++]), 'a');
	if (!stack)
		error(&first, NULL);
	first->size = 1;
	first->next = stack;
	stack->size = 1;
	while(input[i])
	{
		stack->next = new_last(stack, atoi_ps(input[i++]), 'a');
		if (!stack->next)
			error(&stack, NULL);
		stack->next->size = 1;
		stack = stack->next;
	}
	stack->next = first;
	first->previous = stack;
	return (first);
}

//still have 1 free to fix

void test_print(t_stack *stack, const char *name)
{
    t_stack *current;
    int count = 1;

    printf("Stack %s:\n", name);
    if (!stack)
    {
        printf("  [Empty]\n\n");
        return;
    }

    current = stack;
    do
    {//stack = %c, current = %p, previous = %p, next = %p
        printf("  Node %d: data = %d, size = %d\n",
               count++, current->data, current->position/* current->stack, (void *)current,
			   (void *)current->previous, (void *)current->next */);
        current = current->next;
    } while (current && current->data != stack->data);

    printf("\n");
}
void	ss_size(t_stack **first)
{
	t_stack	*current;
	int		len;
	int		size;

	len = stack_len(*first);
	if (len > 300)
		size = 44;
	else
		size = 18;
	current = *first;
	while (current->size == 1)
	{
		current->size = size;
		current = current->next;
	}
}
char	**check_input(char **arg)
{
	char	**input;

	if (!arg[2])
		input = ft_split(arg[1], ' ');
	else
	{
		input = arg;
		input++;
	}
	if (!input[1])
		exit(1);
	check_duplicates(input);
	return(input);
}

// what if input is only one number

int	main(int argc, char **argv)
{
	t_stack	*first_a;
	t_stack	*first_b;
	char	**input;

	if (argc < 2)
		return (0);
	input = check_input(argv);
	first_a = allocate_stack_a(input);
	first_b = NULL;
	ss_size(&first_a);
	if (is_sorted(first_a))
		return (free_stack(&first_a), 0);
	if (stack_len(first_a) <= 5)
		three_five(&first_a, &first_b);
	else
	{
		half_sort_b(&first_a, &first_b);
		initialise_position(&first_b);
		back_to_a(&first_a, &first_b);
	}
	/* test_print(first_a, "a");
	test_print(first_b, "b"); */
	free_stack(&first_a);
	free_stack(&first_b);
}
