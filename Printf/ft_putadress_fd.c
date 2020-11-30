/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:15:20 by abrun             #+#    #+#             */
/*   Updated: 2020/11/24 17:25:47 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "printf.h"

long int		ft_po(long int nb, int power)
{
	long int res;

	res = 1;
	while (power-- > 0)
		res *= nb;
	return (res);
}

long int		ft_put_pui(long long nbr, size_t base_len)
{
	long int	res;
	long int	puissance;

	puissance = 0;
	res = base_len;
	while (nbr >= res)
	{
		puissance++;
		res *= base_len;
	}
	return (puissance);
}

void			ft_putadress_fd(long long nbr, char *base, int fd)
{
	size_t					base_len;
	long int				puissance;
	long int				counter;
	long long				n;

	base_len = ft_strlen(base);
	n = nbr;
	puissance = ft_put_pui(n, base_len);
	ft_putstr_fd("0x", fd);
	while (n > 0)
	{
		counter = n / ft_po(base_len, puissance);
		n %= ft_po(base_len, puissance);
		write(fd, base + counter, 1);
		puissance--;
	}
	while (puissance-- >= 0)
		write(fd, &base[0], 1);
}
