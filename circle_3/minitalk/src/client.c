/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:59:44 by jesmoril          #+#    #+#             */
/*   Updated: 2025/04/24 11:59:46 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(500);
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

int	main(int ac, char **av)
{
	int		pid;

	if (ac != 3)
	{
		write(2, "Use : ./client <PID> <message>\n", 32);
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
	ft_send_str(pid, av[2]);
	return (0);
}
