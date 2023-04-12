/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:22:39 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/13 11:45:13 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (n == 0)
		return (0);
	ptr1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] == (unsigned char)c)
		{
			ptr2 = &ptr1[i];
			return ((void *)ptr2);
		}
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char data[] = "/|\x12\xff\x09\0\x42\042\0\42|\\";
	size_t n = 12;
	int c = '\0';
	printf("orig: %p\n", memchr(data, c, n));
	printf("mine: %p\n", ft_memchr(data, c, n));
	// nullchr not found?
}*/
