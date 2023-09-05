/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:02:41 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/24 11:18:14 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction renvoyant la longueur d'une chaîne de caractères */

size_t	ft_strlen(char const *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
		size ++;
	return (size);
}
