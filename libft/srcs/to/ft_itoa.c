/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:56:54 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/13 12:31:13 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction qui convertit un entier en chaîne de caractères */

int	nbr_len(long int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len = 2;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*result;
	long int	nbr;
	int			i;
	int			len;

	nbr = n;
	len = nbr_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = len - 1;
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr >= 10)
	{
		result[i] = nbr % 10 + 48;
		nbr = nbr / 10;
		i --;
	}
	result[i] = nbr + 48;
	result[len] = '\0';
	return (result);
}
