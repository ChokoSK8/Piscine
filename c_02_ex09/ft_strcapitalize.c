/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 21:40:39 by abrun             #+#    #+#             */
/*   Updated: 2020/10/15 22:39:09 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

int		ft_strlen(char *str)
{
	int strlen;

	while (!str[strlen])
		strlen++;
	return (strlen);
}

bool	ft_is_letter(char c)
{
	if ((c < 123 && c > 96) || (c > 64 && c < 91))
		return (true);
	return (false);
}

bool	ft_is_lowercase(char c)
{
	if (c < 123 && c > 96)
		return (true);
	return (false);
}

char	*ft_strcapitalize(char *str)
{
	int counter;

	counter = 1;
	if (*str > 'a' && *str < 'z')
		*str -= 32;
	while (!str[counter])
	{
		if (!ft_is_letter(str[counter - 1]) && ft_is_lowercase(str[counter]))
		{
			str[counter] -= 32;
			counter++;
		}
		counter++;
	}
	return (str);
}

void	ft_putstr(char *str)
{
	int strlen;

	strlen = ft_strlen(str);
	write(1, str, strlen);
}


int main()
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char *p_str = &str[0];
	ft_putstr(str);
	p_str = ft_strcapitalize(p_str);
	ft_putstr(str);
}
