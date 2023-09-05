/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:03:46 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/24 11:19:13 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction retournant une partie de la chaîne de caractères */
/* débutant à l'index start et de longeur len */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*result;

	if (start > ft_strlen(s))
		len = 0;
	if (ft_strlen(s) - start > len)
		result = malloc(sizeof(char) * (len + 1));
	else
		result = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && start + i < ft_strlen(s))
	{
		result[i] = s[start + i];
		i ++;
	}
	result[i] = '\0';
	return (result);
}
