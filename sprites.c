/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:17:37 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/11 16:09:03 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void tmp(pos *one, int i, int j, char coord)
{
	double	swap;

	if (coord == 'x')
	{
		swap = one->spriteX[i];
		one->spriteX[i] = one->spriteX[j];
		one->spriteX[j] = swap;
	}
	else
	{
		swap = one->spriteY[i];
		one->spriteY[i] = one->spriteY[j];
		one->spriteY[j] = swap;
	}
}

void sortSprites(pos *one)
{
	int i;
	int j;

	i = 0;
	while (i < one->numSprites - 1) 
	{
		one->spriteDistance = ((one->posX - one->spriteX[i]) *
			(one->posX - one->spriteX[i]) +
			(one->posY - one->spriteY[i]) * 
			(one->posY - one->spriteY[i]));
		j = i + 1;
		while (j < one->numSprites)
		{
			if (((one->posX - one->spriteX[j]) *
				(one->posX - one->spriteX[j]) +
				(one->posY - one->spriteY[j]) * 
				(one->posY - one->spriteY[j])) > one->spriteDistance)
			{
				tmp(one, i, j, 'x');
				tmp(one, i, j, 'y');
			}
			j++;
		}
		i++;
	}
}

int	sprites(pos *one)
{
	int i;

	i = 0;
	sortSprites(one);
	while (i < one->numSprites)
	{
		one->sprtX = one->spriteX[i] - one->posX;
		one->sprtY = one->spriteY[i] - one->posY;

		one->invDet = 1.0 / (one->planeX * one->dirY - one->dirX * one->planeY);

		one->transformX = one->invDet * (one->dirY * one->sprtX - one->dirX * one->sprtY);
		one->transformY = one->invDet * (-one->planeY * one->sprtX + one->planeX * one->sprtY);

		one->spriteScreenX = (int)((one->screenwidth / 2) * (1 + one->transformX / one->transformY));
		//////////////////////////////////////////////////////////////////////////////////////////
		one->vmovescreen = (int)(94 / one->transformY);
		one->spriteHeight = (int)fabs((double)one->screenheight / one->transformY);

		one->drawStartY = -one->spriteHeight / 2 + one->screenheight / 2;
		if(one->drawStartY < 0) 
			one->drawStartY = 0;
		one->drawEndY = one->spriteHeight / 2 + one->screenheight / 2;
		if(one->drawEndY >= one->screenheight)
			one->drawEndY = one->screenheight - 1;

		one->spriteWidth = (int)fabs((double)(one->screenheight / (one->transformY)));
		one->drawStartX = -one->spriteWidth / 2 + one->spriteScreenX;
		if (one->drawStartX < 0) 
			one->drawStartX = 0;
		one->drawEndX = one->spriteWidth / 2 + one->spriteScreenX;
		if(one->drawEndX >= one->screenwidth) 
			one->drawEndX = one->screenwidth - 1;
		//////////////////////////////////////////////////////////////////////////////////////////
		int stripe;

		stripe = one->drawStartX;
		while (stripe < one->drawEndX)
		{
			one->texX = (int)((stripe - (-one->spriteWidth / 2 + one->spriteScreenX)) * 64 / one->spriteWidth);
			if (one->transformY > 0 && stripe > 0 && stripe < one->screenwidth && one->transformY < one->zbuffer[stripe] && one->texX < 64)
			{
				int y;
				int d;

				y = one->drawStartY;
				d = 0;
				while (y < one->drawEndY)
				{
					d = y * 256 - one->screenheight * 128 + one->spriteHeight * 128;
					one->texY = ((d * 64) / one->spriteHeight) / 256;
					if ((one->addrobj[64 * one->texY + one->texX] & 0x00FFFFFF) != 0)
						one->addr[y * one->screenwidth + stripe] = one->addrobj[64 * one->texY + one->texX];
					y++;
				}
			}
			stripe++;
		}
		i++;
	}
	return (1);
}
