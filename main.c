/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:56:19 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/26 15:54:36 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	pos	one;
	one.sky = 0xCCFFFF;
	one.ground = 0xCC6600;
	one.wall = 0x0000FF;	

	one.mlx = mlx_init();

	one.posX = 12;
	one.posY = 12;
	one.dirX = -1;
	one.dirY = 0;
	one.planeX = 0;
	one.planeY = 0.66;
	one.time = 0;
	one.oldtime = 0;
	one.bits_per_pixel = 0;
	one.line_length = 0;
	one.endian = 0;

	one.mlx_win = mlx_new_window(one.mlx, screenWidth, screenHeight, "Cub3D");
	one.img = mlx_new_image(one.mlx, screenWidth, screenHeight);
	one.addr = (int*)mlx_get_data_addr(one.img, &one.bits_per_pixel, &one.line_length, &one.endian);
	
	raycast_flat(one.mlx, &one);
	mlx_put_image_to_window(one.mlx, one.mlx_win, one.img, 0, 0);
	mlx_hook(one.mlx_win, 2, 1L<<0, ft_keyboard, &one);


	mlx_loop(one.mlx);
}
