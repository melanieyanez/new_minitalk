/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:48:45 by myanez-p          #+#    #+#             */
/*   Updated: 2023/09/05 22:43:40 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	receive_confirmation(int num_signal)
{
	(void)num_signal;
	ft_printf("Message received\n");
	exit(0);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	send_end_message(int pid_server)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid_server, SIGUSR1);
		usleep(100);
		i ++;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction envoyant les caractères du message en paramètres */
/* sous forme binaire */

void	send_message(char *message, int pid_server)
{
	int				nletter;
	unsigned long	nbit;

	nletter = 0;
	while (message[nletter])
	{
		nbit = 0;
		while (nbit < 8)
		{
			if ((message[nletter] >> (7 - nbit)) & 1)
				kill(pid_server, SIGUSR2);
			else
				kill(pid_server, SIGUSR1);
			usleep(100);
			nbit++;
		}
		nletter++;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main(int argc, char **argv)
{
	int					pid_server;
	char				*message;

	signal(SIGUSR1, receive_confirmation);
	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		message = argv[2];
		send_message(message, pid_server);
		send_end_message(pid_server);
	}
	else
		ft_printf("Please enter : ./client <pid_server> <your message>\n");
	while (1)
		pause();
	return (0);
}
