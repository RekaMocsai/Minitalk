/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:20:47 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/14 12:46:50 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	i = -1;
	if (d < s)
	{
		while (++i < n)
			d[i] = s[i];
	}
	if (d >= s)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			(n--);
		}
	}
	return (d);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char 		d[12];
	char		s[] = "";
	char		s1[] = "";
	size_t		n = 4;

	printf("orig: %p\n", memmove(d, s1, n));
	printf("mine: %p\n", ft_memmove(d, s, n));

	return (0);
}
*/
