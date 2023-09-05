/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:57:00 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/06 12:26:06 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ------------------------------------------------------------------------ */
/* Pour imprimer une chaîne de caractères */

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (print_str("(null)"));
	while (str[i])
	{
		print_char(str[i]);
		i ++;
	}
	return (i);
}
