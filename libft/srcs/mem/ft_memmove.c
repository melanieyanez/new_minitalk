/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:33:32 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/13 12:24:58 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction qui copie une série d'octets dans une autre zone de mémoire */
/* mais en évitant les overlaps */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	if (dst > src && src + len > dst)
	{
		i = len - 1;
		while (len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i --;
			len --;
		}
	}
	else
	{
		i = 0;
		while (len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i ++;
			len --;
		}
	}
	return (dst);
}
