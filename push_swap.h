/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:38:35 by efittant          #+#    #+#             */
/*   Updated: 2025/01/14 19:38:36 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	char			stack;
	int				size;
	int				sub_stack;
	int				position;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

//main
t_stack	*allocate_stack_a(char **input);
void	initialise_position(t_stack **first);
void	ss_size(t_stack **first);
t_stack	*check_input(char **arg);

//utils
void	check_duplicates(char **input, int flag);
int		atoi_ps(const char *str, char **input);
int		ft_strcmp(char *s1, char *s2);
int		find_max(t_stack *first);
int		biggest_ss(t_stack *first_a, int smallest);

//struct_utils
t_stack	*new(int data, char stack, int sub_stack);
t_stack	*new_last(t_stack *prev, int data, char stack);
t_stack	*new_first(t_stack **first, int data, char stack, int sub_stack);
int		stack_len(t_stack *first);
int		find_smallest(t_stack *first);

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

//lest sort
void	initialise_ss(t_stack *first);
int		next_small(t_stack *first, int biggest);
void	back_to_a(t_stack **first_a, t_stack **first_b);
void	half_sort_b(t_stack **first_a, t_stack **first_b);
int		top_bottom(t_stack *first, int target, int flag);

//three five
void	sort_three(t_stack **first_a, t_stack **first_b);
void	three_five(t_stack **first_a, t_stack **first_b);
void	push_smallest(t_stack **first_a, t_stack **first_b);
int		biggest(t_stack	*first);
int		is_sorted(t_stack *first);

//error + free
void	error(t_stack **first_a, t_stack **first_b, char **input);
void	free_stack(t_stack	**stack);
void	free_input(char **input);

#endif
