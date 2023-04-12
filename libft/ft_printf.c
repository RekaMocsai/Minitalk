/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:09:48 by rmocsai           #+#    #+#             */
/*   Updated: 2022/11/07 13:46:21 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count = count + ft_putnull();
		return (count);
	}
	while (str[count] != '\0')
		count = count + ft_putchar(str[count]);
	return (count);
}

int	ft_putnbr(int n)
{
	int			pol;
	char		c;
	int			count;

	pol = 1;
	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		pol = -1;
	}
	if (n / 10)
		count = count + ft_putnbr(n / 10 * pol);
	c = '0' + n % 10 * pol;
	count = count + ft_putchar(c);
	if (pol == -1)
		count++;
	return (count);
}

int	ft_speci(va_list args, const char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count = count + ft_putchar('%');
	else if (c == 'c')
		count = count + ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = count + ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count = count + ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count = count + ft_unsig(va_arg(args, unsigned int));
	else if (c == 'x')
		count = count + ft_puthex(va_arg(args, unsigned int), LOWHEX);
	else if (c == 'X')
		count = count + ft_puthex(va_arg(args, unsigned int), UPHEX);
	else if (c == 'p')
		count = count + ft_putptr(va_arg(args, unsigned long));
	else
	{
		count = count + ft_putchar('%');
		count = count + ft_putchar(c);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		counter;

	va_start(args, str);
	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			counter = counter + ft_speci(args, str[i + 1]);
			i++;
		}
		else
			counter = counter + ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (counter);
}
