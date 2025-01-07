#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
#include <stdio.h> //delete

typedef struct s_stack
{
    int				data;
    char            stack;
    struct s_stack  *previous;
    struct s_stack	*next;
}					t_stack;

//main
t_stack	*allocate_stack_a(char **input);

//utils
void	check_duplicates(char **input);
int		atoi_ps(const char *str);
int		is_sorted(t_stack *first);
int		is_rev_sorted(t_stack *first);
int		ft_strcmp(char *s1, char *s2);

//struct_utils
t_stack	*new(int data, char stack);
t_stack	*new_last(t_stack *prev, int data, char stack);
t_stack	*new_first(t_stack **first, int data, char stack);
int	    stack_len(t_stack *first);
int	    find_smallest(t_stack *first);
//rules
void	swap(t_stack *first);
void	push(t_stack **from, t_stack **to);
t_stack	*rotate(t_stack *first);
t_stack	*rev_rot(t_stack *first);

//moves
void	s(char *move, t_stack **first_a, t_stack **first_b);
void	p(char *move, t_stack **first_a, t_stack **first_b);
void	r(char *move, t_stack **first_a, t_stack **first_b);
void	rr(char *move, t_stack **first_a, t_stack **first_b);
void	moves(char *move, t_stack **first_a, t_stack **first_b);

//algorithm
t_stack	*algorithm(t_stack **first_a, t_stack **first_b);
int		biggest(t_stack	*first);
int	    up_down(t_stack *first);
void	push_biggest_a(t_stack **first_a, t_stack **first_b);

//three five
void    three_five(t_stack **first_a, t_stack **first_b);
void	sort_three(t_stack **first_a, t_stack **first_b);

//error + free
void	error(t_stack **first_a, t_stack **first_b);
void	free_stack(t_stack	**stack);

#endif