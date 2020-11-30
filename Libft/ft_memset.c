/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:55:11 by abrun             #+#    #+#             */
/*   Updated: 2020/11/20 14:41:14 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)pointer;
	i = -1;
	while (++i < count)
		ptr[i] = value;
	return (pointer);
}
