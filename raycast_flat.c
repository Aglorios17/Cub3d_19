/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_flat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:22:28 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/07 10:08:05 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_keyboard(int keycode, pos *one)
{
	(void)one;
	one->moveSpeed = 0.5;
	one->rotSpeed = 0.2;

	if (keycode == 53)
		exit(1);
	if (keycode == 13 || keycode == 126)
	{
		if (one->map[(int)one->posY][(int)(one->posX + one->dirX * one->moveSpeed)] == '0')
			one->posX += one->dirX * one->moveSpeed;
		if (one->map[(int)(one->posY + one->dirY * one->moveSpeed)][(int)one->posX] == '0')
			one->posY += one->dirY * one->moveSpeed;
	}
	if (keycode == 1 || keycode == 125)
	{
		if (one->map[(int)one->posY][(int)(one->posX - one->dirX * one->moveSpeed)] == '0')
			one->posX -= one->dirX * one->moveSpeed;
		if (one->map[(int)(one->posY - one->dirY * one->moveSpeed)][(int)one->posX] == '0')
			one->posY -= one->dirY * one->moveSpeed;
	}
	if (keycode == 14) /////////////// bug
	{
		if (one->map[(int)(one->posY - one->dirX * one->moveSpeed)][(int)one->posX] == '0')
			one->posY -= one->dirX * one->moveSpeed;
		if (one->map[(int)one->posY][(int)(one->posX + one->dirX * one->moveSpeed)] == '0')
			one->posX += one->dirY * one->moveSpeed;
	}
	if (keycode == 12)
	{
		if (one->map[(int)(one->posY + one->dirX * one->moveSpeed)][(int)one->posX] == '0')
			one->posY += one->dirX * one->moveSpeed;
		if (one->map[(int)one->posY][(int)(one->posX - one->dirX * one->moveSpeed)] == '0')
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
	mlx_put_image_to_window(one->mlx, one->mlx_win, one->img, 0, 0);
	return (0);
}

int		texture(pos *one)
{
	if (one->side == 0)
		one->wallX = one->posY + one->perpWallDist * one->rayDirY;
	else
		one->wallX = one->posX + one->perpWallDist * one->rayDirX;
	one->wallX -= floor((one->wallX));
	one->texX = (int)(one->wallX * (double)texWidth);
	if (one->side == 0 && one->rayDirX > 0)
		one->texX = texWidth - one->texX - 1;
	if (one->side == 1 && one->rayDirY < 0)
		one->texX = texWidth - one->texX - 1;

	one->step = 1.0 * texWidth / one->lineHeight;
	one->texPos = (one->drawStart - one->screenheight / 2 + one->lineHeight / 2) * one->step;
	return (0);
}

void	*raycast_flat(void *mlx1, pos *one)
{
	int	x;

	x = 0;
	mlx1 = 0;
	while (x < one->screenwidth)
	{
		one->cameraX = 2 * x / (double)one->screenwidth - 1;
		one->rayDirX = one->dirX + one->planeX * one->cameraX;
		one->rayDirY = one->dirY + one->planeY * one->cameraX;

		/////////////////////////////////////////////////////////////////////////
		one->mapX = (int)one->posX;
		one->mapY = (int)one->posY;

		one->deltaDistX = fabs(1 / one->rayDirX);
		one->deltaDistY = fabs(1 / one->rayDirY);

		one->hit = 0;

		/////////////////////////////////////////////////////////////////////////
		if (one->rayDirX < 0)
		{
			one->stepX = -1;
			one->sideDistX = (one->posX - one->mapX) * one->deltaDistX;
		}
		else
		{
			one->stepX = 1;
			one->sideDistX = (one->mapX + 1.0 - one->posX) * one->deltaDistX;
		}
		if (one->rayDirY < 0)
		{
			one->stepY = -1;
			one->sideDistY = (one->posY - one->mapY) * one->deltaDistY;
		}
		else
		{
			one->stepY = 1;
			one->sideDistY = (one->mapY + 1.0 - one->posY) * one->deltaDistY;
		}
		while (one->hit == 0)
		{
			if (one->sideDistX < one->sideDistY)
			{
				one->sideDistX += one->deltaDistX;
				one->mapX += one->stepX;
				one->side = 0;
			}
			else
			{
				one->sideDistY += one->deltaDistY;
				one->mapY += one->stepY;
				one->side = 1;
			}
			if (one->map[one->mapY][one->mapX] > '0') 
				one->hit = 1;
		}
		/////////////////////////////////////////////////////////////////////////
		if (one->side == 0)
			one->perpWallDist = (one->mapX - one->posX + (1 - one->stepX) / 2) / one->rayDirX;
		else
			one->perpWallDist = (one->mapY - one->posY + (1 - one->stepY) / 2) / one->rayDirY;

		one->lineHeight = (int)(one->screenheight / one->perpWallDist);
		one->drawStart = -one->lineHeight / 2 + one->screenheight / 2; 
		if (one->drawStart < 0)
			one->drawStart = 0;
		one->drawEnd = one->lineHeight / 2 + one->screenheight / 2; 
		if (one->drawEnd >= one->screenheight)
			one->drawEnd = one->screenheight - 1;

		texture(one);
		/////////////////////////////////////////////////////////////////////////
		//if (one->side == 2) /// MARCHE PLUS
		//	one->wall1 = one->wall2;
		int y = 0;
		while (y < one->drawStart)
		{
			if (one->co == 1)
				one->addr[y * one->screenwidth + x] = one->sky;
			else
			{
				one->texY = (int)one->texPos & (texHeight - 1);
				one->texPos += one->step;
				one->color = one->addrC[texHeight * one->texY + one->texX];
				one->addr[y * one->screenwidth + x] = one->color;
			}
			y++;
		}
	//	texture(one, x);
		while (y <= one->drawEnd)
		{
			one->texY = (int)one->texPos & (texHeight - 1);
			one->texPos += one->step;
			if (one->side == 1 && one->rayDirY < 0)
				one->color = one->addrNO[texHeight * one->texY + one->texX];
			if (one->side == 1 && one->rayDirY > 0)
				one->color = one->addrSO[texHeight * one->texY + one->texX];
			if (one->side == 0 && one->rayDirX < 0)
				one->color = one->addrWE[texHeight * one->texY + one->texX];
			if (one->side == 0 && one->rayDirX > 0)
				one->color = one->addrEA[texHeight * one->texY + one->texX];
			one->addr[y * one->screenwidth + x] = one->color;
		//	printf("||%i||", one->texX);
			y++;
		}
		while (y < one->screenheight)
		{
			if (one->fo == 1)
				one->addr[y * one->screenwidth + x] = one->ground;
			else
			{
				one->texY = (int)one->texPos & (texHeight - 1);
				one->texPos += one->step;
				one->color = one->addrF[texHeight * one->texY + one->texX];
				one->addr[y * one->screenwidth + x] = one->color;
			}
			y++;
		}
//		printf("\nDirX||%f||", one->rayDirX);
//		printf("\nDirY||%f||", one->rayDirY);
//		printf("\nSide||%d||", one->side);
		x++;
	}
	return (NULL);
}
