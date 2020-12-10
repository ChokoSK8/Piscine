/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:43:20 by abrun             #+#    #+#             */
/*   Updated: 2020/12/10 11:27:41 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	counter;

	if (!(substr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	counter = 0;
	if (start < ft_strlen(s))
	{
		while (counter < len && s[start + counter])
		{
			substr[counter] = s[start + counter];
			counter++;
		}
		substr[counter] = '\0';
	}
	while (counter < (len) + 1)
		substr[counter++] = 0;
	return (substr);
}
