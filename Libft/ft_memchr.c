/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:57:38 by abrun             #+#    #+#             */
/*   Updated: 2020/11/25 08:50:14 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned int	counter;

	src = (unsigned char *)s;
	counter = 0;
	while (counter < n && src[counter])
	{
		if (src[counter] == (unsigned char)c)
			return (src + counter);
		counter++;
	}
	if (counter == n && n > 0)
		counter--;
	if (c == '\0' && src[counter] == '\0' && n > 0)
		return (src + counter);
	return (NULL);
}
