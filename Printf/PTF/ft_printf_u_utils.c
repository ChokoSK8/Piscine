/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:14:00 by abrun             #+#    #+#             */
/*   Updated: 2020/12/02 16:48:10 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			print_u_2(int n_chr, int puissance, int n_point, int filler)
{
	while (n_chr > puissance && n_chr > n_point)
	{
		ft_putchar_fd(filler, 1);
		n_chr--;
	}
	return (n_chr);
}

int			print_point_u(char *num, unsigned int n, int n_point)
{
	if (is_flag_point(num) && !n && !n_point)
		return (0);
	return (1);
}

void		print_u_3(char *num,unsigned int n, int n_point)
{
	if (print_point_u(num, n, n_point))
		ft_putnbr_fd(n, 1);
}
