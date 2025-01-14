/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:39:44 by norabino          #+#    #+#             */
/*   Updated: 2025/01/14 09:49:36 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}
/*void	handler(int signum)
{
	static char	c = 0;
	static int	i = 0;
}*/

int	main(void)
{
	/*struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	*/
	printf(BANNER0);
	printf(BANNER1);
	printf(BANNER2);
	printf(BANNER3);
	printf(BANNER4);
	printf(BANNER5);
	printf(BANNER6);
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}