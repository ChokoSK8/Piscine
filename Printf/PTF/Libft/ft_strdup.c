/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:17:09 by abrun             #+#    #+#             */
/*   Updated: 2021/01/12 17:05:02 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strdup(const char *s1, int len)
{
	size_t			s1_len;
	unsigned char	*dst;

	s1_len = ft_strlen(s1);
	if (len == -1)
		len = s1_len;
	else
		s1_len = len;
	if (!(dst = malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	while (s1_len--)
		*dst++ = *s1++;
	*dst = 0;
	return ((char *)dst - len);
}
