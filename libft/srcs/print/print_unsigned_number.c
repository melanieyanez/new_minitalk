/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:59:22 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/06 13:08:39 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ------------------------------------------------------------------------ */
/* Pour renvoyer le nombre de charactères imprimés */

int	unbrlen(unsigned int n)
{
	int	size;

	size = 0;
	while (n >= 10)
	{
		n = n / 10;
		size ++;
	}
	size ++;
	return (size);
}

/* ------------------------------------------------------------------------ */
/* Pour imprimer un nombre entier non-signé */

int	print_unsigned_number(unsigned int n)
{
	unsigned long int	nbr;

	nbr = n;
	if (nbr >= 10)
		print_unsigned_number(nbr / 10);
	print_char((nbr % 10 + 48));
	return (unbrlen(n));
}
