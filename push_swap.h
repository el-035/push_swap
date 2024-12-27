#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
#include <stdio.h> //delete

typedef struct s_stack
{
    int				data;
    struct s_stack	*next;
}					t_stack;



//utils
int	atoi_ps(const char *str);

#endif