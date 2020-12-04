/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:58:22 by abrun             #+#    #+#             */
/*   Updated: 2020/12/04 16:58:38 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			browse_s(const char *s, int *n_chr)
{
	int		c;

	c = 0;
	while (*s && *s != '%')
	{
		ft_putchar_fd(*s, 1);
		c++;
		s++;
	}
	*n_chr += c;
	return (c);
}

int			pass_the_spaces(const char *s, int *c_num, char *num)
{
	int		c;

	c = 1;
	s++;
	while (*s == ' ' && *s)
	{
		s++;
		c++;
		*c_num = 1;
		num[0] = ' ';
	}
	if (c == 1)
		num[0] = 0;
	return (c);
}

int			browse_2nd_step(const char *s, char *num, int *c_num)
{
	int		c;

	c = 0;
	while ((*s == '-' || *s == '+' || *s == 32 || *s == '0') && *s)
	{
		if (*s == '-')
			*num++ = '-';
		else if (*s == '+')
			*num++ = '+';
		else if (*s == '+')
			*num++ = ' ';
		else
			*num++ = '0';
		c++;
		s++;
	}
	*c_num += c;
	return (c);
}

int			browse_3rd_step(const char *s, char *num, int c_num, va_list lst)
{
	int		counter;

	counter = 0;
	while ((ft_isdigit(*s) || *s == '.' || *s == '*') && *s)
	{
		if (*s == '*')
		{
			if (!(fill_num_star(num, &c_num, va_arg(lst, int))))
				return (0);
			s++;
		}
		else
			num[c_num++] = *s++;
		counter++;
	}
	num[c_num] = 0;
	return (counter);
}
