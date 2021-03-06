/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:07:11 by abrun             #+#    #+#             */
/*   Updated: 2021/01/04 11:19:23 by abrun            ###   ########.fr       */
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

typedef struct		s_img
{
	int			bpp;
	int			size_line;
	int			endian;
	int			img_len;
	char		*data;
	void		*image;
}					t_img;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_player
{
	int			x;
	int			y;
	t_img		img;
	int			angle;
}				player;

typedef struct		s_param
{
	void		*mlx;
	void		*win;
	player		*hero;
}					t_param;

double		convert(double degre)
{
	double rad;

	rad = degre / 57.2958;
	return (rad);
}

void				display_raycaster(player *hero, int color)
{
	int		x;
	int		y;
	int		pos;
	int		counter;

	x = hero->x + (hero->img.img_len / 2);
	y = hero->y + (hero->img.img_len / 2);
	while (y < 800 && x < 1000 && y > 0 && x > 0)
	{
		counter = 4;
		while (counter--)
		{
			pos = (x * 4) + (hero->img.size_line * y) + counter;
			color && !counter ? color = -50 : color;
			color && !(counter % 1) ? color = -100 : color;
			color && !(counter % 2) ? color = 20 : color;
			color && !(counter % 3) ? color = 1 : color;
			hero->img.data[pos] = color;
		}
		y -= round(5 * cos(convert(hero->angle)));
		x -= round(5 * sin(convert(hero->angle)));
	}
}

void				change_color(player *hero, int color)
{
	int		x;
	int		y;
	int		counter;
	int		pos;
	int		value;

	y = 0;
	while (y < hero->img.img_len)
	{
		x = 0;
		value = hero->img.img_len;
		while (x < value)
		{
			counter = 0;
			while (counter < 4)
			{
				pos = ((hero->x + x) * 4) + (hero->img.size_line * (hero->y + y)) + counter;
				color && !counter ? color = -50 : color;
				color && !(counter % 1) ? color = -100 : color;
				color && !(counter % 2) ? color = 20 : color;
				color && !(counter % 3) ? color = 1 : color;
				hero->img.data[pos] = color;
				counter++;
			}
			x++;
		}
		y++;
	}
	display_raycaster(hero, color);
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

int		main()
{
	void		*mlx;
	void		*win;
	t_param		param;

	mlx = mlx_init();

	win = mlx_new_window(mlx, 1000, 800, "move_hero_42");

	param.mlx = mlx;
	param.win = win;


	int		bpp;
	int		size_line;
	int		endian;
	int		img_len = 8;
	void	*image;
	image = mlx_new_image(mlx, 1000, 800);
	char *img_data = mlx_get_data_addr(image, &bpp, &size_line, &endian);

	t_img	img;
	img.bpp = bpp;
	img.size_line = size_line;
	img.endian = endian;
	img.img_len = img_len;
	img.data = img_data;
	img.image = image;
	player	hero;
	hero.angle = 0;
	hero.x = 500;
	hero.y = 400;
	hero.img = img;

	param.hero = &hero;

	change_color(&hero, 100);

	mlx_put_image_to_window(mlx, win, img.image, 0, 0);

	mlx_hook(win, 2, 1L<<0, move_hero, &param);

	mlx_loop(mlx);
}
