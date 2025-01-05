# include"push_swap.h"

int	atoi_ps(const char *str)
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
	if (str[i])
	{
		while (str[i] >= 48 && str[i] <= 57)
			result = result * 10 + str[i++] - 48;
	}
	result = result * n;
	if (result < -2147483648 || result > 2147483647)
		error(NULL, NULL);
	return ((int) result);
}

int	is_sorted(t_stack *first)
{
	t_stack	*current;

	if (!first)
		return (0);
	current = first->next;
	if (first->data > current->data)
		return (0);
	while(current->next != first)
	{
		if (current->data > current->next->data)
			return (0);
		else
			current = current->next;
	}
	return (1);
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