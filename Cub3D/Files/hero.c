/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:16:49 by abrun             #+#    #+#             */
/*   Updated: 2021/01/04 16:26:33 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

typedef struct	s_player
{
	int			x;
	int			y;
	int			len;
	int			angle;
}				player;

double		convert(double degre)
{
	double rad;

	rad = degre / 57.2958;
	return (rad);
}

void				display_raycaster(t_param param, int color)
{
	int		x;
	int		y;
	int		pos;
	int		counter;

	x = param.hero.x + (param.hero.len / 2);
	y = param.hero.y + (param.hero.len / 2);
	while (y < 800 && x < 1000 && y > 0 && x > 0)
	{
		counter = 4;
		while (counter--)
		{
			pos = (x * 4) + (param.img.size_line * y) + counter;
			color && !counter ? color = -50 : color;
			color && !(counter % 1) ? color = -100 : color;
			color && !(counter % 2) ? color = 20 : color;
			color && !(counter % 3) ? color = 1 : color;
			param.img.data[pos] = color;
		}
		y -= round(5 * cos(convert(hero->angle)));
		x -= round(5 * sin(convert(hero->angle)));
	}
}

void				change_hero_pos(t_param param, int color)
{
	int		x;
	int		y;
	int		counter;
	int		pos;

	y = 0;
	while (y < param.hero.len)
	{
		x = 0;
		while (x < param.hero.len)
		{
			counter = 0;
			while (counter < 4)
			{
				pos = ((hero.x + x) * 4) + (param.img.size_line * (hero.y + y)) + counter;
				color && !counter ? color = -50 : color;
				color && !(counter % 1) ? color = -100 : color;
				color && !(counter % 2) ? color = 20 : color;
				color && !(counter % 3) ? color = 1 : color;
				param.img.data[pos] = color;
				counter++;
			}
			x++;
		}
		y++;
	}
	display_raycaster(param, color);
}

int			move_hero(int key, t_param *param)
{
	change_color(param->hero, 0);
	if (key == 12)
	{
		param->hero->y -= round(5 * cos(convert(param->hero->angle)));
		param->hero->x -= round(5 * sin(convert(param->hero->angle)));
	}
	if (key == 6)
	{
		param->hero->y += round(5 * cos(convert(param->hero->angle)));
		param->hero->x += round(5 * sin(convert(param->hero->angle)));
	}
	if (key == 2)
		param->hero->angle -= 5;
	if (key == 1)
		param->hero->angle += 5;
	if (param->hero->angle < 0)
		param->hero->angle += 360;
	if (param->hero->angle > 360)
		param->hero->angle %= 360;
	change_color(param->hero, 10);
	mlx_put_image_to_window(param->mlx, param->win, param->hero->img.image, 0, 0);
	return (1);
}
