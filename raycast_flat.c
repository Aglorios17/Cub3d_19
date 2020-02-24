/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_flat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:22:28 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/24 18:19:55 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	*raycast_flat(void *mlx1, pos *one)
{
	/////////////////////////////////////////////////////////////////////////

	int	x;

	x = 0;
	while (x < screenWidth)
	{
		one->cameraX = 2 * x / (double)screenWidth - 1;
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
			if (worldMap[one->mapX][one->mapY] > 0) 
				one->hit = 1;
		}
		/////////////////////////////////////////////////////////////////////////
		if (one->side == 0)
			one->perpWallDist = (one->mapX - one->posX + (1 - one->stepX) / 2) / one->rayDirX;
		else
			one->perpWallDist = (one->mapY - one->posY + (1 - one->stepY) / 2) / one->rayDirY;

		one->lineHeight = (int)(screenHeight / one->perpWallDist);
		one->drawStart = -one->lineHeight / 2 + screenHeight / 2; 
		if (one->drawStart < 0)
			one->drawStart = 0;
		one->drawEnd = one->lineHeight / 2 + screenHeight / 2; 
		if (one->drawEnd >= screenHeight)
			one->drawEnd = screenHeight - 1;
		/////////////////////////////////////////////////////////////////////////
		one->color = one->wall;
		if (one->side == 1)
			one->color = one->color / 2;
		int y = 0;
		while (y < one->drawStart)
		{
		
			mlx_pixel_put(mlx1, one->mlx_win, x, y, one->sky);
			y++;
		}
		while (y < one->drawEnd)
		{
			mlx_pixel_put(mlx1, one->mlx_win, x, y, one->color);
			y++;
		}
		while (y < screenHeight)
		{	
			mlx_pixel_put(mlx1, one->mlx_win, x, y, one->ground);
			y++;
		}
		x++;
	}
	return (NULL);
}
