#include"push_swap.h"

//find smallest already exists, lest see if it works


int	biggest_ss(t_stack *first_a, int smallest)
{
	t_stack	*start;
	int		next;
	int		i;
	int		len;

	i = 0;
	start = first_a;
	while(i < 10)
	{
		first_a = start;
		next = find_max(first_a);
		len = stack_len(first_a);
		while (len-- > 0)
		{
			if (first_a->data < next && first_a->data > smallest)
				next = first_a->data;
			first_a = first_a->next;
		}
		if (next == smallest)
			i++;
		smallest = next;
		i++;
	}
	first_a = start;
	return (smallest);
}

void	initialise_ss(t_stack **first)
{
	int		ss_count;
	int		ss_max;
	int		len;
	int		min;
	int		tot_ss;

	tot_ss = stack_len(*first) / 10;
	if (stack_len(*first) % 10 != 0)
		tot_ss = stack_len(*first) / 10 + 1;
	min = find_smallest(*first);
	ss_count = 1;
	ss_max = biggest_ss((*first), min);
	while (ss_count <= tot_ss)
	{
		len = stack_len(*first);
		while (len-- > 0)
		{
			if ((*first)->data <= ss_max && (*first)->data >= min)
				(*first)->sub_stack = ss_count;
			(*first) = (*first)->next;
		}
		ss_count++;
		min = ss_max;
		ss_max = biggest_ss((*first), min);
	}
}

int	next_small(t_stack *first, int biggest)
{
	t_stack	*temp;
	int		next;

	temp = first;
	next = find_smallest(first);
	while (1)
	{
		if (first->data > next && first->data < biggest)
			next = first->data;
		first = first->next;
		if (temp == first)
			break ;
	}
	return (next);
}

void	initialise_position(t_stack **first)
{
	t_stack	*temp;
	int		biggest;
	int		pos;

	temp = (*first);
	biggest = find_max(*first);
	pos = 1;
	while (temp)
	{
		if (temp->data == biggest && biggest != find_smallest(temp))
		{
			temp->position = pos++;
			biggest = next_small(*first, biggest);
		}
		if (biggest == find_smallest(temp) && temp->data == biggest)
		{
			temp->position = pos;
			break ;
		}
		temp = temp->next;
	}
}

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
        printf("  Node %d: data = %d, ss = %d, pos = %d\n",
               count++, current->data, current->sub_stack, current->position/* current->stack, (void *)current,
			   (void *)current->previous, (void *)current->next */);
        current = current->next;
    } while (current && current->data != stack->data);

    printf("\n");
}
void	half_sort_b(t_stack **first_a, t_stack **first_b)
{
	int	ss;
	int	n;

	ss = 1;
	n = 0;
	initialise_ss(first_a);
	while (*first_a)
	{
		if ((*first_a)->sub_stack != ss && (*first_a)->next)
			moves("ra", first_a, first_b);
		else if ((*first_a)->sub_stack == ss)
		{
			moves("pb", first_a, first_b);
			n++;
		}
		if (n == 10)
		{
			n = 0;
			ss++;
		}
	}
	initialise_position(first_b);
}
int	up_or_down(t_stack *first, int pos)
{
	int	nodes;
	int	count;

	if (!first || !first->next || !first->previous)
		return (-1);
	nodes = stack_len(first);
	count = 0;
	while (count <= nodes)
	{
		if (first->position == pos)
			break ;
		first = first->next;
		count++;
	}
	if (count < (nodes / 2))
		return (1); // close to top
	else if (count > (nodes / 2))
		return (2);
	return (0);
}
void	back_to_a(t_stack **first_a, t_stack **first_b)
{
	int	pos;
	int max_pos;

	test_print(*first_b, "B");
	pos = 1;
	max_pos = stack_len(*first_b);
	while (pos <= max_pos)
	{
		test_print(*first_b, "B");
		if ((*first_b)->position == pos)
		{
			moves("pa", first_a, first_b);
			pos++;
			ft_printf("%d\n", pos);
		}
		else if((*first_b)->next->position == pos)
		{
			moves("sb", first_a, first_b);
			moves("pa", first_a, first_b);
			pos++;
			ft_printf("%d\n", pos);
		}
		else if ((*first_b)->previous->position == pos)
		{
			moves("rrb", first_a, first_b);
			moves("pa", first_a, first_b);
			pos++;
			ft_printf("%d\n", pos);
		}
		else
		{
			moves("rb", first_a, first_b);
			moves("rb", first_a, first_b);
			moves("rb", first_a, first_b);
			moves("rb", first_a, first_b);
			//moves("rb", first_a, first_b);
			test_print(*first_b, "B");
			if (pos == 4)
				break ;
			//test_print(*first_b, "B");
		}
	}
}
void	lets_sort(t_stack **first_a, t_stack **first_b)
{
	half_sort_b(first_a, first_b);
	back_to_a(first_a, first_b);
	//test_print(*first_b, "B");
	//ft_printf("%d\n", up_or_down(*first_b, 49));

}