/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:23:43 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/30 10:52:46 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (nmemb >= 4294967295 || size >= 4294967295)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		*(char *)(ptr + i) = '\0';
		i++;
	}
	return ((void *)ptr);
}
/*
#include <stdio.h>
int main (void)
{
	size_t 	a = 55;
	size_t 	b = 4;
	void	*x;

	printf("%lu\n", (SIZE_MAX));
	x = ft_calloc(a, b);
	printf("%p", x);
	free (x);
	return(0);	
}
*/
