/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:41:09 by abrun             #+#    #+#             */
/*   Updated: 2020/11/20 14:39:53 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mal;
	int				lenght;
	int				counter;

	lenght = size * count;
	counter = lenght;
	if (!(mal = malloc(lenght)))
		return (0);
	while (lenght-- > 0)
		*mal++ = 0;
	return (mal - counter);
}
