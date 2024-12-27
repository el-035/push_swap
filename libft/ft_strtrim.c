/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:11:20 by efittant          #+#    #+#             */
/*   Updated: 2024/09/13 18:11:22 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	ft_frontcheck(char const *s1, char const *set)
{
	int	i;
	int	start;
	int	s;

	i = 0;
	start = 0;
	s = 0;
	while (set[s] && s1[i])
	{
		if (s1[i] == set[s])
		{
			i++;
			start++;
			s = 0;
		}
		else
			s++;
	}
	return (start);
}

static int	ft_backcheck(char const *s1, char const *set)
{
	int	end;
	int	s;

	end = ft_strlen(s1) - 1;
	s = 0;
	while (set[s] && end >= 0)
	{
		if (s1[end] == set[s])
		{
			end--;
			s = 0;
		}
		else
			s++;
	}
	end++;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		mem;
	int		start;
	int		new;
	char	*strim;

	new = 0;
	start = ft_frontcheck(s1, set);
	mem = ft_backcheck(s1, set) - start + 1;
	if (!s1 || start == (int) ft_strlen(s1))
		strim = (ft_strdup(""));
	else if (!set)
		strim = (ft_strdup(s1));
	else
		strim = (char *) malloc(mem * sizeof(char));
	if (strim == NULL)
		return (NULL);
	while (new < (mem - 1) && s1 && set)
		strim[new++] = s1[start++];
	strim[new] = '\0';
	return (strim);
}
