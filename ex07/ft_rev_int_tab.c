/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:43:19 by abrun             #+#    #+#             */
/*   Updated: 2020/10/15 16:53:28 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int *temp;

	*temp = *a;
	*a = *b;
	*b = *temp;
}

void	ft_rev_int_tab(int *tab, int *size)
{
	int *tablen;

	tablen = *size;
	while (*tablen < *size / 2)
	{
		ft_swap(tab[*size], tab[*size - *tablen]);
		*tablen--;
	}
}
