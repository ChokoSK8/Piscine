/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:42:09 by abrun             #+#    #+#             */
/*   Updated: 2020/12/04 16:42:30 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putpui(long long int nbr, int base_len)
{
	long long int	res;
	long int		puissance;
	long long int	base;

	puissance = 0;
	res = nbr;
	base = base_len;
	if (res < 0)
	{
		puissance++;
		res = -res;
	}
	while (res >= base)
	{
		puissance++;
		base *= base_len;
	}
	return (puissance + 1);
}
