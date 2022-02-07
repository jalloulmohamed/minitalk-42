/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:13:36 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/19 18:00:00 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	g_cmt;

void	send_s(int b, int pid)
{
	int	i;

	i = 8;
	while (i)
	{
		if ((b & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		if ((b & 1) == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(700);
		b = b >> 1;
		i--;
	}
}

void	handle_msg(int num)
{
	char	*p;

	(void)num;
	p = ft_itoa(g_cmt);
	ft_putstr(p);
	ft_putstr(" message recived.\n");
}

void	cont(int num)
{
	(void)num;
	g_cmt++;
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	signal(SIGUSR1, handle_msg);
	signal(SIGUSR2, cont);
	if (argc == 3)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_putstr("INVALID PID");
			return (0);
		}
		while (argv[2][i])
		{
			send_s(argv[2][i], pid);
			i++;
		}
		send_s(argv[2][i], pid);
	}
	else
		perror("Error:  you need 3 arg");
}
