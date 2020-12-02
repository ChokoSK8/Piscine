/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:16:02 by abrun             #+#    #+#             */
/*   Updated: 2020/11/18 12:16:16 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	counter;

	counter = 0;
	while (s[counter])
	{
		if (s[counter] == c)
			return ((char *)s + counter);
		counter++;
	}
	if (c == '\0' && s[counter] == '\0')
		return ((char *)s + counter);
	return (NULL);
}
