/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:38:42 by myanez-p          #+#    #+#             */
/*   Updated: 2023/09/06 18:53:17 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
