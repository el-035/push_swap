/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:38:50 by efittant          #+#    #+#             */
/*   Updated: 2024/09/09 13:38:59 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	i = 0;
	if (n == 0)
		return ((void *) d);
	else if (&d[i] < &s[i])
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (&d[i] > &s[i])
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return ((void *) d);
}
