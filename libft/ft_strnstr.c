/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:23:13 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/14 16:00:33 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	if (little == NULL || len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && big[i + j] != '\0' && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)(&big[i]));
		i++;
		j = 0;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
//	const char *big = "Find what you are looking for!*§-+§";
	const char *little = "look";
	size_t		len = 35;

	printf("orig: %s\n", strnstr(((void *)0), little, len));
//	printf("mine: %s\n", ft_strnstr(((void *)0), little, len));
}
*/
/*
#include <stdio.h>
int main (void)
{
	char str1[50] = "TEsttestzteHallosteeHllo";
	char str2[] = "Hallo";
	printf("%s", ft_strnstr(str1, str2, 40));
			printf("\n");
}
*/
