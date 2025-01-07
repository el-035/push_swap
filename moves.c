#include"push_swap.h"

void	s(char *move, t_stack **first_a, t_stack **first_b)
{
	if (ft_strcmp(move, "sa") == 0)
	{
		ft_printf("sa\n");
		swap(*first_a);
	}
	else if (ft_strcmp(move, "sb") == 0)
	{
		ft_printf("sb\n");
		swap(*first_b);
	}
	else if (ft_strcmp(move, "ss") == 0)
	{
		ft_printf("ss\n");
		swap(*first_a);
		swap(*first_b);
	}
}
void	p(char *move, t_stack **first_a, t_stack **first_b)
{

	if (ft_strcmp(move, "pa") == 0)
	{
		ft_printf("pa\n");
		push(first_b, first_a);
	}
	else if (ft_strcmp(move, "pb") == 0)
	{
		ft_printf("pb\n");
		push(first_a, first_b);
	}
}
void	r(char *move, t_stack **first_a, t_stack **first_b)
{
	if (ft_strcmp(move, "ra") == 0)
	{
		ft_printf("ra\n");
		(*first_a) = rotate(*first_a);
	}
	else if (ft_strcmp(move, "rb") == 0)
	{
		ft_printf("rb\n");
		(*first_b) = rotate(*first_b);
	}
	else if (ft_strcmp(move, "rr") == 0)
	{
		ft_printf("rr\n");
		(*first_a) = rotate(*first_a);
		(*first_b) = rotate(*first_b);
	}
}
void	rr(char *move, t_stack **first_a, t_stack **first_b)
{
	if (ft_strcmp(move, "rra") == 0)
	{
		ft_printf("rra\n");
		(*first_a) = rev_rot(*first_a);
	}
	else if (ft_strcmp(move, "rrb") == 0)
	{
		ft_printf("rrb\n");
		(*first_b) = rev_rot(*first_b);
	}
	else if (ft_strcmp(move, "rrr") == 0)
	{
		ft_printf("rrr\n");
		(*first_a) = rev_rot(*first_a);
		(*first_b) = rev_rot(*first_b);
	}
}
void	moves(char *move, t_stack **first_a, t_stack **first_b)
{
	s(move, first_a, first_b);
	p(move, first_a, first_b);
	r(move, first_a, first_b);
	rr(move, first_a, first_b);
}