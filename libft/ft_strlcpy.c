/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:21:10 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/10 11:14:01 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include "libft.h"

static int	ft_strlen(const char *str)
{
	unsigned int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (len != 0)
	{
		if (size == 0)
		{
			return (len);
		}
		while (i < (size - 1) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (len);
}

/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	unsigned int	size;
	char		src[] = "Hellzapoppin'there!";
	char		dest[] = "Charmander!";
	char		dest2[] = "Charmander!";
	unsigned int	len;
	
	size = 13;
	printf("source string: %s\n", src);
	printf("dest string: %s\n", dest);
	printf("size: %u\n", size);
	len = ft_strlcpy(dest, src, size);
	printf("dest string: %s\n", dest);
	strlcpy(dest2, src, size);
	printf("dest2 string: %s\n", dest2);
	printf("Offset: %u\n", len);
	return(0);
}*/
