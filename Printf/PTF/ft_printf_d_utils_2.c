/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:19:09 by abrun             #+#    #+#             */
/*   Updated: 2020/12/02 11:39:37 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			print_d_n_2(int puissance, int n_point)
{
	while (puissance < n_point)
	{
		ft_putchar_fd('0', 1);
		puissance++;
	}
	return (puissance);
}

int			print_d_5(int n_point, int puissance)
{
	while (n_point > puissance)
	{
		ft_putchar_fd('0', 1);
		puissance++;
	}
	return (puissance);
}

void		print_d_4(int n_point, int puissance, int n, int filler)
{
	if (n_point > puissance && n < 0 && filler != '0')
		ft_putchar_fd('-', 1);
}

void		print_d_6(char *num, int n, int n_point, long int nbr)
{
	if (print_point(num, n, n_point))
		ft_putnbr_fd(nbr, 1);
}
