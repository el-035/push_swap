#include "push_swap.h"

void	error(t_stack **first_a, t_stack **first_b, char **input)
{
	ft_putstr_fd("Error\n", 2);
	if (first_a)
		free_stack(first_a);
	if (first_b)
		free_stack(first_b);
	if (input)
		free_input(input);
	exit(1);
}
void free_input(char **input)
{
	int	i;

	i = 0;
	if (!input)
		return ;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free (input);
}

void	free_stack(t_stack	**stack)
{
	int		n;
	t_stack	*current;

	if (!*stack)
		return ;
	if ((*stack)->next)
	{
		n = (*stack)->data;
		current = (*stack)->next;
		while (current->data != n)
		{
			current = current->next;
			free(current->previous);
		}
	}
	free(*stack);
	*stack = NULL;
}
