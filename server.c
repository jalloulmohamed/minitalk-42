/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:20:44 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/17 18:23:42 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	g_pid;

void	handel(int num, siginfo_t *info, void *context)
{
	static int	x;
	static int	j;

	(void)context;
	if (g_pid == 0)
		g_pid = info->si_pid;
	if (g_pid != info -> si_pid)
	{
		x = 0;
		j = 0;
		g_pid = info->si_pid;
	}
	if (num == SIGUSR1)
		x = x | 1 << j;
	j++;
	if (j == 8)
	{
		write(1, &x, 1);
		x = 0;
		j = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	char				*pid;

	pid = ft_itoa(getpid());
	sa.sa_sigaction = handel;
	sa.sa_flags = SA_SIGINFO;
	ft_putstr(pid);
	free (pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	while (1)
		pause();
}
