/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 09:46:22 by abrun             #+#    #+#             */
/*   Updated: 2020/12/04 14:32:11 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_p_normal(long long int n, int n_chr)
{
	int				puissance;
	int				res;

	puissance = ft_putpui(n, 16) + 2;
	res = get_res(puissance, n_chr);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
	ft_putadress_fd(n, "0123456789abcdef", 1);
	return (res);
}

int		print_p_neg(long long int n, int n_chr)
{
	int			puissance;
	int			res;

	puissance = ft_putpui(n, 16) + 2;
	res = get_res(puissance, n_chr);
	ft_putadress_fd(n, "0123456789abcdef", 1);
	while (puissance++ < n_chr)
		ft_putchar_fd(32, 1);
	return (res);
}

int		print_p(long long int n, char *num)
{
	int		n_chr;

	n_chr = get_flag_n(num);
	if (!is_flag_minus(num))
		return (print_p_normal(n, n_chr));
	else
		return (print_p_neg(n, n_chr));
}
