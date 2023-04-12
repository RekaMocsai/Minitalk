/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:26:26 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/12 11:36:40 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;
	int		pol;

	i = 0;
	nb = 0;
	pol = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] != '\0' && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			pol = -1;
		i++;
	}
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]))
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
		if (nb * pol > 2147483647)
			return (-1);
		if (nb * pol < -2147483648)
			return (0);
	}
	return (nb * pol);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	int	x;
	int	y;
	char	*nptr = av[1];
	if (ac == 2)
	{
		x = ft_atoi(av[1]);
		printf("Input:  %s\n", av[1]);
		printf("Output mine:  %d\n", x);
	
		y = atoi(nptr);
		printf("Input:  %s\n", nptr);
		printf("Output atoi:  %d\n", y);
	}
	return (0);
}*/
