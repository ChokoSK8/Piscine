/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:10:27 by abrun             #+#    #+#             */
/*   Updated: 2020/11/21 16:11:45 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_cases(char const *s, char c)
{
	unsigned int	cases;
	unsigned int	counter;

	counter = 0;
	cases = 0;
	while (s[counter])
	{
		while (s[counter] == c && s[counter])
			counter++;
		s[counter] ? cases += 1 : cases;
		while (s[counter] != c && s[counter])
			counter++;
	}
	!cases ? cases++ : cases;
	return (cases);
}

unsigned int	ft_size_malloc(char const *s, char c)
{
	unsigned int	size_malloc;

	size_malloc = 0;
	while (s[size_malloc] && s[size_malloc] != c)
		size_malloc++;
	return (size_malloc);
}

void			ft_fill_split(unsigned int counter, char **split,
			unsigned int size, char const *s)
{
	int i;

	i = 0;
	while (size-- > 0)
	{
		split[counter][i] = *s++;
		i++;
	}
	split[counter][i] = '\0';
}

char			**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	cases;
	unsigned int	counter;
	unsigned int	size;

	counter = 0;
	cases = ft_cases(s, c) + 1;
	if (!(split = (char **)malloc(sizeof(char *) * cases)))
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		size = ft_size_malloc(s, c);
		if (!(split[counter] = malloc(size + 1)))
			return (0);
		ft_fill_split(counter, split, size, s);
		size ? counter++ : counter;
		s += size;
	}
	if (!(split[counter] = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	split[counter] = 0;
	return (split);
}
