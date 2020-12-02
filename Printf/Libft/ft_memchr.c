/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:57:38 by abrun             #+#    #+#             */
/*   Updated: 2020/11/19 14:49:52 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned int	counter;

	src = (unsigned char *)s;
	counter = -1;
	while (++counter < n && *src)
		if (*src++ == (unsigned char)c)
			return (--src);
	if (c == '\0' && *src == '\0')
		return (src);
	return (NULL);
}
