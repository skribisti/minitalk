/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:39:49 by norabino          #+#    #+#             */
/*   Updated: 2025/01/06 16:59:50 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	n;
	int	i;

	n = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		usleep(100);
		i++;
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
	send_char(pid, str[i]);
}

int	main(int ac, char *av) 
{
	int	pid;

	if (ac != 3)
	{
		write(1, "Usage: ./client [PID] [STRING]\n", 30);
		return (1);
	}
	pid = ft_atoi(av[1]);
	send_str(pid, av[2]);
}