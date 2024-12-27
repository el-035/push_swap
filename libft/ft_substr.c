/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:39:21 by efittant          #+#    #+#             */
/*   Updated: 2024/09/13 13:39:24 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	slen;
	size_t	memlen;

	i = 0;
	memlen = 0;
	slen = ft_strlen(s);
	if ((slen - start) >= len)
		memlen = len;
	else if ((slen - start) < len)
		memlen = slen - start;
	if (start >= slen || !s || !*s)
		return (ft_strdup(""));
	else
		sub = (char *) malloc((memlen + 1) * sizeof (char));
	if (sub == NULL)
		return (NULL);
	sub[memlen] = '\0';
	while (i < memlen)
		sub[i++] = s[start++];
	return (sub);
}
