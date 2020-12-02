/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:12:02 by abrun             #+#    #+#             */
/*   Updated: 2020/12/02 16:48:08 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_u_normal(unsigned int n, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			filler;

	puissance = ft_putpui(n, 10);
	n_point = get_flag_point(num);
	filler = get_filler(num);
	n_chr = print_u_2(n_chr, puissance, n_point, filler);
	puissance = print_d_5(n_point, puissance);
	print_u_3(num, n, n_point);
	if (!print_point_u(num, n, n_point) && n_chr > 0)
		ft_putchar_fd(filler, 1);
}

void		print_u_neg(unsigned int n, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			filler;

	puissance = ft_putpui(n, 10);
	n_point = get_flag_point(num);
	filler = get_filler(num);
	puissance = print_d_n_2(puissance, n_point);
	if (print_point(num, n, n_point))
		ft_putnbr_fd(n, 1);
	if (!print_point_u(num, n, n_point) && n_chr > 0)
		ft_putchar_fd(32, 1);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
}

void		print_u(unsigned int n, char *num)
{
	int		n_chr;

	n_chr = get_flag_n(num);
	if (num[0] != '-')
		print_u_normal(n, n_chr, num);
	else
		print_u_neg(n, n_chr, num);
}