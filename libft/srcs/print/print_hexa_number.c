/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:41:48 by myanez-p          #+#    #+#             */
/*   Updated: 2023/03/06 14:51:04 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ------------------------------------------------------------------------ */
/* Pour renvoyer le nombre de charactères imprimés */

int	hnbrlen(unsigned int n, char *base)
{
	unsigned int	base_len;
	int				size;

	base_len = (unsigned int) ft_strlen(base);
	size = 0;
	while (n >= base_len)
	{
		n = n / base_len;
		size ++;
	}
	size ++;
	return (size);
}

/* ------------------------------------------------------------------------ */
/* Pour imprimer un nombre en hexadécimal */

int	print_hexa_number(unsigned int n, char *base)
{
	unsigned int	base_len;

	base_len = (unsigned int) ft_strlen(base);
	if (n >= base_len)
	{
		print_hexa_number((n / base_len), base);
		print_char(base[n % base_len]);
	}
	else
		print_char(base[n]);
	return (hnbrlen(n, base));
}

/* ------------------------------------------------------------------------ */
/* Exemples */
/* 0123456789abcdef */

/*
hexa = dec
f = 15
10 = 16
11 = 17
12 = 18
13 = 19
14 = 20
19 = 25
1a = 26
1f = 31
20 = 32
*/

/* 20 en décimal */

/*
20 // 16 = 1
20 % 16 = 4, base[4] = 4
14 en hexadécimal
*/

/* 100 en décimal */

/*
100 // 16 = 6 (6e element de la base)
100 % 16 = 4 (4e element de la base)
64 en hexadécimal
*/

/* 1000 en décimal */

/*
1000 // 16 = 62
je renvoie 62 dans ma fonction
1000 % 16 = 8
print dans le terminal
n = 62 // 16 = 3 (le prochain n)
je renvoie 3 dans ma fonction
62 % 16 = 14
print dans le terminal
n = 3
3 // 16 = 0
du coup stop
(3 % 16)3 (60 % 16)E  (1000 % 16)8 3E8 en hexadécimal
*/

/* 2328 en décimal */

/*
2328 // 16 = 145
je renvoie 145
2328 % 16 = 8
print dans le terminal
145 // 16 = 9
145 %  16 = 1
print dans le terminal
918 en hexadécimal
*/