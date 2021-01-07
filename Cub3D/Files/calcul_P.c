/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_P.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:57:59 by abrun             #+#    #+#             */
/*   Updated: 2021/01/05 11:56:53 by abrun            ###   ########.fr       */
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

double		convert_deg_in_rad(double degre)
{
	double rad;

	rad = degre / 57.2958;
	return (rad);
}

void		get_pt_a(player hero, t_point *pt_a, t_map map)
{
	if (hero.angle < 180)
	{
		pt_a->y = hero.y - (hero.y % map.len_pix);
		pt_a->y == hero.y ? pt_a->y -= map.len_pix : pt_a->y;
		if (hero.angle < 90)
			pt_a->x = hero.x - ((hero.y - pt_a->y) / tan((convert_deg_in_rad(hero.angle))));
		else
			pt_a->x = hero.x + ((hero.y - pt_a->y) / tan((convert_deg_in_rad(180 - hero.angle))));
	}
	else
	{
		pt_a->y = hero.y + (hero.y % map.len_pix);
		pt_a->y == hero.y ? pt_a->y += map.len_pix : pt_a->y;
		if (angle < 270)
			pt_a->x = hero.x - (hero.y - pt_a->y) / tan((convert_deg_in_rad(hero.angle - 180)));
		else
			pt_a->x = hero.x + ((hero.y - pt_a->y) / tan((convert_deg_in_rad(360 - hero.angle))));
	}
}

void		get_vector(int angle, int len_pix, t_vect *vector)
{
	if (angle < 180)
	{
		vector->y = len_pix;
		if (angle < 90)
			vector->x = vector->y / tan(convert_deg_in_rad(angle));
		else
			vector->x = -vector->y / tan(convert_deg_in_rad(angle));
	}
	else
	{
		vector->y = lenb_pix;
		if (angle < 270)
			vector->x = vector->y / tan(convert_deg_in_rad(angle));
		else
			vector->x = -vector->y / tan(convert_deg_in_rad(angle));
	}
}

int			is_wall_horizontal(t_point pt, int angle, t_map map)
{
	int		x;
	int		y;

	if (angle < 180)
		y = (pt.y / map.len_pix) - 1;
		else
		y = pt.y / map.len_pix;
	if ((int)pt.x % map.len_pix || (angle < 270 && angle > 90))
		x = pt.x / map.len_pix;
	else
		x = (pt.x / map.len_pix) - 1;
	if (x <= map.height - 1 && x >= 0 && map.map[x][y] == '1')
		return (1);
	if (x >= map.height || x < 0)
		return (2);
	return (0);
}

double		get_hp_horizontal(t_param param, t_map map)
{
	t_point		pt_a;
	t_vect		vector;
	double		hp;

	get_pt_a(param.hero, &pt_a);
	printf("pt(%f,%f)\n", pt_a.x, pt_a.y);
	get_vector(param.hero.angle, map.len_pix, &vector);
	printf("vector(%f,%f)\n", vector.x, vector.y);
	while (!(ret = is_wall_horizontal(pt_a, param.hero.angle, map)))
	{
		pt_a.x += vector.x;
		pt_a.y += map.len_pix;
	}
	/*if (ret == 2)
	  return (-1);*/
	hp = sqrt(pow(hero.y - pt_a.y, 2) + pow(hero.x - pt_a.x, 2));
	return (hp);
}
