#include "minilibx/mlx.h"

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void    *mlx;
	void    *mlx_win;
	int x;
	int y;
	int dimx;
	int dimy;
	int carre;
	t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2560, 1440, "Cub3D");
	img.img = mlx_new_image(mlx, 2560, 1440);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	carre = 1400;
	dimy = 1440/2 + carre/2;
	dimx = 2560/2 + carre/2;
	y = dimy - carre;
	while (y < dimy)
	{
		x = dimx - carre;
		while (x < dimx)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
