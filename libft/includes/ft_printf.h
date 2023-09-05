/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:06:32 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/24 13:10:30 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define ULL unsigned long long
# define BHMIN "0123456789abcdef"
# define BHMAJ "0123456789ABCDEF"

int		ft_printf(const char *arg0, ...);
int		print_char(char c);
int		print_str(char *str);
int		print_number(int n);
int		print_unsigned_number(unsigned int n);
int		print_hexa_number(unsigned int n, char *base);
int		print_ptr(unsigned long long n, char *base);

#endif