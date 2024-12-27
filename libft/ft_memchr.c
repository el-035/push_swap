/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:39:17 by efittant          #+#    #+#             */
/*   Updated: 2024/09/09 13:39:22 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;

	str = (unsigned char *) s;
	cc = c;
	while (n--)
	{
		if (*str == cc)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
