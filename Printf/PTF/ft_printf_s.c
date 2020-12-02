/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:41:21 by abrun             #+#    #+#             */
/*   Updated: 2020/12/02 14:20:20 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_s_normal(char *s, int n_chr, char *num)
{
	int			n_point;
	int			filler;
	int			puissance;

	puissance = ft_strlen(s);
	n_point = get_flag_point(num);
	filler = 32;
	if (is_flag_zero(num))
		filler = '0';
	if (is_flag_point(num) && puissance > n_point)
		puissance = n_point;
	n_chr = print_c_3(n_chr, puissance, filler);
	print_s_npt(n_point, s, puissance, num);
}

void		print_s_neg(char *s, int n_chr, char *num)
{
	int			puissance;
	int			n_point;

	puissance = ft_strlen(s);
	n_point = get_flag_point(num);
	if (is_flag_point(num) && puissance > n_point)
		puissance = n_point;
	print_s_npt(n_point, s, puissance, num);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
}

void		print_s(char *s, char *num)
{
	int		n_chr;

	n_chr = get_flag_n(num);
	if (num[0] != '-')
		print_s_normal(s, n_chr, num);
	else
		print_s_neg(s, n_chr, num);
}
