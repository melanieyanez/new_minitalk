/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:48:45 by myanez-p          #+#    #+#             */
/*   Updated: 2023/09/06 18:43:59 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_message_received = 0;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Handler de réception du signal de confimation */

void	receive_confirmation(int num_signal)
{
	(void)num_signal;
	g_message_received = 1;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Envoie 0 pour signaler la fin du message */

void	send_end_message(int pid_server)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (kill(pid_server, SIGUSR1) == -1)
			error_management(5);
		usleep(50);
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
			{
				if (kill(pid_server, SIGUSR2) == -1)
					error_management(0);
			}
			else
			{
				if (kill(pid_server, SIGUSR1) == -1)
					error_management(0);
			}
			usleep(50);
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
	if (!signal(SIGUSR1, receive_confirmation))
		error_management(1);
	pid_server = ft_atoi(argv[1]);
	message = argv[2];
	if (argc == 3 && message[0] != 0 && pid_server)
	{
		if (message[0] != 0 && pid_server)
		{
			send_message(message, pid_server);
			send_end_message(pid_server);
		}	
	}
	else
		error_management(2);
	while (!g_message_received)
		pause();
	ft_printf("Message received.\n");
	return (0);
}
