/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:46:48 by abrun             #+#    #+#             */
/*   Updated: 2021/01/26 09:35:23 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			browse_all(const char *s, int *c_num, char *num, va_list lst)
{
	int	counter;

	counter = pass_the_spaces(s, c_num, num);
	counter += browse_2nd_step(s + counter, num, c_num);
	num[0] && *c_num == 0 ? *c_num += 1 : *c_num;
	counter += browse_3rd_step(s + counter, num, *c_num, lst);
	return (counter);
}

int			error_malloc(char *num, int n_chr, va_list lst)
{
	va_end(lst);
	free(num);
	return (n_chr);
}
