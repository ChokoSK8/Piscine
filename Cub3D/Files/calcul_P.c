/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_P.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:57:59 by abrun             #+#    #+#             */
/*   Updated: 2020/12/23 12:18:50 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
# define	PI 3.1415926535897
# define	PI2 PI/2
# define	PI3 3 * PI2
# define	PI4 2 * PI

typedef struct		s_point
{
	double x;
	double y;
}					t_point;

typedef struct		s_vect
{
	double x;
	double y;
}					t_vect;

typedef struct		s_map
{
	char	**mat;
	int		x_max;
	int		y_max;
	size_t	len;
}					t_map;

double		convert_deg_in_rad(double degre)
{
	double rad;

	rad = degre / 57.2958;
	return (rad);
}

void		get_pt_a(t_point hero, double angle, t_point abs, t_point *pt_a)
{
	if (angle < 180)
	{
		pt_a->y = hero.y - ((int)hero.y % (int)abs.y);
		pt_a->y == hero.y ? pt_a->y -= abs.y : pt_a->y;
		if (angle < 90)
			pt_a->x = hero.x - ((hero.y - pt_a->y) / tan((convert_deg_in_rad(angle))));
		else
			pt_a->x = hero.x + ((hero.y - pt_a->y) / tan((convert_deg_in_rad(180 - angle))));
	}
	else
	{
		pt_a->y = hero.y + ((int)hero.y % (int)abs.y);
		pt_a->y == hero.y ? pt_a->y += abs.y : pt_a->y;
		if (angle < 270)
			pt_a->x = hero.x - (hero.y - pt_a->y) / tan((convert_deg_in_rad(angle - 180)));
		else
			pt_a->x = hero.x + ((hero.y - pt_a->y) / tan((convert_deg_in_rad(360 - angle))));
	}
}

void		get_vector(double angle, t_point abs, t_vect *vector)
{
	if (angle < 180)
	{
		vector->y = -abs.y;
		if (angle < 90)
			vector->x = vector->y / tan(convert_deg_in_rad(angle));
		else
			vector->x = -vector->y / tan(convert_deg_in_rad(angle));
	}
	else
	{
		vector->y = abs.y;
		if (angle < 270)
			vector->x = vector->y / tan(convert_deg_in_rad(angle));
		else
			vector->x = -vector->y / tan(convert_deg_in_rad(angle));
	}
}

int			is_wall_horizontal(t_point pt, double angle, t_map map)
{
	int		x;
	int		y;

	if (angle < 180)
		y = (pt.y / map.len) - 1;
	else
		y = pt.y / map.len;
	if ((int)pt.x % map.len || (angle < 270 && angle > 90))
		x = pt.x / map.len;
	else
		x = (pt.x / map.len) - 1;
	if (x <= map.x_max && map.mat[x][y] == '1')
		return (1);
	if (x > map.x_max)
		return (2);
	return (0);
}

double		get_hp_horizontal(t_point hero, double angle, t_point abs, t_map map)
{
	t_point		pt_a;
	t_vect		vector;
	double		hp;
	int			ret;

	get_pt_a(hero, angle, abs, &pt_a);
	printf("pt(%f,%f)\n", pt_a.x, pt_a.y);
	get_vector(angle, abs, &vector);
	printf("vector(%f,%f)\n", vector.x, vector.y);
	while (!(ret = is_wall_horizontal(pt_a, angle, map)))
	{
		pt_a.x += vector.x;
		pt_a.y += map.len;
	}
	/*if (ret == 2)
	  return (-1);*/
	hp = sqrt(pow(hero.y - pt_a.y, 2) + pow(hero.x - pt_a.x, 2));
	return (hp);
}

int			main()
{
	t_point		hero;
	t_point		abs;
	double		angle;
	t_map		map;


	abs.x = 100;
	abs.y = 100;

	hero.x = 150;
	hero.y = 200;

	angle = 187;
	get_hp_horizontal(hero, angle, abs, map);
}
