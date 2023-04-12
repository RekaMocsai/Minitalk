/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:34:16 by rmocsai           #+#    #+#             */
/*   Updated: 2022/12/02 13:57:06 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_findnewline(const char *s)
{
	char	c;

	c = '\n';
	while (c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	if (*s == '\n')
		s++;
	return ((char *)s);
}

char	*ft_remains(char *stat)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (stat[i] && stat[i] != '\n')
		i++;
	if (stat[i] == '\0')
	{
		free (stat);
		return (NULL);
	}
	tmp = ft_strdup(ft_findnewline(stat));
	if (!tmp)
		return (NULL);
	free (stat);
	return (tmp);
}

char	*ft_oneline(char *stat)
{
	char	*line;
	int		size;
	int		i;

	if (!*stat)
		return (NULL);
	size = 0;
	while (stat[size] && stat[size] != '\n')
		size++;
	if (stat[size] == '\n')
		size++;
	line = (char *)malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stat[i] && stat[i] != '\n')
	{
		line[i] = stat[i];
		i++;
	}
	if (stat[i] && stat[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_readfile(char *stat, int fd)
{
	char	*tmp;
	char	*buff;
	ssize_t	size;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!stat)
		stat = ft_calloc(1, 1);
	while (ft_findnewline(stat) == 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == 0)
			break ;
		buff[size] = '\0';
		tmp = ft_strjoin(stat, buff);
		free(stat);
		stat = tmp;
	}
	free (buff);
	return (stat);
}

char	*get_next_line(int fd)
{
	static char	*stat[4096];
	char		*ret;

	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		if (stat[fd])
		{
			free (stat[fd]);
			stat[fd] = NULL;
		}
		return (NULL);
	}
	stat[fd] = ft_readfile(stat[fd], fd);
	if (!stat[fd])
		return (NULL);
	ret = ft_oneline(stat[fd]);
	stat[fd] = ft_remains(stat[fd]);
	if (!ret)
		free(stat[fd]);
	return (ret);
}
/*
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int	fd;
	char *ptr;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "open failed", 11);
		return (-1);
	}
	ptr = get_next_line(fd);
	printf("%s", ptr);	
	free(ptr);

	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);

	if (close(fd) == -1)
	{
		write(1, "close failed", 12);
		return (-1);
	}
	return (0);
}



int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
