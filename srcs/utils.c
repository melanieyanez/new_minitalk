/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:38:42 by myanez-p          #+#    #+#             */
/*   Updated: 2023/09/11 16:37:56 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	arguments_checker(char **argv, int pid_server, char *message)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) == 1)
			i ++;
		else
			error_management(2);
	}
	if (message[0] == 0 || !pid_server)
		error_management(2);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	error_management(int type)
{
	if (type == 0)
		ft_printf("Error: Failed to send a signal to the server.\n");
	else if (type == 1)
		ft_printf("Error: Failed to set up signal handling for confirmation.\n");
	else if (type == 2)
	{
		ft_printf("Error: Invalid command line arguments.\n");
		ft_printf("Please enter: ./client <pid_server> <your message>\n");
	}
	else if (type == 3)
		ft_printf("Error: Failed to send confirmation signal to the client.\n");
	else if (type == 4)
		ft_printf("Error: Failed to set up signal handling for the server.\n");
	else if (type == 5)
		ft_printf("Error: Failed to send the end signal to the server.\n");
	exit(1);
}
