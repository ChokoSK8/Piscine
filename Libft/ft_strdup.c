/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:17:09 by abrun             #+#    #+#             */
/*   Updated: 2020/11/19 11:31:43 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t			s1_len;
	unsigned char	*dst;
	unsigned int	len;

	s1_len = ft_strlen(s1) + 1;
	len = s1_len;
	if (!(dst = malloc(sizeof(char) * s1_len)))
		return (NULL);
	while (s1_len--)
		*dst++ = *s1++;
	return ((char *)dst - len);
}
