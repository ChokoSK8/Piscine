/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:50:58 by abrun             #+#    #+#             */
/*   Updated: 2020/12/02 11:44:01 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_c_normal(int n, int n_chr, char *num)
{
	int			n_point;
	int			filler;
	int			puissance;

	puissance = 1;
	n_point = get_flag_point(num);
	filler = 32;
	if (is_flag_zero(num))
		filler = '0';
//	n_chr = print_d_3(n_chr, puissance, n_point, filler);
//	puissance = print_d_5(n_point, puissance);
	n_chr = print_c_3(n_chr, puissance, filler);
	if (print_point(num, n, n_point))
		ft_putchar_fd(n, 1);
//	if (!print_point(num, n, n_point) && n_chr > 0)
//		ft_putchar_fd(filler, 1);
}

void		print_c_neg(int n, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			filler;

	puissance = 1;
	n_point = get_flag_point(num);
	filler = get_filler(num);
//	puissance = print_d_n_2(puissance, n_point);
	if (print_point(num, n, n_point))
		ft_putchar_fd(n, 1);
//	if (!print_point(num, n, n_point) && n_chr > 0)
//		ft_putchar_fd(32, 1);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
}

void		print_c(int n, char *num)
{
	int		n_chr;

	n_chr = get_flag_n(num);
	if (num[0] != '-')
		print_c_normal(n, n_chr, num);
	else
		print_c_neg(n, n_chr, num);
}
