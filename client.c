/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:35:11 by rmocsai           #+#    #+#             */
/*   Updated: 2023/04/13 16:45:03 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_in = 0;

void	ft_handshake(int signum)
{
	(void)signum;
	g_in = 1;
}

void	ft_sendsignals(pid_t pid_server, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 7;
		while (i >= 0)
		{
			if ((str[j] >> i) & 1)
				kill(pid_server, SIGUSR2);
			else
				kill(pid_server, SIGUSR1);
			i--;
			while (!g_in)
				usleep(25);
			g_in = 0;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid_server;

	if (argc != 3)
		return (ft_printf("Wrong number of arguments! Correct way: \
'S<./client [PID_NR] [message]'\n"));
	pid_server = ft_atoi(argv[1]);
	i = 0;
	signal(SIGUSR1, ft_handshake);
	ft_sendsignals(pid_server, argv[2]);
	return (0);
}
