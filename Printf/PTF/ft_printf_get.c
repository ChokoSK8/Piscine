/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:35:14 by abrun             #+#    #+#             */
/*   Updated: 2020/12/02 16:45:23 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

int		ft_putpui(long long int nbr, int base_len)
{
	long long int	res;
	long int		puissance;
	long long int	base;

	puissance = 0;
	res = nbr;
	base = base_len;
	if (res < 0)
	{
		puissance++;
		res = -res;
	}
	while (res >= base)
	{
		puissance++;
		base *= base_len;
	}
	return (puissance + 1);
}

int		get_flag_n(char *num)
{
	size_t		start;
	int			n;

	start = ft_strlen(num) - 1;
	if (is_flag_point(num))
	{
		while (num[start] != '.' && start >= 0)
			start--;
		start--;
	}
	while (ft_isdigit(num[start]) && start >= 0)
		start--;
	n = ft_atoi(num + start + 1);
	return (n);
}

int		get_flag_point(char *num)
{
	int			point;
	size_t		start;

	start = 0;
	point = 0;
	if (is_flag_point(num))
	{
		while (num[start] != '.' && num[start])
			start++;
		point = ft_atoi(num + start + 1);
	}
	return (point);
}

int		get_space_or_plus(char *num)
{
	int		counter;

	counter = 0;
	while (num[counter] && num[counter] != '+')
		counter++;
	if (num[counter])
		return ('+');
	counter = 0;
	while (num[counter] && num[counter] != ' ')
		counter++;
	if (num[counter])
		return (32);
	return (0);
}

int		get_filler(char *num)
{
	if (is_flag_zero(num) && !is_flag_point(num))
		return ('0');
	return (32);
}
