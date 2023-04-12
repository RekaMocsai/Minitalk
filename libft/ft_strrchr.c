/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:22:03 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/11 13:05:51 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main    (void)
{   
    int     i = 10;
    char    *s = "nsjdhkadhkjaf\0jhdfk#";
    
    printf("orig: %s\n", strchr(s, i));
    printf("mine: %s\n", ft_strchr(s, i));
    return (0);
}
*/
