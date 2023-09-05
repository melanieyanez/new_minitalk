/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:26:27 by myanez-p          #+#    #+#             */
/*   Updated: 2023/04/13 11:59:54 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ------------------------------------------------------------------------ */
/* Permet de sélectionner la fonction à utiliser */
/* selon l'option donnée à la suite du % */

int	conv_select(const char c, va_list arg_list)
{
	if (c == '%')
		return (print_char(c));
	else if (c == 'd' || c == 'i')
		return (print_number(va_arg(arg_list, int)));
	else if (c == 'x')
		return (print_hexa_number(va_arg(arg_list, unsigned int), BHMIN));
	else if (c == 'X')
		return (print_hexa_number(va_arg(arg_list, unsigned int), BHMAJ));
	else if (c == 'u')
		return (print_unsigned_number(va_arg(arg_list, unsigned int)));
	else if (c == 'c')
		return (print_char(va_arg(arg_list, int)));
	else if (c == 's')
		return (print_str(va_arg(arg_list, char *)));
	else if (c == 'p')
		return (print_str("0x") + print_ptr(va_arg(arg_list, ULL), BHMIN));
	else
		write(1, &c, 1);
	return (1);
}

/* Fonction utilisant une va_list pour utiliser un nombre variable */
/* d'arguments de type non-défini */

int	ft_printf(const char *arg0, ...)
{
	va_list	arg_list;
	int		i;
	int		len;

	va_start(arg_list, arg0);
	i = 0;
	len = 0;
	while (arg0[i])
	{
		if (arg0[i] == '%')
		{
			len += conv_select(arg0[i + 1], arg_list);
			i ++;
		}
		else
			len += write(1, &arg0[i], 1);
		i ++;
	}
	va_end(arg_list);
	return (len);
}
