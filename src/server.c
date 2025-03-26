/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:39:44 by norabino          #+#    #+#             */
/*   Updated: 2025/03/26 17:18:33 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*ft_strjoin_char(char *s1, char c)
{
	char	*res;
	size_t	i;

	if (!c)
		return (NULL);
	i = 0;
	if (s1)
		res = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
	else
		res = (char *)malloc(2 * sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	res[i] = c;
	res[i + 1] = '\0';
	if (s1)
		free(s1);
	return (res);
}

void	handler(int signal)
{
	static int	bit;
	static char	c;
	static char	*str;

	if (signal == SIGUSR1)
		c |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		else
			str = ft_strjoin_char(str, (char)c);
		bit = 0;
		c = 0;
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
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause ();
	}
	return (0);
}
