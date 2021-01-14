/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:19:58 by abrun             #+#    #+#             */
/*   Updated: 2020/11/24 16:35:00 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "printf.h"

static void		ft_putint_fd(int n, int fd)
{
	char	c;

	c = n + '0';
	write(fd, &c, 1);
}

void			ft_putunsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putunsigned_fd(n / 10, fd);
	ft_putint_fd(n % 10, fd);
}
