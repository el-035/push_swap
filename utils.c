# include"push_swap.h"

void	check_duplicates(char **input, int flag)
{
	int	i;
	int	j;
	char 	**temp;

	temp = NULL;
	if (flag == 1)
		temp = input;
	i = 0;
	j = 1;
	if (!input[j])
		atoi_ps(input[i], temp);
	while(input[i])
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
		i++;
	}
	if (str[i] < 48 || str[i] > 57)
			error(NULL, NULL, input);
	if (str[i])
	{
		while (str[i] >= 48 && str[i] <= 57)
			result = result * 10 + str[i++] - 48;
	}
	result = result * n;
	if (result < -2147483648 || result > 2147483647)
		error(NULL, NULL, input);
	return ((int) result);
} 

int	biggest_ss(t_stack *first_a, int smallest)
{
	t_stack	*start;
	int		next;
	int		i;
	int		len;

	i = 0;
	start = first_a;
	while(i < first_a->size)
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