#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

typedef struct		s_param
{
	void		*mlx;
	void		*win;
}					t_param;

typedef struct		s_img
{
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
}					t_img;

void		change_pixel(t_img *image, int x, int y)
{
	int		counter;
	int		start;

	start = x * 4 + 4 * image->size_line * y;
	while (counter < 9000)
	{
		image->data[start + counter] = 126;
		image->data[start + counter + 1] = 126;
		image->data[start + counter + 2] = 126;
		image->data[start + counter + 3] = 126;
		counter += 4;
	}
}

int		main()
{
	void		*mlx;
	void		*win;
	t_param		param;
	t_img		image;
	char		*img_data;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 600, "mlx_42");
	param.mlx = mlx;
	param.win = win;

	image.img = mlx_new_image(mlx, 300, 300);
	image.bpp = 0;
	image.size_line = 0;
	image.endian = 0;
	img_data = mlx_get_data_addr(image.img, &image.bpp, &image.size_line, &image.endian);
	printf("bpp : %d\n", image.bpp);
	printf("size_line : %d\n", image.size_line);
	image.data = img_data;

	unsigned int color = mlx_get_color_value(mlx, 0xAAFFFF);
	printf("color : %u\n", color);

	change_pixel(&image, 0, 0);

	mlx_put_image_to_window(mlx, win, image.img, 100, 100);

	mlx_loop(mlx);
}
