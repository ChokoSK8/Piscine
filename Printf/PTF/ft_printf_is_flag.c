/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_is_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:38:01 by abrun             #+#    #+#             */
/*   Updated: 2021/01/12 17:53:10 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_flag_point(char *num)
{
	int		counter;

	counter = 0;
	while (num[counter] && num[counter] != '.')
		counter++;
	if (!num[counter])
		return (0);
	return (1);
}

int		is_flag_zero(char *num)
{
	int		counter;

	counter = 0;
	if (num[0] == '-')
		return (0);
	if (num[counter] == '0')
		return (1);
	while (num[counter])
	{
		if (num[counter] == '0' && !ft_isdigit(num[counter - 1]))
			return (1);
		counter++;
	}
	return (0);
}

int		is_flag_minus(char *num)
{
	int counter;

	counter = 0;
	while (num[counter] == ' ' || num[counter] == '0')
		counter++;
	if (num[counter] && num[counter] == '-')
		return (1);
	return (0);
}
