/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:21:18 by abrun             #+#    #+#             */
/*   Updated: 2020/11/19 17:14:41 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dstlen;
	unsigned int	counter;
	size_t			srclen;

	counter = 0;
	dstlen = 0;
	srclen = ft_strlen(src);
	while (dst[dstlen])
		dstlen++;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	if (dstsize > dstlen)
	{
		while (src[counter] && counter < dstsize - dstlen - 1)
		{
			dst[dstlen + counter] = src[counter];
			counter++;
		}
	}
	dst[dstlen + counter] = '\0';
	return (dstlen + srclen);
}
