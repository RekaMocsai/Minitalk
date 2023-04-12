/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reka <reka@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:20:36 by rmocsai           #+#    #+#             */
/*   Updated: 2023/03/09 14:27:15 by reka             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*s;
	char		*d;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
//	char	*s = NULL;
//	char	*d = NULL;
//	char	*d2 = NULL;
	size_t	n = 5;

//	printf ("memcpy dest string: %p\n", memcpy(((void*)0), ((void*)0), n));
	printf ("ft_memcpy dest string: %p\n", ft_memcpy(((void*)0), ((void*)0), n));
}
*/
