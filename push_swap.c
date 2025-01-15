/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:50:20 by efittant          #+#    #+#             */
/*   Updated: 2025/01/14 18:50:23 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*allocate_stack_a(char **input, int flag)
{
	t_stack	*first;
	t_stack	*stack;
	int		i;
	char	**temp;

	i = 0;
	temp = NULL;
	if (flag == 1)
		temp = input;
	first = new(atoi_ps(input[i++], 0), 'a', 0, temp);
	first->size = 1;
	stack = first;
	while (input[i])
	{
		stack->next = new_last(stack, atoi_ps(input[i++], 0), 'a', temp);
		if (!stack->next)
			error(&stack, NULL, NULL);
		stack->next->size = 1;
		stack = stack->next;
	}
	stack->next = first;
	first->previous = stack;
	return (first);
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

void	initialise_position(t_stack **first)
{
	t_stack	*temp;
	int		current;
	int		pos;

	temp = (*first);
	current = find_max(*first);
	pos = 1;
	while (temp)
	{
		if (temp->data == current && current != find_smallest(temp))
		{
			temp->position = pos++;
			current = next_small(*first, current);
		}
		if (current == find_smallest(temp) && temp->data == current)
		{
			temp->position = pos;
			break ;
		}
		temp = temp->next;
	}
}

t_stack	*check_input(char **arg)
{
	t_stack	*first_a;
	char	**input;
	int		flag;

	flag = 0;
	if (!arg[1])
		return (NULL);
	if (!arg[2])
	{
		input = ft_split(arg[1], ' ');
		if (!input)
			return (error(NULL, NULL, input), NULL);
		flag = 1;
	}
	else
		input = arg + 1;
	if (!input[0] && flag == 1)
		return (free_input(input), NULL);
	check_duplicates(input, flag);
	if (!input[1])
		return (free_input(input), NULL);
	first_a = allocate_stack_a(input, flag);
	if (flag == 1)
		free_input(input);
	return (first_a);
}

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
		initialise_ss(first_a);
		half_sort_b(&first_a, &first_b);
		initialise_position(&first_b);
		sort_a(&first_a, &first_b);
	}
	free_stack(&first_a);
	free_stack(&first_b);
}
