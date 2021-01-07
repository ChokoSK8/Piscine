/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:19:40 by abrun             #+#    #+#             */
/*   Updated: 2021/01/05 15:59:05 by abrun            ###   ########.fr       */
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

typedef struct	s_player
{
	int			x;
	int			y;
	int			len;
	int			angle;
}				player;

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

typedef struct		s_param
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	player		hero;
	t_img		img;
	t_map		map;
}					t_param;

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

//-------------------Get_Dist------------------\\

typedef struct		s_vect
{
	double x;
	double y;
}					t_vect;

double		convert_deg_in_rad(double degre)
{
	double rad;

	rad = degre / 57.2958;
	return (rad);
}

void		get_pt_a(player hero, t_point *pt_a, t_map map)
{
	if (hero.angle > 270 || hero.angle < 90)
	{
		pt_a->y = hero.y - (hero.y % map.len_pix);
		if (pt_a->y == hero.y)
			pt_a->y -= map.len_pix;
		if (hero.angle < 90)
		{
			if (hero.angle % 360 == 0)
			{
				pt_a->x = 0;
				return;
			}
			pt_a->x = hero.x - tan(convert_deg_in_rad(hero.angle)) * (hero.y - pt_a->y);
		}
		else
		{
			pt_a->x = hero.x + tan(convert_deg_in_rad(hero.angle)) * (hero.y - pt_a->y);
		}
	}
}

/*void		get_pt_a(player hero, t_point *pt_a, t_map map)
  {
  if (hero.angle < 180)
  {
  pt_a->y = hero.y - (hero.y % map.len_pix);
  pt_a->y == hero.y ? pt_a->y -= map.len_pix : pt_a->y;
  if (hero.angle < 90)
  {
  if (hero.angle % 360 == 0)
  {
  pt_a->x = 0;
  return ;
  }
  pt_a->x = hero.x - ((hero.y - pt_a->y) / tan((convert_deg_in_rad(hero.angle))));
  }
  else
  pt_a->x = hero.x + ((hero.y - pt_a->y) / tan((convert_deg_in_rad(180 - hero.angle))));
  }
  else
  {
  pt_a->y = hero.y + (hero.y % map.len_pix);
  pt_a->y == hero.y ? pt_a->y += map.len_pix : pt_a->y;
  if (hero.angle < 270)
  pt_a->x = hero.x - (hero.y - pt_a->y) / tan((convert_deg_in_rad(hero.angle - 180)));
  else
  pt_a->x = hero.x + ((hero.y - pt_a->y) / tan((convert_deg_in_rad(360 - hero.angle))));
  }
  }*/

void		get_vector(int angle, int len_pix, t_vect *vector)
{
	if (angle < 270 && angle > 90)
	{
		vector->y = len_pix;
		if (angle < 180)
			vector->x = -vector->y / tan(convert_deg_in_rad(angle));
		else
			vector->x = vector->y / tan(convert_deg_in_rad(angle));
	}
	else
	{
		vector->y = -len_pix;
		if (angle < 90)
			vector->x = vector->y / tan(convert_deg_in_rad(angle));
		else
			vector->x = -vector->y / tan(convert_deg_in_rad(angle));
	}
}

int			is_wall_horizontal(t_point pt, int angle, t_param param)
{
	int		x;
	int		y;

	pt.y -= (param.height - (param.map.height * param.map.len_pix)) / 2;
	pt.x -= (param.width - (param.map.max_width * param.map.len_pix)) / 2;
	if (angle < 180)
		y = (pt.y / param.map.len_pix) - 1;
	else
		y = pt.y / param.map.len_pix;
	if ((int)pt.x % param.map.len_pix || (angle < 270 && angle > 90))
		x = pt.x / param.map.len_pix;
	else
		x = (pt.x / param.map.len_pix) - 1;
	if (x <= param.map.height - 1 && x >= 0 && param.map.map[x][y] == '1')
	{
		return (1);
	}
	if (x >= param.map.height || x < 0)
		return (2);
	return (0);
}

double		get_hp_horizontal(t_param param, t_map map)
{
	t_point		pt_a;
	t_vect		vector;
	double		hp;
	int			ret;

	get_pt_a(param.hero, &pt_a, map);
	printf("pt_a (%d, %d)\n", pt_a.x, pt_a.y);
	if (pt_a.x == 0)
		return (0);
	get_vector(param.hero.angle, map.len_pix, &vector);
	/*while (!(ret = is_wall_horizontal(pt_a, param.hero.angle, param)))
	  {
	  pt_a.x -= vector.x;
	  pt_a.y += map.len_pix;
	  }
	  printf("Fin ray : (%d, %d)\n", pt_a.x, pt_a.y);
	  if (ret == 2)
	  return (-1);*/
	hp = sqrt(pow(param.hero.y - pt_a.y, 2) + pow(param.hero.x - pt_a.x, 2));
	return (hp);
}

//-----------------------------Get_Dist------------------------\\

//--------------------HERO-----------------------\\

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
	int		x_1;
	int		y_1;
	double 	dist;

	dist = get_hp_horizontal(param, param.map);
	x = param.hero.x + (param.hero.len / 2);
	y = param.hero.y + (param.hero.len / 2);
	x_1 = param.hero.x + (param.hero.len / 2);
	y_1 = param.hero.y + (param.hero.len / 2);
	while (dist > sqrt(pow(x_1 - x, 2) + pow(y_1 - y, 2)))
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
	printf("angle : %d\n", param->hero.angle);
	mlx_put_image_to_window(param->mlx, param->win, param->img.image, 0, 0);
	return (1);
}

//--------------------------------HERO---------------------------------\\

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
			if (y_bis == map.len_pix - 1 || x_bis == map.len_pix - 1)
			{
				param.img.data[pos] = 10;
				param.img.data[pos + 1] = 120;
				param.img.data[pos + 2] = -10;
				param.img.data[pos + 3] = -100;
			}
			else
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

void		display_map_empty_case(t_map map, t_point img_pt, t_point map_pt, t_param param)
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
			if (y_bis == map.len_pix - 1 || x_bis == map.len_pix - 1)
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
			if (map.map[map_pt.x][map_pt.y] == '1')
				display_map_case(map, img_pt, map_pt, param);
			else
				display_map_empty_case(map, img_pt, map_pt, param);
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
	map.max_width = get_max_width(tab);
	map.len_pix = 40;
	free(tab);
	display_map(map, param);
	param.map = map;

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
