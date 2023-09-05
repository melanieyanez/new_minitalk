/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:44:24 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/24 13:11:02 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
void	add_to_buffer(int fd, char **stash);
void	add_to_stash(char **stash, char *buffer);
void	extract_line(char *stash, char **line);
void	generate_line(char **line, char *stash);
int		check_newline(const char *str, char c);
void	clean_stash(char **stash);

#endif