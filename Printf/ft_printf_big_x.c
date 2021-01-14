/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_big_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 09:27:29 by abrun             #+#    #+#             */
/*   Updated: 2021/01/14 18:51:20 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_bigx_6(char *num, unsigned int n, int n_point)
{
	if (p_p(num, n, n_point))
		ft_putnbr_base_fd(n, "0123456789ABCDEF", 1);
}

int			print_bigx_normal(unsigned int n, int n_chr, char *num)
{
	int				puissance;
	int				n_point;
	int				filler;
	int				res;

	puissance = ft_putpui(n, 16);
	n_point = get_flag_point(num);
	res = get_res_npt(puissance, n_chr, n_point, 0);
	!p_p(num, n, n_point) && !n_chr ? res -= 1 : res;
	filler = get_filler(num, n_point);
	print_x_2(filler, n);
	n_chr = print_d_3(n_chr, puissance, n_point, filler);
	puissance = print_d_5(n_point, puissance, n, filler);
	print_bigx_6(num, n, n_point);
	if (!p_p(num, n, n_point) && n_chr > 0)
		ft_putchar_fd(filler, 1);
	return (res);
}

int			print_bigx_neg(unsigned int n, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			filler;
	int			res;

	puissance = ft_putpui(n, 16);
	n_point = get_flag_point(num);
	res = get_res_npt(puissance, n_chr, n_point, 0);
	!p_p(num, n, n_point) && !n_chr ? res -= 1 : res;
	filler = get_filler(num, n_point);
	n_chr += print_x_n_1(n_point, n);
	puissance = print_d_n_2(puissance, n_point);
	if (p_p(num, n, n_point))
		ft_putnbr_base_fd(n, "0123456789ABCDEF", 1);
	if (!p_p(num, n, n_point) && n_chr > 0)
		ft_putchar_fd(32, 1);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
	return (res);
}

int			print_bigx(unsigned int n, char *num)
{
	int		n_chr;

	n_chr = get_flag_n(num);
	if (!is_flag_minus(num))
		return (print_bigx_normal(n, n_chr, num));
	else
		return (print_bigx_neg(n, n_chr, num));
}
