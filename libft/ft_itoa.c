/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:27:37 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/20 11:11:39 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_size(long nb)
{
	unsigned int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		if (nb == -2147483648)
			return (11);
		nb = -nb;
		len++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}	
	return (len);
}

char	*ft_itoa(int n)
{
	char				*str;
	long				nb;
	unsigned int		len;

	nb = n;
	len = ft_size(n);
	str = (char *) ft_calloc (sizeof(char), (len + 1));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		str[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	char	*x;
	int	y;

	y =	ft_atoi(av[1]);
	if (ac == 2)
	{
		x = ft_itoa(y);
		printf("Input:  %s\n", av[1]);
		printf("Output:  %s\n", x);
	}
	return (0);
}
*/
