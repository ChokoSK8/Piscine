/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:58:07 by abrun             #+#    #+#             */
/*   Updated: 2020/12/04 14:56:42 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"
#include <stdio.h>

int		ft_pow_int(int n, int p)
{
	int res;

	if (p == 0)
		return (1);
	res = n;
	p--;
	while (p)
	{
		res *= n;
		p--;
	}
	return (res);
}

int		print_va_arg(char c, va_list lst, char *num)
{
	if (c == 's')
		return (print_s(va_arg(lst, char *), num));
	else if (c == 'd' || c == 'i')
		return (print_d(va_arg(lst, int), num));
	else if (c == 'c')
		return (print_c(va_arg(lst, int), num));
	else if (c == 'u')
		return (print_u(va_arg(lst, unsigned int), num));
	else if (c == 'x')
		return (print_x(va_arg(lst, long long int), num));
	else if (c == 'X')
		return (print_bigX(va_arg(lst, long long int), num));
	else if (c == 'p')
		return (print_p(va_arg(lst, long long int), num));
	else if (c == '%')
	{
		return (print_c('%', num));
	}
	return (0);
}

int			fill_num_last_step(int puissance, char *num, int n, int counter)
{
	while (puissance)
	{
		num[counter] = n / ft_pow(10, puissance - 1) + '0';
		puissance--;
		n -= ((n / ft_pow(10, puissance)) * ft_pow(10, puissance));
		counter++;
	}
	return (counter);
}

int			fill_num_star_neg(char *num, int num_len, int n, int puissance)
{
	char		*tmp;
	int			counter;

	if (!(tmp = malloc(num_len + 1)))
	{
		free(tmp);
		return (0);
	}
	counter = 1;
	while (num[counter - 1])
	{
		tmp[counter] = num[counter - 1];
		counter++;
	}
	tmp[0] = '-';
	tmp[counter] = 0;
	counter = -1;
	while (tmp[++counter])
		num[counter] = tmp[counter];
	n *= -1;
	counter = fill_num_last_step(puissance, num, n, counter);
	free(tmp);
	return (counter);
}

int			fill_num_star_bis(char *num, int *c_num, int n)
{
	int		puissance;
	int		counter;

	counter = *c_num;
	puissance = ft_putpui(n, 10);
	n < 0 && is_flag_minus(num) ? n *= -1 : n;
	n < 0 ? puissance-- : puissance;
	if (n < 0)
	{
		num[counter++] = '-';
		n *= -1;
		counter = fill_num_last_step(puissance, num, n, counter);
	}
	else
	{
		counter = *c_num;
		counter = fill_num_last_step(puissance, num, n, counter);
	}
	*c_num = counter;
	num[counter] = 0;
	return (1);
}

int		ft_printf(const char *s, ...)
{
	va_list		lst;
	int			counter;
	char		*num;
	int			c_num;
	int			n_chr;

	n_chr = 0;
	va_start(lst, s);
	counter = 0;
	while (s[counter])
	{
		num = malloc(100);
		num[0] = 0;
		while (s[counter] && s[counter] != '%')
		{
			n_chr++;
			ft_putchar_fd(s[counter], 1);
			counter++;
		}
		if (s[counter] && s[counter] == '%')
		{
			counter++;
			c_num = 0;
			while (s[counter] == ' ' && s[counter])
			{
				num[0] = ' ';
				c_num = 1;
				counter++;
			}
			while ((s[counter] == '-' || s[counter] == '+' || s[counter] == 32 || s[counter] == '0') && s[counter])
			{
				if (s[counter] == '-')
					num[c_num++] = '-';
				else if (s[counter] == '+')
					num[c_num++] = '+';
				else if (s[counter] == ' ')
					num[c_num++] = ' ';
				else
					num[c_num++] = '0';
				counter++;
			}
			num[0] && c_num == 0 ? c_num++ : c_num;
			while((ft_isdigit(s[counter]) || s[counter] == '.' || s[counter] == '*') && s[counter])
			{
				if (s[counter] == '*')
				{
					if (!(fill_num_star_bis(num, &c_num, va_arg(lst, int))))
						return (0);
					counter++;
				}
				else
					num[c_num++] = s[counter++];
			}
			num[c_num] = 0;
			n_chr += print_va_arg(s[counter], lst, num);
			s[counter] ? counter++ : counter;
			free(num);
		}
	}
	va_end(lst);
	return (n_chr);
}
