/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:58:07 by abrun             #+#    #+#             */
/*   Updated: 2020/11/30 17:10:24 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"
#include <stdio.h>
#define MAX(x, y) x < y ? y : x

int		ft_putpui(long long int nbr, int base_len)
{
	long long int	res;
	long int		puissance;

	puissance = 0;
	res = nbr;
	if (res < 0)
	{
		puissance++;
		res = -res;
	}
	while (res > base_len)
	{
		puissance++;
		res /= base_len;
	}
	return (puissance + 1);
}

void	print_u(unsigned int n, char *num)
{
	int	nbr;

	nbr = ft_atoi(num);
	while (nbr-- > ft_putpui(n, 10))
		ft_putchar_fd(' ', 1);
	ft_putunsigned_fd(n, 1);
}

int		check_0(char *num)
{
	int		counter;

	counter = 0;
	while (num[counter] == 32)
		counter++;
	if (counter == 0 && num[counter] == '+')
		counter++;
	if (num[counter] == '0' && ft_isdigit(num[counter + 1]))
		return (1);
	return (0);
}

void	print_0_d(int n, char *num, int find_space)
{
	int		nbr;
	int		sign_plus;
	int		find_0;

	sign_plus = 0;
	if (num[find_space] == ' ')
		ft_putchar_fd(32, 1);
	while (num[sign_plus] != '+' && num[sign_plus])
		sign_plus++;
	if (num[sign_plus] == '+')
		ft_putchar_fd('+', 1);
	find_0 = 0;
	while (num[find_0] != '0')
		find_0++;
	nbr = ft_atoi(num + find_0);
	if (nbr == 0)
		ft_putnbr_fd(n, 1);
	num[sign_plus] == '+' || num[find_space] == 32 ? nbr-- : nbr;
	if (nbr == 0 && (num[sign_plus] == '+' || num[find_space] == 32))
		ft_putnbr_fd(n, 1);
	while (nbr--)
		ft_putnbr_fd(n, 1);
}

int		check_point(char *num)
{
	int counter;

	counter = 0;
	while (num[counter])
		if (num[counter++] == '.')
			return (1);
	return (0);
}

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
	while (num[start] != '.' && num[start])
		start++;
	point = ft_atoi(num + start + 1);
	return (point);
}

int		is_flag_zero(char *num)
{
	int		counter;

	counter = 0;
	if (num[0] == '-')
		return (0);
	if (num[counter] == '0')
		return (1);
	counter++;
	while (num[counter])
	{
		if (num[counter] == '0' && !ft_isdigit(num[counter - 1]))
			return (1);
		counter++;
	}
	return (0);
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

int		get_filler(char *num, int n_point)
{
	if (is_flag_zero(num) && !is_flag_point(num))
		return ('0');
	return (32);
}

int		print_point(char *num, int n, int n_point)
{
	if (is_flag_point(num) &&  !n && !n_point)
		return (0);
	return (1);
}

int		get_filler_negative(char *num, int n_point)
{
	if (is_flag_point(num) && n_point)
		return ('0');
	return (32);
}

void	print_d(int  n, char *num)
{
	int			n_chr;
	int			puissance;
	int			space_plus;
	int			filler;
	int			n_point;
	long int	nbr;

	nbr = n;
	n_chr = get_flag_n(num);
	n_point = get_flag_point(num);
	puissance = ft_putpui(n, 10);
	space_plus = get_space_or_plus(num);
	space_plus && n_chr ? n_chr-- : n_chr;
	filler = get_filler(num, n_point);
	if (space_plus == 32 && !(num[0] == '-' && n < 0))
		ft_putchar_fd(32, 1);
	if (num[0] != '-')
	{
		if (filler == '0' && space_plus == '+' && n >= 0) 
			ft_putchar_fd(space_plus, 1);
		if (space_plus == '+' && n < 0)
			n_chr++;
		if (filler == '0' && n < 0)
		{
			ft_putchar_fd('-', 1);
			nbr *= -1;
		}
		while (n_chr > puissance && n_chr > n_point)
		{
			ft_putchar_fd(filler, 1);
			n_chr--;
		}
		if (space_plus == '+' && filler != '0' && print_point(num, n, n_point) && n >= 0)
			ft_putchar_fd(space_plus, 1);
		while (n_point > puissance++) 
			ft_putchar_fd('0', 1);
		if (print_point(num, n, n_point))
			ft_putnbr_fd(nbr, 1);
		if (!print_point(num, n, n_point) && n_chr > 0)
			ft_putchar_fd(filler, 1);
		if (space_plus == '+' && !print_point(num, n, n_point) && n >= 0)
			ft_putchar_fd('+', 1);
	}
	else
	{
		if (space_plus == '+' && n >= 0)
			ft_putchar_fd(space_plus, 1);
		if (space_plus && n < 0)
			n_chr++;
		if (print_point(num, n, n_point))
			ft_putnbr_fd(n, 1);
		if (!print_point(num, n, n_point) && n_chr > 0)
			ft_putchar_fd(filler, 1);
		while (puissance < n_point)
		{
			ft_putchar_fd('0', 1);
			puissance++;
		}
		while (puissance++ < n_chr)
			ft_putchar_fd(32, 1);
	}
}
		
void	print_point_d(int n, char *num, int find_space)
{
	int		nbr_1;
	int		find_pt;
	int		puissance;
	int		find_plus;
	int		nbr_2;

	find_pt = 0;
	find_plus = 0;
	nbr_1 = ft_atoi(num);
	while (num[find_plus] != '+' && num[find_plus])
		find_plus++;
	while (num[find_pt] != '.')
		find_pt++;
	nbr_2 = ft_atoi(num + find_pt + 1);
	if (num[find_space] == ' ' && (!nbr_1 || nbr_2))
	{
		ft_putchar_fd(32, 1);
		nbr_1 > 0 ? nbr_1-- : nbr_1;
		nbr_1 < 0 ? nbr_1++ : nbr_1;
	}
	puissance = ft_putpui(n, 10);
	n == 0 ? puissance-- : puissance;
	if (nbr_1 > 0)
	{
		num[find_plus] == '+' ? nbr_1-- : nbr_1;
		while (nbr_1-- > puissance && nbr_1 >= nbr_2)
			ft_putchar_fd(32,1);
		if (num[find_plus] == '+')
			ft_putchar_fd('+', 1);
		if (n != 0 && nbr_2 <= 0)
			ft_putnbr_fd(n, 1);
		while (nbr_2--)
			ft_putnbr_fd(n, 1);
	}
	else
	{
		nbr_1 *= -1;
		num[find_plus] == '+' ? nbr_1-- : nbr_1;
		if (num[find_plus] == '+')
			ft_putchar_fd('+', 1);
		if (n != 0 && nbr_2 <= 0)
			ft_putnbr_fd(n, 1);
		while (nbr_2--)
		{
			ft_putnbr_fd(n, 1);
			nbr_1--;
		}
		while (nbr_1-- > puissance && nbr_1 >= nbr_2)
			ft_putchar_fd(32,1);
	}
}

void	print_dbis(int n, char *num)
{
	int	nbr;
	int	puissance;
	int	sign_plus;
	int	find_space;
	int	find_digit;

	find_space = 0;
	while (num[find_space] && num[find_space] != ' ')
		find_space++;
	if (check_point(num))
	{
		print_point_d(n, num, find_space);
		return ;
	}
	if (check_0(num))
	{
		print_0_d(n, num, find_space);
		return ;
	}
	sign_plus = 0;
	while (num[sign_plus] != '+' && num[sign_plus])
		sign_plus++;
	find_digit = 0;
	while (num[find_digit] && !ft_isdigit(num[find_digit]))
		find_digit++;
	nbr = ft_atoi(num + find_digit);
	num[0] == '-' ? nbr *= -1 : nbr;
	if (nbr <= 1 && num[find_space] == ' ' && num[sign_plus] != '+')
		ft_putchar_fd(32,1);
	puissance = ft_putpui(n, 10);
	num[sign_plus] == '+' ? puissance++ : puissance;
	if (nbr >= 0)
	{
		while (nbr-- > puissance)
			ft_putchar_fd(' ', 1);
		if (num[sign_plus] == '+')
			ft_putchar_fd('+', 1);
		ft_putnbr_fd(n, 1);
	}
	else
	{
		if (num[sign_plus] == '+')
			ft_putchar_fd('+', 1);
		ft_putnbr_fd(n, 1);
		num[sign_plus] == '+' || num[find_space] == 32 ? nbr++ : nbr;
		while (nbr++ < -1)
			ft_putchar_fd(' ', 1);
	}
}

void	print_s(char *s, char *num)
{
	size_t		nbr;

	nbr = ft_atoi(num);
	while (nbr-- > ft_strlen(s))
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(s, 1);
}

void	print_c(int va_arg, char *num)
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

void	print_x(long long int n, char *num)
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

void	print_va_arg(char c, va_list lst, char *num)
{
	if (c == 's')
		print_s(va_arg(lst, char *), num);
	else if (c == 'd')
		print_d(va_arg(lst, int), num);
	else if (c == 'c')
		print_c(va_arg(lst, int), num);
	else if (c == 'u')
		print_u(va_arg(lst, int), num);
	else if (c == 'x')
		print_x(va_arg(lst, long long int), num);
	else if (c == 'X')
		print_X(va_arg(lst, long long int), num);
	else if (c == 'p')
		print_p(va_arg(lst, long long int), num);
	else if (c == '%')
		ft_putchar_fd('%', 1);
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
			while((ft_isdigit(s[counter]) || s[counter] == '.') && s[counter])
				num[c_num++] = s[counter++];
			num[c_num] = 0;
			print_va_arg(s[counter], lst, num);
			s[counter] ? counter++ : counter;
			free(num);
		}
	}
	va_end(lst);
	return (counter);
}