/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:39:37 by myanez-p          #+#    #+#             */
/*   Updated: 2023/04/24 11:13:08 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Fonction que retourne le résultat d'une puissance */

int	ft_pow(int base, int power)
{
	int	base_i;

	base_i = base;
	if (power == 0)
		base = 1;
	while ((power - 1) > 0)
	{
		base *= base_i;
		power --;
	}
	return (base);
}
