/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:55:15 by abrun             #+#    #+#             */
/*   Updated: 2020/11/20 10:05:38 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	unsigned int		counter;
	unsigned char		chr;

	chr = c;
	counter = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (counter < n)
	{
		d[counter] = s[counter];
		if (s[counter] == chr)
			return (d + counter + 1);
		counter++;
	}
	return (0);
}
