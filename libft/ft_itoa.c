/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:33:59 by efittant          #+#    #+#             */
/*   Updated: 2024/09/13 18:34:01 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(int n)
{
	int	mem;

	mem = 0;
	if (n == -2147483648)
		mem = 11;
	if (n <= 0)
	{
		mem++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		mem++;
	}
	return (mem);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		mem;

	mem = ft_intlen(n) + 1;
	if (n == -2147483648)
		arr = ft_strdup("-2147483648");
	else
		arr = (char *) malloc(mem * sizeof(char));
	if (arr == NULL)
		return (NULL);
	arr[--mem] = '\0';
	if (n < 0 && n > -2147483648)
	{
		n *= -1;
		arr[0] = '-';
	}
	if (n == 0)
		arr[0] = '0';
	while (arr[--mem] != '-' && mem >= 0 && n != 0 && n != -2147483648)
	{
		arr[mem] = (n % 10) + 48;
		n /= 10;
	}
	return (arr);
}
