/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:35:05 by rmocsai           #+#    #+#             */
/*   Updated: 2023/04/18 13:40:19 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_bitshifting(int signum, int reset, siginfo_t *info)
{
	static int		count_bit = 0;
	static int		c = 0;

	if (reset == 0)
	{
		count_bit = 0;
		reset = 1;
	}
	if (signum == SIGUSR1)
		c = c << 1;
	else if (signum == SIGUSR2)
	{
		c = ~c;
		c = c << 1;
		c = ~c;
	}
	count_bit++;
	if (count_bit == 8)
	{
		write(1, &c, 1);
		count_bit = 0;
	}
	usleep(50);
	kill(info->si_pid, SIGUSR1);
	return (1);
}

static void	ft_server(int signum, siginfo_t *info, void *context)
{
	static int		reset;
	static pid_t	pid_client = 0;
	static pid_t	pid_compare = 0;

	(void)context;
	pid_client = info->si_pid;
	if (pid_compare == 0)
		pid_compare = pid_client;
	if (pid_client != pid_compare)
	{
		reset = 0;
		pid_compare = pid_client;
	}
	reset = ft_bitshifting(signum, reset, info);
}

int	main(void)
{
	pid_t				pid_server;
	struct sigaction	sa;

	pid_server = getpid();
	if (pid_server == -1)
		return (1);
	ft_printf("PID: %d\n", pid_server);
	ft_printf("waiting for the client...\n");
	sa.sa_sigaction = ft_server;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
