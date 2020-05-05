/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:56:19 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/07 09:45:25 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    exit_hook2(void *ok)
{
	(void)ok;
	exit(1);
	return (0);
}


int main(int argc, char **argv)
{
	pos	one;
	one.sky = 0;
	one.ground = 0;
	one.wall1 = 0x0000FF;	
	one.wall2 = 0xFF99CC;	

	one.mlx = mlx_init();

	one.posX = 0;
	one.posY = 0;
	one.dirX = 0;
	one.dirY = 0;
	one.planeX = 0;
	one.planeY = 0;
	one.time = 0;
	one.oldtime = 0;
	one.bits_per_pixel = 0;
	one.line_length = 0;
	one.endian = 0;
	one.screenheight = 0;
	one.screenwidth = 0;
	one.spriteScreenX = 0;
	one.vmovescreen = 0;
	one.numSprites = 0;
	one.fo = 0;
	one.co = 0;
	one.zbuffer = 0;

	one.save = 0;
	if (argc != 2)
	{
		if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
			one.save = 1;	
		else
		{
			write(1, "\nError", 7);
			return (-1);
		}
	}
	if (parsing(&one, argv[1]) == -1)
	{
		write(1, "\nError Parsing", 15);
		return (-1);
	}

	if (one.screenwidth > 5120)
		one.screenwidth = 2560;
	if (one.screenheight > 2880)
		one.screenheight = 1440;
	if (one.screenwidth < 720)
		one.screenwidth = 720;
	if (one.screenheight < 480)
		one.screenheight = 480;

	one.mlx_win = mlx_new_window(one.mlx, one.screenwidth, one.screenheight, "Cub3D");
	one.img = mlx_new_image(one.mlx, one.screenwidth, one.screenheight);
	one.addr = (int*)mlx_get_data_addr(one.img, &one.bits_per_pixel, &one.line_length, &one.endian);

	mlx_hook(one.mlx_win, 17, 0, exit_hook2, (void*)&one);
	raycast_flat(one.mlx, &one);
	if (one.save == 5)
	{
		write(1, "\nError bmp", 11);
		return (-1);
	}
	mlx_put_image_to_window(one.mlx, one.mlx_win, one.img, 0, 0);
	mlx_hook(one.mlx_win, 2, 1L<<0, ft_keyboard, &one);

	mlx_loop(one.mlx);
	return (0);
}
