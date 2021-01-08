/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:41:04 by abrun             #+#    #+#             */
/*   Updated: 2020/11/20 14:38:54 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_findchr(char chr, char const *set)
{
	unsigned int	counter;

	counter = 0;
	while (set[counter])
	{
		if (chr == set[counter])
			return (1);
		counter++;
	}
	return (0);
}

unsigned int	ft_get_start(char const *s1, char const *set)
{
	unsigned int	start;

	start = 0;
	while (ft_findchr(s1[start], set) && s1[start])
		start++;
	return (start);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char			*strtrim;
	size_t			s1_len;
	unsigned int	start;
	unsigned int	end;
	unsigned int	counter;

	counter = 0;
	s1_len = ft_strlen(s1);
	end = s1_len - 1;
	if (!(strtrim = malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	if (s1_len > 0)
	{
		start = ft_get_start(s1, set);
		while (ft_findchr(s1[end], set) && end > 0)
			end--;
		while (start + counter <= end)
		{
			strtrim[counter] = s1[start + counter];
			counter++;
		}
	}
	strtrim[counter] = '\0';
	return (strtrim);
}
