/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:16:48 by abrun             #+#    #+#             */
/*   Updated: 2020/12/02 11:19:59 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			print_c_3(int n_chr, int puissance, int filler)
{
	while (n_chr > puissance)
	{
		ft_putchar_fd(filler, 1);
		n_chr--;
	}
	return (n_chr);
}
