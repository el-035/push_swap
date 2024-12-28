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
	return (first);
}
void	test_print(t_stack *first)
{
	t_stack *temp;

	temp = first;
	printf(" A\n");
	while(temp->next != first)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}
int	main(int argc, char **argv)
{
	t_stack	*first_a;

	if (argc <= 2)	//???
		return (0);
	check_duplicates(argv);
	first_a = allocate_stack_a(argv);
	test_print (first_a);
	swap(first_a);
	test_print (first_a);
	first_a = rotate(first_a);
	test_print (first_a);
	first_a = rev_rot(first_a);
	swap(first_a);
	test_print (first_a);
}