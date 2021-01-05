#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_player
{
	int			x;
	int			y;
	void		*img;
}				player;

typedef struct		s_param
{
	void		*mlx;
	void		*win;
	player		hero;
}					t_param;

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int		deal_key(int key, t_param *param)
{
	printf("key : %d\n", key);
	if (key == 12)
		param->hero.y -= 1;
	if (key == 6)
		param->hero.y += 1;
	if (key == 2)
		param->hero.x += 1;
	if (key == 1)
		param->hero.x -= 1;
	return (0);
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

void		print_map(char **map)
{
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
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
	print_map(map);
	return (map);
}


t_point		*first_pt(char *tab, int pix_len)
{
	t_point		*pt;
	
	pt = malloc(sizeof(t_point));
	pt->x = 200 - (get_width(tab) / 2) * pix_len ;
	pt->y = 200 - (get_height(tab) / 2) * pix_len;
	return (pt);
}

void		display_pix(int pix_len, t_param *param, int n, t_point *pt)
{
	int		i;
	int		j;

	i = 0;
	while(i < pix_len)
	{
		j = 0;
		while (j < pix_len)
		{
			if (n == '1')
				mlx_pixel_put(param->mlx, param->win, pt->x, pt->y, 0x00FF0000);
			else if (n == '0')
				mlx_pixel_put(param->mlx, param->win, pt->x, pt->y, 0x000000FF);
			pt->x += 1;
			j++;
		}
		pt->x -= j;
		pt->y += 1;
		i++;
	}
	pt->y -= pix_len;
}

void		display_map(char **map, t_param *param, char *tab)
{
	t_point		*pt;
	int			pix_len;
	int			i;
	int			j;

	pix_len = 10;
	pt = first_pt(tab, pix_len);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			display_pix(pix_len, param, map[i][j], pt);
			pt->x += pix_len;
			j++;
		}
		pt->x -= pix_len * j;
		pt->y += pix_len;
		i++;
	}
	free(pt);
}

int			keypressed(int key, t_param *param)
{
	if (key == 12)
		param->hero.y -= 1;
	if (key == 6)
		param->hero.y += 1;
	if (key == 2)
		param->hero.x += 1;
	if (key == 1)
		param->hero.x -= 1;
	printf("hero(%d,%d)\n", param->hero.x, param->hero.y);
	return (1);
}

int		main()
{
	void		*mlx;
	void		*win;
	t_param		param;
	void		*img;

	//On crée la connexion avec mlx
	mlx = mlx_init();

	//On crée une fenêtre
	win = mlx_new_window(mlx, 400, 400, "mlx_42");

	//On affiche un pixel
	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);

	param.mlx = mlx;
	param.win = win;

	char		**map;
	char		*tab;
	tab = get_tab();
	map = get_map(tab);
	display_map(map, &param, tab);

	int		bpp;
	int		size_line;
	int		endian;
	int		img_len = 3;
	img = mlx_new_image(mlx, img_len, img_len);
	char *img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

	player Hero;
	Hero.x = 200;
	Hero.y = 200;
	Hero.img = img;
	param.hero = Hero;

	mlx_put_image_to_window(mlx, win, img, Hero.x, Hero.y);

	//Detection touche clavier
//	mlx_key_hook(win, deal_key, &param);

	mlx_hook(win, 2, 1L<<0, keypressed, &param);

	//Gere les évènements
	mlx_loop(mlx);
}
