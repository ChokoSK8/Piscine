/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:16:44 by abrun             #+#    #+#             */
/*   Updated: 2021/01/04 15:16:26 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t		get_height(char *tab)
{
	size_t height;
	size_t counter;

	height = 0;
	counter = 0;
	while (tab[counter])
	{
		if (tab[counter] == '\n')
			height++;
		counter++;
	}
	return (height);
}

int			get_max_width(char **map, char *tab)
{
	int		max;
	int		row;
	size_t	height;
	int		width;

	height = get_height(tab);
	row = 0;
	max = 0;
	while (row < height)
	{
		width = 0;
		while (map[row][width])
			width++;
		if (max < width)
			max = width;
		row++;
	}
	return (max);
}

size_t		get_length(char *tab)
{
	size_t len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

int			fill_tabulation(char **map, int i, int *j)
{
	int		counter;

	counter = 4;
	while (counter--)
	{
		map[i][*j] = 32;
		*j += 1;
	}
	return (1);
}

char		*get_tab()
{
	int		fd;
	char	*tab;
	int		ret;

	fd = open("map", O_RDONLY);
	tab = malloc(sizeof(int) * 100000);
	ret = read(fd, tab, 100000);
	tab[ret] = 0;
	close(fd);
	return (tab);
}

size_t		get_width(char *tab)
{
	size_t		counter;
	size_t		width;	

	counter = 0;
	width = 0;
	while (tab[counter] && tab[counter] != '\n')
	{
		if (tab[counter] == '\t')
			width += 3;
		counter++;
		width++;
	}
	return (counter);
}

char		**get_map(char *tab)
{
	char		**map;
	int			i;
	int			j;
	int			tab_length;

	tab_length = get_length(tab);
	i = 0;
	j = 0;
	map = malloc(sizeof(int *) * (get_height(tab) + 1));
	while (*tab)
	{
		map[i] = malloc(sizeof(int) * (get_width(tab) + 1));
		while (*tab && *tab != '\n')
		{
			if (*tab == '\t')
				tab += fill_tabulation(map, i, &j);
			else
				map[i][j++] = *tab++;
		}
		map[i][j] = 0;
		i++;
		j = 0;
		*tab ? tab++ : tab;
	}
	map[i] = 0;
	return (map);
}
