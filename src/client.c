/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:39:49 by norabino          #+#    #+#             */
/*   Updated: 2025/03/30 17:53:57 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_ack_received = 0;

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
	else
		write(1, "Message sent successfully!\n", 27);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = n * 10 + str[i] - '0';
			i++;
		}
		else
			return (0);
	}
	return (n);
}

void	send_char(int pid, char c)
{
	int	bit;
	int	time;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		time = 0;
		g_ack_received = 0;
		while (!g_ack_received && time < 100)
		{
			time++;
			usleep(1);
		}
		bit++;
	}
}

void	send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = sig_handler;
	if (ac != 3)
	{
		write(1, "Usage: ./client [PID] [STRING]\n", 32);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (!pid)
	{
		write(1, "Error: PID contains only number and can't be zero.\n", 52);
		return (0);
	}
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_str(pid, av[2]);
	return (0);
}
