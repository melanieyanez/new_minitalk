/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:05:22 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/24 11:25:58 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction localisant la dernière occurence du caractère c */
/* dans la chaîne de caractères */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((char)c == s[i])
			return ((char *) &s[i]);
		i --;
	}
	return (NULL);
}
