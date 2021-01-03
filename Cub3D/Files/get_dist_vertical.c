/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_vertical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:49:48 by abrun             #+#    #+#             */
/*   Updated: 2020/12/21 17:02:10 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

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
	if (angle < 270 && angle > 90)
	{
		pt_a->x = hero.x + ((int)hero.x % (int)abs.x);
		pt_a->x == hero.x ? pt_a->x += abs.x : pt_a->x;
		if (angle < 180)
			pt_a->y = hero.y + ((hero.x - pt_a->x) * tan(convert_deg_in_rad(180 - angle)));
		else
			pt_a->y = hero.y - ((hero.x - pt_a->x) * tan(convert_deg_in_rad(angle - 180)));
	}
	else
	{
		pt_a->x = hero.x - ((int)hero.x % (int)abs.x);
		pt_a->x == hero.x ? pt_a->x -= abs.x : pt_a->x;
		if (angle < 90)
			pt_a->y = hero.y - ((hero.x - pt_a->x) * tan(convert_deg_in_rad(angle)));
		else
			pt_a->y = hero.y + ((hero.x - pt_a->x) * tan(convert_deg_in_rad(angle - 270)));
	}
}

void		get_vector_vert(double angle, t_point abs, t_vect *vector)
{
	if (angle < 270 && angle > 90)
	{
		vector->x = abs.x;
		if (angle > 180)
			vector->y = vector->x * tan(convert_deg_in_rad(angle - 180));
		else
			vector->y = -vector->x * tan(convert_deg_in_rad(180 - angle));
	}
	else
	{
		vector->x = -abs.x;
		if (angle > 270)
			vector->y = vector->x / tan(convert_deg_in_rad(angle));
		else
			vector->y = -vector->x / tan(convert_deg_in_rad(angle));
	}
}

int			is_wall_vert(t_point pt, double angle, t_map map)
{
	int		x;
	int		y;

	if (angle < 270 && angle > 90)
		x = (pt.x / map.len);
	else
		x = (pt.x / map.len) - 1;
	if (!((int)pt.y % map.len) && (angle < 180))
		y = (pt.y / map.len) - 1;
	else
		y = pt.y / map.len;
	if (y <= map.y_max && map.mat[x][y] == '1')
		return (1);
	if (y > map.y_max)
		return (2);
	return (0);
}

double		get_dist_vert(t_point hero, double angle, t_point abs, t_map map)
{
	t_point		pt_a;
	t_vect		vector;
	double		dist;
	int			ret;

	get_pt_a(hero, angle, abs, &pt_a);
	printf("pt_a(%f,%f)\n", pt_a.x, pt_a.y);
	get_vector_vert(angle, abs, &vector);
	printf("vector(%f,%f)\n", vector.x, vector.y);
	while (!(ret = is_wall_vert(pt_a, angle, map)))
	{
		pt_a.x += vector.x;
		pt_a.y += map.len;
	}
	/*if (ret == 2)
	  return (-1);*/
	dist = sqrt(pow(hero.y - pt_a.y, 2) + pow(hero.x - pt_a.x, 2));
	return (dist);
}

int			main()
{
	t_point		hero;
	t_point		abs;
	double		angle;
	t_map		map;

	abs.x = 100;
	abs.y = 100;

	hero.x = 450;
	hero.y = 550;

	angle = 337;
	get_dist_vert(hero, angle, abs, map);
}
