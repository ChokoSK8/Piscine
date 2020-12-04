/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:29:44 by abrun             #+#    #+#             */
/*   Updated: 2020/12/04 17:56:15 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_d_2(int filler, int n)
{
	if (filler == '0' && n < 0)
		ft_putchar_fd('-', 1);
}

int			print_d_1(int filler, int space_plus, int n)
{
	if (filler == '0' && space_plus == '+' && n >= 0)
		ft_putchar_fd('+', 1);
	print_d_2(filler, n);
	if (space_plus && n < 0)
		return (1);
	return (0);
}

int			print_d_3(int n_chr, int puissance, int n_point, int filler)
{
	while (n_chr > puissance && n_chr > n_point)
	{
		ft_putchar_fd(filler, 1);
		n_chr--;
	}
	return (n_chr);
}

int			p_p(char *num, int n, int n_point)
{
	if (is_flag_point(num) && !n && !n_point)
		return (0);
	return (1);
}

int			print_d_n_1(int n_point, int n)
{
	if (n_point && n < 0)
	{
		ft_putchar_fd('-', 1);
		return (-1);
	}
	return (0);
}
