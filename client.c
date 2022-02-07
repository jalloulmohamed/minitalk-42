/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:13:36 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/17 18:22:30 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	send_s(int b, int pid)
{
	int	i;

	i = 8;
	while (i)
	{
		if ((b & 1) == 1)
		{
			kill(pid, SIGUSR1);
		}
		if ((b & 1) == 0)
		{
			kill(pid, SIGUSR2);
		}
		usleep(700);
		b = b >> 1;
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

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
	}
	else
		perror("Error: you need 3 arg");
}
