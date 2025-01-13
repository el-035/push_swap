#include"push_swap.h"

t_stack	*allocate_stack_a(char **input)
{
	t_stack	*first;
	t_stack	*stack;
	int		i;

	i = 0;
	first = new(atoi_ps(input[i++], 0), 'a', 0);
	if (!first)
		error(NULL, NULL, NULL);
	stack = new_last(first, atoi_ps(input[i++], 0), 'a');
	if (!stack)
		error(&first, NULL, NULL);
	first->size = 1;
	first->next = stack;
	stack->size = 1;
	while(input[i])
	{
		stack->next = new_last(stack, atoi_ps(input[i++], 0), 'a');
		if (!stack->next)
			error(&stack, NULL, NULL);
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
t_stack	*check_input(char **arg)
{
	t_stack	*first_a;
	char	**input;
	int		flag;

	flag = 0;
	if (!arg[2])
	{
		input = ft_split(arg[1], ' ');
		if (!input)
			return (error(NULL, NULL, NULL), NULL);
		flag = 1;
	}
	else
	{
		input = arg;
		input++;
	}
	check_duplicates(input, flag);
	if (!input[1])
		return (free_input(input), NULL);
	first_a = allocate_stack_a(input);
	if (flag == 1)
		free_input(input);
	return(first_a);
}

// what if input is only one number
//check all mallocs

int	main(int argc, char **argv)
{
	t_stack	*first_a;
	t_stack	*first_b;

	if (argc < 2)
		return (0);
	first_a = check_input(argv);
	if (!first_a)
		return (0);
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
