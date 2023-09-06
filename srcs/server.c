/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:48:49 by myanez-p          #+#    #+#             */
/*   Updated: 2023/09/06 15:20:37 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Permet d'ajouter chaque caractère reçu au message */

char	*add_char_to_message(char *message, int c)
{
	char	*result;
	int		i;
	int		j;

	result = malloc((ft_strlen(message) + 2) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (message[i])
	{
		result[j] = message[i];
		i ++;
		j ++;
	}
	result[j] = c;
	result[j + 1] = '\0';
	free(message);
	return (result);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Handler des signaux reçus */
/* qui permet de transformer le binaire en caractères */

void	receive_message(int num_signal, siginfo_t *info, void *context)
{
	static char	*message;
	static char	current_char;
	static int	count;

	(void)context;
	(void)info;
	if (!message)
		message = ft_strdup("");
	if (num_signal == SIGUSR2)
		current_char |= (1 << (7 - count));
	count ++;
	if (count == 8)
	{
		message = add_char_to_message(message, current_char);
		if (current_char == '\0')
		{
			ft_printf("%s\n", message);
			kill(info->si_pid, SIGUSR1);
			free(message);
			message = NULL;
		}
		count = 0;
		current_char = 0;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main(void)
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_sigaction = receive_message;
	s_sigaction.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&s_sigaction.sa_mask);
	ft_printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	if (sigaction(SIGUSR1, &s_sigaction, NULL) == -1
		|| sigaction(SIGUSR2, &s_sigaction, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
