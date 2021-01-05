/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:19:40 by abrun             #+#    #+#             */
/*   Updated: 2021/01/04 16:40:24 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.c"
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

typedef struct		s_map
{
	int		height;
	int		max_width;
	int		len_pix;
	char	**map;
}					t_map;

//--------------------HERO-----------------------\\

typedef struct	s_player
{
	int			x;
	int			y;
	int			len;
	int			angle;
}				player;

typedef struct		s_param
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	player		hero;
	t_img		img;
}					t_param;

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
		y -= round(5 * cos(convert(param.hero.angle)));
		x -= round(5 * sin(convert(param.hero.angle)));
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
				pos = ((param.hero.x + x) * 4) + (param.img.size_line * (param.hero.y + y)) + counter;
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
	change_hero_pos(*param, 0);
	if (key == 12)
	{
		param->hero.y -= round(5 * cos(convert(param->hero.angle)));
		param->hero.x -= round(5 * sin(convert(param->hero.angle)));
	}
	if (key == 6)
	{
		param->hero.y += round(5 * cos(convert(param->hero.angle)));
		param->hero.x += round(5 * sin(convert(param->hero.angle)));
	}
	if (key == 2)
		param->hero.angle -= 5;
	if (key == 1)
		param->hero.angle += 5;
	if (param->hero.angle < 0)
		param->hero.angle += 360;
	if (param->hero.angle > 360)
		param->hero.angle %= 360;
	change_hero_pos(*param, 10);
	mlx_put_image_to_window(param->mlx, param->win, param->img.image, 0, 0);
	return (1);
}

//--------------------------------HERO---------------------------------\\

typedef	struct		s_point
{
	int		x;
	int		y;
}					t_point;

void		display_map_case(t_map map, t_point	img_pt, t_point map_pt, t_param param)
{
	int		pos;
	int		x_bis;
	int		y_bis;

	y_bis = map.len_pix;
	while (y_bis--)
	{
		x_bis = map.len_pix;
		while (x_bis--)
		{
			pos = (img_pt.x * 4) + (param.img.size_line * img_pt.y);
			if (map.map[map_pt.x][map_pt.y] == '1')
			{
				param.img.data[pos] = 100;
				param.img.data[pos + 1] = 20;
				param.img.data[pos + 2] = -100;
				param.img.data[pos + 3] = 10;
			}
			img_pt.x += 1;
		}
		img_pt.x -= map.len_pix;
		img_pt.y += 1;
	}
}


void		display_map(t_map map, t_param param)
{
	t_point		img_pt;
	t_point		map_pt;
	int			counter;
	
	img_pt.y = (param.height - (map.height * map.len_pix)) / 2;
	img_pt.x = (param.width - (map.max_width * map.len_pix)) / 2;
	map_pt.x = 0;
	while (map_pt.x < map.height)
	{
		map_pt.y = 0;
		while (map.map[map_pt.x][map_pt.y])
		{
			display_map_case(map, img_pt, map_pt, param);
			map_pt.y += 1;
			img_pt.x += map.len_pix;
		}
		map_pt.x += 1;
		img_pt.x -= (map_pt.y * map.len_pix);
		img_pt.y += map.len_pix;
	}
}

void		print_map(char **map)
{
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
}

int		main()
{
	void		*mlx;
	void		*win;
	t_param		param;

	mlx = mlx_init();

	param.height = 750;
	param.width = 1000;
	win = mlx_new_window(mlx, param.width, param.height, "test");

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

	param.img = img;

	char		*tab;
	t_map		map;
	tab = get_tab();
	map.map = get_map(tab);
	map.height = (int)get_height(tab);
	map.max_width = get_max_width(map.map, tab);
	map.len_pix = 40;
	free(tab);
	display_map(map, param);

	player	hero;
	hero.angle = 0;
	hero.x = 500;
	hero.y = 400;
	hero.len = 7;

	param.hero = hero;

	mlx_hook(win, 2, 1L<<0, move_hero, &param);
	
	change_hero_pos(param, 100);

	mlx_put_image_to_window(mlx, win, img.image, 0, 0);

	mlx_loop(mlx);
}
