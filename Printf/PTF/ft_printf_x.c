/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:11:09 by abrun             #+#    #+#             */
/*   Updated: 2020/12/02 17:36:21 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_x_6(char *num, long long int n, int n_point, long int nbr)
{
	if (print_point(num, n, n_point))
		ft_putnbr_base_fd(nbr, "0123456789abcdef", 1);
}

void		print_x_normal(long long int n, int n_chr, char *num)
{
	int				puissance;
	int				n_point;
	int				filler;
	long long int	nbr;

	nbr = n;
	puissance = ft_putpui(n, 16);
	n < 0 ? puissance-- : puissance;
	n < 0 ? n_chr-- : n_chr;
	n_point = get_flag_point(num);
	filler = get_filler(num);
	n < 0 && (filler == '0' || n_point > puissance) ? nbr *= -1 : nbr;
	print_x_2(filler, n);
	n_chr = print_d_3(n_chr, puissance, n_point, filler);
	print_x_4(n_point, puissance, n, filler);
	puissance = print_d_5(n_point, puissance);
	print_x_6(num, n, n_point, nbr);
	if (!print_point(num, n, n_point) && n_chr > 0)
		ft_putchar_fd(filler, 1);
}

void		print_x_neg(long long int n, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			filler;
	long int	nbr;

	nbr = n;
	puissance = ft_putpui(n, 16);
	n_point = get_flag_point(num);
	n < 0 && n_point ? puissance-- : puissance;
	n < 0 && n_point ? nbr *= -1 : nbr;
	filler = get_filler(num);
	n_chr += print_x_n_1(n_point, n);
	puissance = print_d_n_2(puissance, n_point);
	if (print_point(num, n, n_point))
		ft_putnbr_base_fd(nbr, "0123456789abcedf", 1);
	if (!print_point(num, n, n_point) && n_chr > 0)
		ft_putchar_fd(32, 1);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
}

void		print_x(long long int n, char *num)
{
	int		n_chr;

	n_chr = get_flag_n(num);
	if (num[0] != '-')
		print_x_normal(n, n_chr, num);
	else
		print_x_neg(n, n_chr, num);
}
