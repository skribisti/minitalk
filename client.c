/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:39:49 by norabino          #+#    #+#             */
/*   Updated: 2024/12/20 14:32:59 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum) 
{
  printf("Received SIGINT = %d!\n", signum);
}

int main() 
{
  // Set the signal handler for the SIGINT and SIGTERM signals
  // to the signal_handler function
  
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);

  printf("Enter input\n");
  while (1) {
	printf("Waiting...\n");
    sleep(1);
  }

  return 0;
}