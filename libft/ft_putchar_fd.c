/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:28:34 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/17 10:53:48 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int	main (void)
{
	char	x = 'Z';
	int	fd;

	fd = open("file", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		write(1, "open failed", 11);
		return (1);
	}
	printf("%d\n", fd);
	ft_putchar_fd(x, fd);
	if (close(fd) == -1)
	{
		write(1, "close failed", 12);
		return (1);
	}
	return (0);
}*/
