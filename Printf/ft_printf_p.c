/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 09:46:22 by abrun             #+#    #+#             */
/*   Updated: 2021/01/20 11:38:59 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_p_normal(long long int n, int n_chr, char *num)
{
	int			puissance;
	int			res;
	int			n_point;

	n_point = get_flag_point(num);
	puissance = ft_putpui(n, 16) + 2;
	res = get_res(puissance, n_chr);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
	if (p_p(num, n, n_point))
		ft_putadress_fd(n, "0123456789abcdef", 1);
	else
	{
		ft_putstr_fd("0x", 1);
		res--;
	}
	while (n_chr++ < n_point && puissance++ < n_point + 3)
	{
		res++;
		ft_putchar_fd(48, 1);
	}
	return (res);
}

int		print_p_neg(long long int n, int n_chr, char *num)
{
	int			puissance;
	int			res;
	int			n_point;

	n_point = get_flag_point(num);
	puissance = ft_putpui(n, 16) + 2;
	res = get_res(puissance, n_chr);
	if (p_p(num, n, n_point))
		ft_putadress_fd(n, "0123456789abcdef", 1);
	else
	{
		ft_putstr_fd("0x", 1);
		res--;
	}
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
	return (res);
}

int		print_p(long long int n, char *num)
{
	int		n_chr;

	n_chr = get_flag_n(num);
	if (!is_flag_minus(num))
		return (print_p_normal(n, n_chr, num));
	else
		return (print_p_neg(n, n_chr, num));
}
