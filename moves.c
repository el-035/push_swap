#include"push_swap.h"

void	s(char *move, t_stack **first_a, t_stack **first_b)
{
	if (ft_strcmp(move, "sa") == 0)
		swap(*first_a);
	else if (ft_strcmp(move, "sb") == 0)
		swap(*first_b);
	else if (ft_strcmp(move, "ss") == 0)
	{
		swap(*first_a);
		swap(*first_b);
	}
}
void	p(char *move, t_stack **first_a, t_stack **first_b)
{
	if (ft_strcmp(move, "pa") == 0)
		push(first_a, first_b);
	else if (ft_strcmp(move, "pb") == 0)
		push(first_b, first_a);
}
void	r(char *move, t_stack **first_a, t_stack **first_b)
{
	if (ft_strcmp(move, "ra") == 0)
		rotate(*first_a);
	else if (ft_strcmp(move, "rb") == 0)
		rotate(*first_b);
	else if (ft_strcmp(move, "rr") == 0)
	{
		rotate(*first_a);
		rotate(*first_b);
	}
	else if (ft_strcmp(move, "rra") == 0)
		rev_rot(*first_a);
	else if (ft_strcmp(move, "rrb") == 0)
		rev_rot(*first_b);
	else if (ft_strcmp(move, "rrr") == 0)
	{
		rev_rot(*first_a);
		rev_rot(*first_b);
	}
}
void	moves(char *move, t_stack **first_a, t_stack **first_b)
{
	s(move, first_a, first_b);
	p(move, first_a, first_b);
	r(move, first_a, first_b);
}