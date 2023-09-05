/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:53:20 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/24 11:31:44 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction concaténant deux chaînes de caractères en s'assurant que */
/* le résultat terminera par 0 en fixant la taille de la dest */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	i = 0;
	if (dstsize != 0 && dst_len < dstsize)
	{
		while (src[i] != '\0' && i < dstsize - dst_len - 1)
		{
			dst[dst_len + i] = src[i];
			i ++;
		}
		dst[dst_len + i] = '\0';
	}
	if (dstsize < dst_len)
		return (dstsize + ft_strlen(src));
	return (dst_len + ft_strlen(src));
}
