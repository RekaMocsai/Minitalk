/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reka <reka@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:21:18 by rmocsai           #+#    #+#             */
/*   Updated: 2023/03/09 13:30:36 by reka             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lensrc;
	size_t	lendst;

	j = 0;
	lensrc = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (lensrc);
	lendst = ft_strlen(dst);
	i = lendst;
	if (size <= lendst)
		return (lensrc + size);
	else
	{
		while (src[j] != '\0' && size - lendst - 1 > j)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (lensrc + lendst);
	}
}
/*
int     main(void)
{
    char        dst[50] = "Hellobello";
    const char  *src = "This is the source";
    char        dst2[50] = "Hellobello";
    size_t      size = 15;
    
    printf("Orig: %ld\n",
    strlcat(dst2, src, size));  
	printf("mine: %ld\n",
    ft_strlcat(dst, src, size));  
    return (0);
}
*/
