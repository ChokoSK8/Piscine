/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:00:46 by abrun             #+#    #+#             */
/*   Updated: 2021/01/14 17:40:07 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			get_pui_n_chr(int *n_chr, int n)
{
	int		puissance;
	int		chr;

	chr = *n_chr;
	puissance = ft_putpui(n, 10);
	n < 0 ? chr-- : chr;
	n < 0 ? puissance-- : puissance;
	*n_chr = chr;
	return (puissance);
}

int			print_d_normal(int space_plus, int n, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			filler;
	long int	nbr;
	int			res;

	nbr = n;
	n_point = get_flag_point(num);
	res = get_res_npt_pos(n, n_chr, n_point, space_plus);
	!p_p(num, n, n_point) && n_chr == 0 && !space_plus ? res = 0 : res;
	!p_p(num, n, n_point) && n_chr == 0 && space_plus ? res = 1 : res;
	puissance = get_pui_n_chr(&n_chr, n);
	filler = get_filler(num, n_point);
	n < 0 && (filler == '0' || n_point > puissance) ? nbr *= -1 : nbr;
	n_chr += print_d_1(filler, space_plus, n);
	n_chr = print_d_3(n_chr, puissance, n_point, filler);
	if (space_plus == '+' && filler != '0' && p_p(num, n, n_point) && n >= 0)
		ft_putchar_fd(space_plus, 1);
	puissance = print_d_5(n_point, puissance, n, filler);
	print_d_6(num, n, n_point, nbr);
	if (!p_p(num, n, n_point) && n_chr > 0)
		ft_putchar_fd(filler, 1);
	if (space_plus == '+' && !p_p(num, n, n_point) && n >= 0)
		ft_putchar_fd('+', 1);
	return (res);
}

int			get_nbr_pui(long int *nbr, int n_point)
{
	int			puissance;
	long int	n;

	n = *nbr;
	puissance = ft_putpui(n, 10);
	n < 0 && n_point ? puissance-- : puissance;
	n < 0 && n_point ? n *= -1 : n;
	*nbr = n;
	return (puissance);
}

int			print_d_neg(int space_plus, int n, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			filler;
	long int	nbr;
	int			res;

	nbr = n;
	n_point = get_flag_point(num);
	puissance = get_nbr_pui(&nbr, n_point);
	res = get_res_npt_neg(n, n_chr, n_point, space_plus);
	!p_p(num, n, n_point) && n_chr == 0 && !space_plus ? res = 0 : res;
	!p_p(num, n, n_point) && n_chr == 0 && space_plus ? res = 1 : res;
	filler = get_filler(num, n_point);
	n_chr += print_d_n_1(n_point, n);
	if (space_plus == '+' && n >= 0)
		ft_putchar_fd(space_plus, 1);
	if (space_plus && n < 0)
		n_chr++;
	puissance = print_d_n_2(puissance, n_point);
	print_d_6(num, n, n_point, nbr);
	if (!p_p(num, n, n_point) && n_chr > 0)
		ft_putchar_fd(32, 1);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
	return (res);
}

int			print_d(int n, char *num)
{
	int		space_plus;
	int		n_chr;

	n_chr = get_flag_n(num);
	space_plus = get_space_or_plus(num);
	space_plus && n_chr ? n_chr-- : n_chr;
	if (space_plus == 32 && n >= 0)
		ft_putchar_fd(32, 1);
	if (!is_flag_minus(num))
		return (print_d_normal(space_plus, n, n_chr, num));
	else
		return (print_d_neg(space_plus, n, n_chr, num));
}
