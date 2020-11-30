/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:34:59 by abrun             #+#    #+#             */
/*   Updated: 2020/11/20 10:44:49 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	counter;

	if (!(dst = malloc(ft_strlen(s) + 1)))
		return (NULL);
	counter = 0;
	while (s[counter])
	{
		dst[counter] = (*f)(counter, s[counter]);
		counter++;
	}
	dst[counter] = '\0';
	return (dst);
}
