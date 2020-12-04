/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:04:29 by abrun             #+#    #+#             */
/*   Updated: 2020/12/04 13:46:35 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "printf.h"

long long int		ft_pow(long long int nb, int power)
{
	long int res;

	res = 1;
	while (power-- > 0)
		res *= nb;
	return (res);
}

long int			ft_put_puissance(long long int nbr, size_t base_len)
{
	long long int	res;
	long int		puissance;

	puissance = 0;
	res = nbr;
	while (res > (long long int)base_len)
	{
		puissance++;
		res /= base_len;
	}
	return (puissance);
}

void				ft_putnbr_base_fd(long long int nbr, char *base, int fd)
{
	size_t						base_len;
	long int					puissance;
	long int					counter;
	long long int				n;

	base_len = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	puissance = ft_put_puissance(n, base_len);
	while (n > 0)
	{
		counter = n / ft_pow(base_len, puissance);
		n %= ft_pow(base_len, puissance);
		write(fd, base + counter, 1);
		puissance--;
	}
	while (puissance-- >= 0)
		write(fd, &base[0], 1);
}
