/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:56:19 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/24 18:19:58 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_keyboard(int keycode, pos *one)
{
	(void)one;
	one->moveSpeed = 0.8;
	one->rotSpeed = 0.3;

	if (keycode == 53)
		exit(1);
	if (keycode == 13 || keycode == 126)
	{
		one->posX += one->dirX * one->moveSpeed;
		one->posY += one->dirY * one->moveSpeed;
	}
	if (keycode == 1 || keycode == 125)
	{
		one->posX -= one->dirX * one->moveSpeed;
		one->posY -= one->dirY * one->moveSpeed;
	}
	if (keycode == 14)
	{
		one->posY -= one->dirX * one->moveSpeed;
		one->posX += one->dirY * one->moveSpeed;
	}
	if (keycode == 12)
	{
		one->posY += one->dirX * one->moveSpeed;
		one->posX -= one->dirY * one->moveSpeed;
	}
	if (keycode == 2 || keycode == 124)
	{
		one->oldDirX = one->dirX;
		one->dirX = one->dirX * cos(-(one->rotSpeed)) - one->dirY * sin(-(one->rotSpeed));
		one->dirY = one->oldDirX * sin(-(one->rotSpeed)) + one->dirY * cos(-(one->rotSpeed));
		one->oldPlaneX = one->planeX;
		one->planeX = one->planeX * cos(-(one->rotSpeed)) - one->planeY * sin(-(one->rotSpeed));
		one->planeY = one->oldPlaneX * sin(-(one->rotSpeed)) + one->planeY * cos(-(one->rotSpeed));
	}
	if (keycode == 0 || keycode == 123)
	{
		one->oldDirX = one->dirX;
		one->dirX = one->dirX * cos(one->rotSpeed) - one->dirY * sin(one->rotSpeed);
		one->dirY = one->oldDirX * sin(one->rotSpeed) + one->dirY * cos(one->rotSpeed);
		one->oldPlaneX = one->planeX;
		one->planeX = one->planeX * cos(one->rotSpeed) - one->planeY * sin(one->rotSpeed);
		one->planeY = one->oldPlaneX * sin(one->rotSpeed) + one->planeY * cos(one->rotSpeed);
	}
//	printf("%i", keycode);
	raycast_flat(one->mlx, one);
	return (0);
}

int main()
{
	pos	one;
	one.sky = 0xCCFFFF;
	one.ground = 0xCC6600;
	one.wall = 0x0000FF;	

	one.mlx = mlx_init();

	one.posX = 22;
	one.posY = 12;
	one.dirX = -1;
	one.dirY = 0;
	one.planeX = 0;
	one.planeY = 0.66;
	one.time = 0;
	one.oldtime = 0;

	one.mlx_win = mlx_new_window(one.mlx, screenWidth, screenHeight, "Cub3D");
	raycast_flat(one.mlx, &one);

	mlx_hook(one.mlx_win, 2, 1L<<0, ft_keyboard, &one);

	mlx_loop(one.mlx);
}
