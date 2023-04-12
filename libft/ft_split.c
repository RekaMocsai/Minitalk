/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:27:27 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/28 13:06:31 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cuntwords(char const *s, char c)
{
	int	skip;
	int	cunt;

	cunt = 0;
	skip = 1;
	while (*s)
	{
		if (*s != c && skip)
		{
			skip = 0;
			cunt++;
		}
		else if (*s == c)
			skip = 1;
		s++;
	}
	return (cunt);
}

static char	*copier(char *str, char const *s, int first, int last)
{
	int	i;

	i = 0;
	while (last > 0)
	{
		str[i] = s[first - last];
		i++;
		last--;
	}
	str[i] = '\0';
	return (str);
}

static char	**helper(char **arr, char const *s, char c, int cunt)
{
	int	first;
	int	last;
	int	word;

	first = 0;
	word = 0;
	last = 0;
	while (word < cunt)
	{
		while (s[first] != '\0' && s[first] == c)
			first++;
		while (s[first] != '\0' && s[first] != c)
		{
			first++;
			last++;
		}
		arr[word] = (char *)malloc ((last + 1) * sizeof(char));
		if (!arr[word])
			return (NULL);
		copier(arr[word], s, first, last);
		last = 0;
		word++;
	}
	arr[word] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		wordcunt;
	char	**array;

	if (s == NULL)
		return (NULL);
	wordcunt = cuntwords(s, c);
	array = (char **)malloc (sizeof(char *) * (wordcunt + 1));
	if (!array)
		return (NULL);
	helper(array, s, c, wordcunt);
	return (array);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s;
	char	c;
	char	**arr;
	int		i;

	s = "..abc...de....fghi...jk..lmn5.";
	c = '.';
	printf("string received: %s\n", s);
	i = cuntwords(s, c);
	printf("nbr of cunts: %d\n", i);
	arr = ft_split(s, c);
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		free (arr[i]);
		i++;
	}
	free (arr);
	return (0);
}
*/
