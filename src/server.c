/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:39:44 by norabino          #+#    #+#             */
/*   Updated: 2025/03/13 14:13:11 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Error : wrong format.\n");
		ft_printf("Try : ./server\n");
		return (0);
	}
	ft_printf(BANNER0);
	ft_printf(BANNER1);
	ft_printf(BANNER2);
	ft_printf(BANNER3);
	ft_printf(BANNER4);
	ft_printf(BANNER5);
	ft_printf(BANNER6);
	ft_printf("Server PID: %d\nWaiting  for a message...\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause ();
	}
	return (0);
}
