/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:39:15 by abrun             #+#    #+#             */
/*   Updated: 2020/11/19 15:15:02 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == c)
			return ((char *)s + len);
		len--;
	}
	if (s[len] == c)
		return ((char *)s + len);
	return (NULL);
}
