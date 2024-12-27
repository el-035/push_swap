/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:55:07 by efittant          #+#    #+#             */
/*   Updated: 2024/09/18 15:55:09 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int	ft_word_count(char *s, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			wc++;
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (wc);
}

static char	*ft_word(char *s, char c, int i)
{
	char	*word;
	int		j;

	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	word = (char *) malloc((j + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = i - j;
	j = 0;
	while (s[i] != c && s[i])
		word[j++] = s[i++];
	word[j] = '\0';
	return (word);
}

static char	**ft_free(char **split)
{
	int	word;

	word = 0;
	while (split[word])
	{
		free(split[word]);
		word++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	int		i;
	int		j;
	char	**split;

	wc = ft_word_count((char *) s, c);
	i = 0;
	j = 0;
	split = (char **) malloc ((wc + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	else
	{
		while (s && split && j < wc)
		{
			split[j++] = ft_word((char *)s, c, i);
			if (!split[j - 1])
				return (ft_free(split));
			while (s[i] == c)
				i++;
			i = i + ft_strlen(split[j - 1]) + 1;
		}
	}
	split[j] = 0;
	return (split);
}
