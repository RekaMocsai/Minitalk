/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:23:55 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/14 12:46:11 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s) + 1;
	dst = (char *)malloc(len * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s, len);
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s[] = "Whatever this is";
	
	printf("orig: %s\n", (char *)strdup(s) );
	printf("mine: %s\n", (char *)ft_strdup(s) );
	
	return (0);	
}
*/
