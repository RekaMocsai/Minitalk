/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:35:05 by rmocsai           #+#    #+#             */
/*   Updated: 2023/04/13 16:45:05 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_bitshifting(int signum, int reset, siginfo_t *info)
{
	static int		count_char = 0;
	static int		g_out = 0;

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
	usleep(25);
	kill(info->si_pid, SIGUSR1);
	count_char++;
	if (count_char == 8)
	{
		write(1, &g_out, 1);
		count_char = 0;
	}
	return (1);
}

// If the signal is SIGUSR1, the function shifts the g_out variable
// one bit to the left. If the signal is SIGUSR2, the function inverts
// the bits in g_out, shifts it one bit to the left, and then inverts
// the bits again.

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
