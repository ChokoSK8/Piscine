/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:42:43 by abrun             #+#    #+#             */
/*   Updated: 2020/12/22 12:18:30 by abrun            ###   ########.fr       */
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

typedef struct		s_wall
{
	int			height;
	int			width;
}					t_wall;

typedef struct		s_param
{
	void		*mlx;
	void		*win;
	int			dist;
	t_wall		*wall;
	t_img		*img;
}					t_param;

void		get_wall_dim(int dist, t_wall *wall)
{
	double		div;

	div = (double)dist / 50;
	!div ? div += 1 : div;
	wall->height = 1000 / div;
	wall->width = 800 / div;
}

void				change_color(t_param param, int color)
{
	int		x;
	int		y;
	int		counter;
	int		pos;

	y = 0;
	while (y < param.wall->width)
	{
		x = 0;
		while (x < param.wall->height)
		{
			counter = 0;
			while (counter < 4)
			{
				pos = (((1000 - param.wall->height) / 2 + x) * 4) + (param.img->size_line * (((800 - param.wall->width) / 2 + y))) + counter;
				param.img->data[pos] = color;
				counter++;
			}
			x++;
		}
		y++;
	}
}

int			change_dist(int key, t_param *param)
{
	change_color(*param, 0);
	if (key == 12)
		param->dist -= 1;
	if (key == 6)
		param->dist += 1;
	get_wall_dim(param->dist, param->wall);
	change_color(*param, 100);
	mlx_put_image_to_window(param->mlx, param->win, param->img->image, 0, 0);
	return (1);
}


int		main()
{
	void		*mlx;
	void		*win;
	t_param		param;
	t_wall		wall;
	t_img		img;

	mlx = mlx_init();

	win = mlx_new_window(mlx, 1000, 800, "draw_wall_42");

	int		dist = 50;
	
	get_wall_dim(dist, &wall);
	
	param.mlx = mlx;
	param.win = win;
	param.dist = dist;
	param.wall = &wall;

	
	int		bpp;
	int		size_line;
	int		endian;
	int		img_len = 8;
	void	*image;
	image = mlx_new_image(mlx, 1000, 800);
	char *img_data = mlx_get_data_addr(image, &bpp, &size_line, &endian);

	img.bpp = bpp;
	img.size_line = size_line;
	img.endian = endian;
	img.img_len = img_len;
	img.data = img_data;
	img.image = image;

	param.img = &img;
	
	change_color(param, 100);

	mlx_put_image_to_window(mlx, win, param.img->image, 0, 0);

	mlx_hook(win, 2, 1L<<0, change_dist, &param);

	mlx_loop(mlx);
}
