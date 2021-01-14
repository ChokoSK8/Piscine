/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:50:58 by abrun             #+#    #+#             */
/*   Updated: 2021/01/14 17:41:39 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_c_normal(int n, int n_chr, char *num)
{
	int			n_point;
	int			filler;
	int			puissance;
	int			res;

	puissance = 1;
	n_point = get_flag_point(num);
	res = get_res(puissance, n_chr);
	filler = 32;
	if (is_flag_zero(num))
		filler = '0';
	n_chr = print_c_3(n_chr, puissance, filler);
	if (p_p(num, n, n_point))
		ft_putchar_fd(n, 1);
	return (res);
}

int		print_c_neg(int n, int n_chr, char *num)
{
	int			puissance;
	int			n_point;
	int			filler;
	int			res;

	puissance = 1;
	n_point = get_flag_point(num);
	res = get_res(puissance, n_chr);
	filler = get_filler(num, n_point);
	if (p_p(num, n, n_point))
		ft_putchar_fd(n, 1);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
	return (res);
}

int		print_c(int n, char *num)
{
	int		n_chr;

	n_chr = get_flag_n(num);
	if (!is_flag_minus(num))
		return (print_c_normal(n, n_chr, num));
	else
		return (print_c_neg(n, n_chr, num));
}
