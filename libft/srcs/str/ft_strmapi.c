/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:05:40 by myanez-p          #+#    #+#             */
/*   Updated: 2023/04/24 11:23:59 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction créant une nouvelle chaîne en appliquant */
/* une fonction à chaque caractère de la chaîne de base */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	result = malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i ++;
	}
	result[i] = '\0';
	return (result);
}
