/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 21:31:04 by abrun             #+#    #+#             */
/*   Updated: 2020/10/15 21:37:58 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    *ft_strupcase(char *str)
{
    while (*str)
        //pas !*str
    {
        if (*str > 'a' && *str < 'z')
            *str -= 32;
        str++;
        //faire str++ par *str++
    }
    return (str);
    //attention à retourner str sans *
}
