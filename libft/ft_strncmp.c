/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:22:21 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/10 11:14:24 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	while ((st1[i] != '\0' || st2[i] != '\0') && i < n)
	{
		if (st1[i] > st2[i])
		{
			return (st1[i] - st2[i]);
		}
		else if (st1[i] < st2[i])
		{
			return (st1[i] - st2[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
void	main(void)
{
	char	comp_str[] = "abcd";
	char	less[] = "abccefg";
	char	less2[] = "abcde";
	char	equal[] = "abcdefg";
	char	greater[] = "abceefg";
	char	greater2[] = "abcdefgx";
	size_t	n = 4;
	
	while (n < 11)
	{
		printf("\nn = %lu\n\n", n);
		printf("ft_strncmp: \"%s\" < \"%s\": ", less, comp_str);
		printf("%d\n", ft_strncmp(less, comp_str, n));
		printf("strncmp: \"%s\" < \"%s\": ", less, comp_str);
		printf("%d\n", strncmp(less, comp_str, n));
		printf("\n");
		printf("ft_strncmp: \"%s\" < \"%s\": ", less2, comp_str);
		printf("%d\n", ft_strncmp(less2, comp_str, n));
		printf("strncmp: \"%s\" < \"%s\": ", less2, comp_str);
		printf("%d\n", strncmp(less2, comp_str, n));
		printf("\n");
		printf("ft_strncmp: \"%s\" = \"%s\": ", equal, comp_str);
		printf("%d\n", ft_strncmp(equal, comp_str, n));
		printf("strncmp: \"%s\" = \"%s\": ", equal, comp_str);
		printf("%d\n", strncmp(equal, comp_str, n));
		printf("\n");
		printf("ft_strncmp: \"%s\" > \"%s\": ", greater, comp_str);
		printf("%d\n", ft_strncmp(greater, comp_str, n));
		printf("strncmp: \"%s\" > \"%s\": ", greater, comp_str);
		printf("%d\n", strncmp(greater, comp_str, n));
		printf("\n");
		printf("ft_strncmp: \"%s\" > \"%s\": ", greater2, comp_str);
		printf("%d\n", ft_strncmp(greater2, comp_str, n));
		printf("strncmp: \"%s\" > \"%s\": ", greater2, comp_str);
		printf("%d\n", strncmp(greater2, comp_str, n));
		n += 2;
	}
}*/
