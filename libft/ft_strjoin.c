/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:46:33 by efittant          #+#    #+#             */
/*   Updated: 2024/09/13 15:46:35 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	mem;
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*join;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	mem = len1 + len2 + 1;
	join = (char *) ft_calloc(mem, sizeof(char));
	if (join == NULL)
		return (NULL);
	while (len1-- > 0)
		join[i++] = *s1++;
	while (len2-- > 0)
		join[i++] = *s2++;
	return (join);
}
