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

//struct_utils
t_stack	*new(int data, char stack);
t_stack	*new_last(t_stack *prev, int data, char stack);

//error + free
void	error();

#endif