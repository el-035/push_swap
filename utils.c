/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:51:02 by efittant          #+#    #+#             */
/*   Updated: 2025/01/14 18:51:04 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(char **input, int flag)
{
	int		i;
	int		j;
	char	**temp;

	temp = NULL;
	if (flag == 1)
		temp = input;
	i = 0;
	j = 1;
	if (!input[j])
		atoi_ps(input[i], temp);
	while (input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (atoi_ps(input[i], temp) == atoi_ps(input[j], temp))
				error(NULL, NULL, temp);
			j++;
		}
		i++;
	}
}

int	atoi_ps(const char *str, char **input)
{
	int				i;
	long long		result;
	long long		n;

	n = 1;
	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		if (!str[++i])
			error(NULL, NULL, input);
	}
	is_digit((char *) str, i, input);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
		result = result * 10 + str[i++] - 48;
	result = result * n;
	if (result < -2147483648 || result > 2147483647)
		error(NULL, NULL, input);
	return ((int) result);
}

void	is_digit(char *str, int pos, char **input)
{
	while (str[pos])
	{
		if (!ft_isdigit(str[pos++]))
			error(NULL, NULL, input);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	find_max(t_stack *first)
{
	int	max;
	int	start;

	start = first->data;
	max = first->data;
	first = first->next;
	while (first->data != start)
	{
		if (first->data > max)
			max = first->data;
		first = first->next;
	}
	return (max);
}
