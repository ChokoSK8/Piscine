/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:41:20 by abrun             #+#    #+#             */
/*   Updated: 2020/12/04 16:41:58 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int		get_flag_point_s(char *num, int puissance)
{
	int			point;
	size_t		start;

	start = 0;
	point = -1;
	if (!is_flag_point(num))
		return (point);
	else
	{
		while (num[start] != '.' && num[start])
			start++;
		point = ft_atoi(num + start + 1);
	}
	if (puissance < 0 && point < 0)
		point = 6;
	return (point);
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
