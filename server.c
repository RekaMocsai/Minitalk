/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:35:05 by rmocsai           #+#    #+#             */
/*   Updated: 2023/04/12 11:57:20 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_out = 0;

static int	ft_bitshifting(int signum, int reset)
{
	static int		count_char = 0;

	if (reset == 0)
	{
		count_char = 0;
		reset = 1;
	}
	if (signum == SIGUSR1)
		g_out = g_out << 1;
	else if (signum == SIGUSR2)
	{
		g_out = ~g_out;
		g_out = g_out << 1;
		g_out = ~g_out;
	}
	count_char++;
	if (count_char == 8)
	{
		write(1, &g_out, 1);
		count_char = 0;
	}
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
	reset = ft_bitshifting(signum, reset);
	usleep(50);
	kill(pid_client, SIGUSR1);
}

int	main(void)
{
	pid_t				pid_server;
	struct sigaction	sa;

	sa.sa_sigaction = ft_server;
	sa.sa_flags = SA_SIGINFO;
	pid_server = getpid();
	if (pid_server == -1)
		return (1);
	ft_printf("PID: %d\n", pid_server);
	ft_printf("waiting for the client...\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
