/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:58:07 by abrun             #+#    #+#             */
/*   Updated: 2020/12/02 17:19:07 by abrun            ###   ########.fr       */
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

void	print_u_bis(unsigned int n, char *num)
{
	int	nbr;

	nbr = ft_atoi(num);
	while (nbr-- > ft_putpui(n, 10))
		ft_putchar_fd(' ', 1);
	ft_putunsigned_fd(n, 1);
}

void	print_s_bis(char *s, char *num)
{
	size_t		nbr;

	nbr = ft_atoi(num);
	while (nbr-- > ft_strlen(s))
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(s, 1);
}

void	print_c_bis(int va_arg, char *num)
{
	int		nbr;

	nbr = ft_atoi(num);
	if (nbr >= 0)
	{
		while (nbr-- > 1)
			ft_putchar_fd(32, 1);
		if (ft_isprint(va_arg))
			ft_putchar_fd(va_arg, 1);
	}
	else
	{
		if (ft_isprint(va_arg))
			ft_putchar_fd(va_arg, 1);
		while (nbr++ < -1)
			ft_putchar_fd(32,1);
	}
}

void	print_X(long long int n, char *num)
{
	int		nbr;

	nbr = ft_atoi(num);
	while (nbr-- > ft_putpui(n, 16))
		ft_putchar_fd(' ', 1);
	ft_putnbr_base_fd(n, "0123456789ABCDEF", 1);
}

void	print_x_bis(long long int n, char *num)
{
	int		nbr;

	nbr = ft_atoi(num);
	while (nbr-- > ft_putpui(n, 16))
		ft_putchar_fd(' ', 1);
	ft_putnbr_base_fd(n, "0123456789abcedf", 1);
}

void	print_p(long long int n, char *num)
{
	int		nbr;

	nbr = ft_atoi(num);
	while (nbr-- > 14)
		ft_putchar_fd(' ', 1);
	ft_putadress_fd(n, "0123456789abcdef", 1);
}

int		is_flag_star(char *num)
{
	int counter;

	counter = 0;
	while (num[counter])
	{
		if (num[counter] == '*')
			return (1);
		counter++;
	}
	return (0);
}

void	print_va_arg(char c, va_list lst, char *num)
{
	if (c == 's')
		print_s(va_arg(lst, char *), num);
	else if (c == 'd' || c == 'i')
		print_d(va_arg(lst, int), num);
	else if (c == 'c')
		print_c(va_arg(lst, int), num);
	else if (c == 'u')
		print_u(va_arg(lst, unsigned int), num);
	else if (c == 'x')
		print_x(va_arg(lst, long long int), num);
	else if (c == 'X')
		print_X(va_arg(lst, long long int), num);
	else if (c == 'p')
		print_p(va_arg(lst, long long int), num);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

void	fill_num_star(char *num, int *c_num, int n)
{
	int		puissance;
	char	*tmp;
	size_t	num_len;
	int		counter;

	counter = 1;
	num[*c_num] = 0;
	num_len = ft_strlen(num);
	n < 0 && num[0] == '-' ? n *= -1 : n;
	n < 0 ? puissance-- : puissance;
	puissance = ft_putpui(n, 10);
	if (n < 0)
	{
		tmp = malloc(num_len + 1);
		while (num[counter - 1])
		{
			tmp[counter] = num[counter - 1];
			counter++;
		}
		tmp[0] = '-';
		tmp[counter] = 0;
		counter = 0;
		while (tmp[counter])
		{
			num[counter] = tmp[counter];
			counter++;
		}
		n *= -1;
		while (puissance)
		{
			num[counter] = n / ft_pow(10, puissance - 1) + '0';
			puissance--;
			counter++;
		}
	}
	else
	{
		counter = *c_num;
		while (puissance)
		{
			num[counter] = n / ft_pow(10, puissance - 1) + '0';
			puissance--;
			counter++;
		}
	}
	num[counter] = 0;
	*c_num = counter;
}

int		ft_printf(const char *s, ...)
{
	va_list		lst;
	int			counter;
	char		*num;
	int			c_num;

	va_start(lst, s);
	counter = 0;
	while (s[counter])
	{
		num = malloc(100);
		while (s[counter] && s[counter] != '%')
		{
			ft_putchar_fd(s[counter], 1);
			counter++;
		}
		if (s[counter] && s[counter] == '%')
		{
			counter++;
			c_num = 0;
			while (s[counter + c_num] == ' ' && s[counter])
				num[c_num++] = ' ';
			counter += c_num;
			while ((s[counter] == '-' || s[counter] == '+' || s[counter] == 32) && s[counter])
			{
				if (s[counter] == '-')
					num[c_num++] = '-';
				else if (s[counter] == '+')
					num[c_num++] = '+';
				else
					num[c_num++] = ' ';
				counter++;
			}
			while((ft_isdigit(s[counter]) || s[counter] == '.' || s[counter] == '*') && s[counter])
			{
				if (s[counter] == '*')
				{
					fill_num_star(num, &c_num, va_arg(lst, int));
					counter++;
				}
				else
					num[c_num++] = s[counter++];
			}
			num[c_num] = 0;
			print_va_arg(s[counter], lst, num);
			s[counter] ? counter++ : counter;
			free(num);
		}
	}
	va_end(lst);
	return (counter);
}
