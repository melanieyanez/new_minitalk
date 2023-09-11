/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:44:03 by myanez-p          #+#    #+#             */
/*   Updated: 2023/09/11 16:37:36 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

//client.c

void	receive_confirmation(int num_signal);
void	send_end_message(int pid_server);
void	send_message(char *message, int pid_server);

//server.c

char	*add_char_to_message(char *message, int c);
void	receive_message(int num_signal, siginfo_t *info, void *context);

//utils.c

void	error_management(int type);
void	arguments_checker(char **argv, int pid_server, char *message);

#endif