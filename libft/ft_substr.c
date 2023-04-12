/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:26:04 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/17 15:55:48 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copier(char const *s, char *sub, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start] && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{		
		sub = (char *)malloc (1 * (sizeof(char)));
		if (!sub)
			return (NULL);
		*sub = 0;
		return (sub);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *)malloc ((len + 1) * (sizeof(char)));
	if (!sub)
		return (NULL);
	copier(s, sub, start, len);
	return (sub);
}
/*
#include <stdio.h>
int	main(void)
{
	char 			s[10] = "abshdifkch";
	char 			*sub;
	unsigned int	start;
	size_t			len;

//	s = "There once was a ship that put to sea\n /
//	and the name of that ship was the Billy o' Tea";
	start = 9;
	len = 10;
	printf("The original string: %s\n", s);
	sub = ft_substr(s, start, len);
	printf("The substring: %s\n", sub);

	return (0);
}*/
