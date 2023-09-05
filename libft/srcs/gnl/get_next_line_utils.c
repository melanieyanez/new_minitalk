/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:44:28 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/24 13:09:44 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction pour chercher un passage à la ligne dans une chaîne de caractères */

int	check_newline(const char *str, char c)
{
	if (str == NULL)
		return (0);
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (1);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction qui permet d'enlever de la stash ce qui a deja été extrait */

void	clean_stash(char **stash)
{
	char	*clean_stash;
	int		i;
	int		j;

	clean_stash = NULL;
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i ++;
	if ((*stash)[i] && (*stash)[i] == '\n')
		i ++;
	clean_stash = malloc(sizeof(char) * (ft_strlen(*stash) - i + 1));
	if (clean_stash == NULL)
		return ;
	j = 0;
	while ((*stash)[i])
	{
		clean_stash[j] = (*stash)[i];
		j ++;
		i ++;
	}
	clean_stash[j] = '\0';
	free(*stash);
	*stash = ft_strdup(clean_stash);
	free(clean_stash);
}
