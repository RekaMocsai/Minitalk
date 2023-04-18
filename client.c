/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:35:11 by rmocsai           #+#    #+#             */
/*   Updated: 2023/04/18 13:46:56 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_in = 0;

void	ft_handshake(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)context;
	(void)info;
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
				usleep(1);
			g_in = 0;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	pid_t				pid_server;
	struct sigaction	sa;

	if (ac != 3)
		return (ft_printf("Wrong number of arguments! Correct way: \
'S<./client [PID_NR] [message]'\n"));
	pid_server = ft_atoi(av[1]);
	sa.sa_sigaction = ft_handshake;
	sigaction(SIGUSR1, &sa, NULL);
	ft_sendsignals(pid_server, av[2]);
	return (0);
}
