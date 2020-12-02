/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:00:46 by abrun             #+#    #+#             */
/*   Updated: 2020/12/02 10:57:40 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_d_normal(int space_plus, int n, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			filler;
	long int	nbr;

	nbr = n;
	puissance = ft_putpui(n, 10);
	n < 0 ? puissance-- : puissance;
	n < 0 ? n_chr-- : n_chr;
	n_point = get_flag_point(num);
	filler = get_filler(num);
	n < 0 && (filler == '0' || n_point > puissance) ? nbr *= -1 : nbr;
	n_chr += print_d_1(filler, space_plus, n);
	print_d_2(filler, n);
	n_chr = print_d_3(n_chr, puissance, n_point, filler);
	if (space_plus == '+' && filler != '0'
		&& print_point(num, n, n_point) && n >= 0)
		ft_putchar_fd(space_plus, 1);
	print_d_4(n_point, puissance, n, filler);
	puissance = print_d_5(n_point, puissance);
	print_d_6(num, n, n_point, nbr);
	if (!print_point(num, n, n_point) && n_chr > 0)
		ft_putchar_fd(filler, 1);
	if (space_plus == '+' && !print_point(num, n, n_point) && n >= 0)
		ft_putchar_fd('+', 1);
}

void		print_d_neg(int space_plus, int n, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			filler;
	long int	nbr;

	nbr = n;
	puissance = ft_putpui(n, 10);
	n_point = get_flag_point(num);
	n < 0 && n_point ? puissance-- : puissance;
	n < 0 && n_point ? nbr *= -1 : nbr;
	filler = get_filler(num);
	n_chr += print_d_n_1(n_point, n);
	if (space_plus == '+' && n >= 0)
		ft_putchar_fd(space_plus, 1);
	if (space_plus && n < 0)
		n_chr++;
	puissance = print_d_n_2(puissance, n_point);
	if (print_point(num, n, n_point))
		ft_putnbr_fd(nbr, 1);
	if (!print_point(num, n, n_point) && n_chr > 0)
		ft_putchar_fd(32, 1);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
}

void		print_d(int n, char *num)
{
	int		space_plus;
	int		n_chr;

	n_chr = get_flag_n(num);
	space_plus = get_space_or_plus(num);
	space_plus && n_chr ? n_chr-- : n_chr;
	if (space_plus == 32 && n >= 0)
		ft_putchar_fd(32, 1);
	if (num[0] != '-')
		print_d_normal(space_plus, n, n_chr, num);
	else
		print_d_neg(space_plus, n, n_chr, num);
}
