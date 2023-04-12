/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:27:17 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/19 12:07:33 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	helper(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		beg;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	beg = 0;
	end = ft_strlen(s1);
	while (s1[beg] && helper(s1[beg], set))
		beg++;
	while (helper(s1[end - 1], set) && end > beg)
		end--;
	str = (char *)malloc((end - beg + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (beg < end)
	{
		str[i] = s1[beg];
		i++;
		beg++;
	}
	str[i] = '\0';
	return (str);
}
/*

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	return (ft_substr(s1, 0, len + 1);
}

#include <stdio.h>
int	main(void)
{
	const char s1[] = "xyThere once was a ship that took to seayx";
	char const set[] = "xy"; 
	char *str;

	str = ft_strtrim(s1, set);
	printf("The old string is this:\n%s\n", s1);
	printf("The new string is this:\n%s\n", str);
	free (str);
	return (0);
}*/
