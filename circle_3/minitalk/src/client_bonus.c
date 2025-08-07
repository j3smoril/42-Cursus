/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:01:03 by jesmoril          #+#    #+#             */
/*   Updated: 2025/05/06 15:01:06 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_bit_received = 0;

void	ft_send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_bit_received)
			pause();
		g_bit_received = 0;
		bit--;
	}
}

void	ft_send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_char(pid, str[i]);
		i++;
	}
}

void	sig_handler(int sig)
{
	(void)sig;
	g_bit_received = 1;
}

void	set_handler(struct sigaction *sa)
{
	sa->sa_handler = sig_handler;
	sa->sa_flags = 0;
	sigemptyset(&sa->sa_mask);
	sigaction(SIGUSR1, sa, NULL);
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	if (ac != 3)
	{
		write(2, "Use : ./client_bonus <PID> <message>\n", 38);
		exit(1);
	}
	if (!ft_strdigit(av[1]))
	{
		write(2, "Error : PID must be a number\n", 30);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(2, "Error : Invalid PID\n", 21);
		exit(1);
	}
	set_handler(&sa);
	ft_send_str(pid, av[2]);
	return (0);
}
