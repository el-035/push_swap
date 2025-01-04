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
				error();
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
		return NULL;	//error and free
	stack =  new_last(first, atoi_ps(input[i++]), 'a');
	if (!stack)
		return NULL;	//error and free
	first->next = stack;
	while(input[i])
	{
		stack->next = new_last(stack, atoi_ps(input[i++]), 'a');
		if (!stack->next)
			return NULL;	//error and free
		stack = stack->next;
	}
	stack->next = first;
	first->previous = stack;
	return (first);
}

t_stack *initialise_b()
{
	t_stack	*first;

	first = new(0, 'b');
	if (!first)
		return NULL;
	return	(first);
}
/* void	test_print(t_stack *first)
{
	t_stack *temp;

	if (!first)
	{
		ft_printf("stack is empty\n");
		return ;
	}
	temp = first;
	printf(" %c\n", first->stack);
	while(temp->next && temp->next != first)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	if(temp->data)
		printf("%d\n", temp->data);
} */

void test_print(t_stack *stack, const char *name)
{
    t_stack *current;
    int count = 0;

    printf("Stack %s:\n", name);
    if (!stack)
    {
        printf("  [Empty]\n\n");
        return;
    }

    current = stack;
    do
    {
        printf("  Node %d: data = %d, stack = %c, previous = %p, next = %p\n",
               count++, current->data, current->stack,
               (void *)current->previous, (void *)current->next);
        current = current->next;
    } while (current && current->data != stack->data);

    printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*first_a;
	t_stack	*first_b;
	//t_stack	*temp;

	if (argc <= 2)	//???
		return (0);
	check_duplicates(argv);
	first_a = allocate_stack_a(argv);
	first_b = NULL;

	test_print(first_a, "a");
/* 	test_print(first_b, "b");
	push(&first_a, &first_b);
	push(&first_a, &first_b);
	swap(first_a);
	swap(first_b); */
	//moves("sa", &first_a, &first_b);
	moves("pb", &first_a, &first_b);
	//moves("rr", &first_a, &first_b);
	test_print(first_a, "a");
	test_print(first_b, "b");
}