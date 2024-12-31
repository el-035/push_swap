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
void	check_duplicates(char **input);
t_stack	*allocate_stack_a(char **input);

//utils
int	atoi_ps(const char *str);
int	is_sorted(t_stack *first);

//struct_utils
t_stack	*new(int data, char stack);
t_stack	*new_last(t_stack *prev, int data, char stack);
t_stack	*new_first(t_stack **first, int data, char stack);

//rules
void	swap(t_stack *first);
void	push(t_stack **from, t_stack **to);
t_stack	*rotate(t_stack *first);
t_stack	*rev_rot(t_stack *first);

//error + free
void	error();

#endif