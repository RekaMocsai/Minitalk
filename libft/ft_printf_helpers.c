/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:03:47 by rmocsai           #+#    #+#             */
/*   Updated: 2022/11/07 13:37:16 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsig(unsigned int u)
{
	if (u < 10)
	{
		ft_putchar(u + '0');
		return (1);
	}
	return (ft_unsig(u / 10) + ft_unsig(u % 10));
}

int	ft_putnull(void)
{
	ft_putstr("(null)");
	return (6);
}

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count = count + ft_putstr("(nil)");
		return (count);
	}
	count = count + ft_putstr("0x");
	count = count + ft_puthex(ptr, LOWHEX);
	return (count);
}

int	ft_puthex(unsigned long n, char *base)
{
	int	count;
	int	i;
	int	arr[500];

	count = 0;
	if (n == 0)
	{
		count = count + ft_putchar('0');
		return (count);
	}
	i = 0;
	while (n)
	{
		arr[i] = n % 16;
		n = n / 16;
		i++;
	}
	while (--i >= 0)
		count = count + ft_putchar(base[arr[i]]);
	return (count);
}
