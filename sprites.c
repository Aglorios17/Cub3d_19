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

/*
void sortSprites(int* order, double* dist, int amount, pos *one)
{
	std::vector<std::pair<double, int>> sprites(amount);
	int i;

	i = 0;
	one->numSprites = one->numSprites;
	while (i < amount) 
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	std::sort(sprites.begin(), sprites.end());
	restore in reverse order to go from farthest to nearest
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
}
*/

int	sprites(pos *one)
{
	int i;
	one->numSprites = 19;

	i = 0;
	while (i < one->numSprites)
	{
//		one->spriteOrder[i] = i;
//		one->spriteDistance[i] = ((one->posX - sprite[i].x) + (one->posX - sprite[i].x) + (one->posY - sprite[i].y) * (posY - sprite[i].y));
		i++;
	}
/*	sortSprites(one->spriteOrder, one->spriteDistance, one->numSprites, one);
	i = 0;
	while (i < one->numSprites)
	{
		one->spriteX = sprite[spriteOrder[i]].x - one->posX;
		one->spriteY = sprite[spriteOrder[i]].y - one->posY;

		one->invDet = 1.0 / (one->planeX * one->dirY - one->dirX * one->posX);

		one->transformX = one->invDet * (one->dirY * one->spriteX - one->dirX * one->spriteY);
		one->transformY = one->invDet * (-one->planeY * one->spriteX + one->planeX * one->spriteY);

		one->spriteHeight = abs((int)(one->screenheight / one->transformY));

		one->drawStartY = -one->spriteHeight / 2 + one->screenheight / 2;
		if(one->drawStartY < 0) 
			one->drawStartY = 0;
		one->drawEndY = one->spriteHeight / 2 + one->screenheight / 2;
		if(one->drawEndY >= one->screenheight)
			one->drawEndY = one->screenheight - 1;

		one->spriteWidth = abs((int)(one->screenheight / (one->transformY)));
		one->drawStartX = -one->spriteWidth / 2 + one->spriteScreenX;
		if (one->drawStartX < 0) 
			one->drawStartX = 0;
		one->drawEndX = one->spriteWidth / 2 + one->spriteScreenX;
		if(one->drawEndX >= one->screenwidth) 
			one->drawEndX = one->screenwidth - 1;
		//////////////////////////////////////////////////////////////////////////////////////////
		int stripe;

		stripe = 0;
		while (stripe < one->drawEndX)
		{
			one->texX = (int)((256 * (stripe - (-one->spriteWidth / 2 + one->spriteScreenX)) * texWidth / one->spriteWidth) / 256)
				stripe++;
		}
		if (one->transformY > 0 && stripe > 0 && stripe < one->screenwidth && one->transformY < Zbuffer[stripe])
		{
			int y;

			y = one->drawStartY;
			while (y < one->drawEndY)
			{
				int d;
				d = (y * 256) - (one->screenheight * 128) + (one->spriteHeight * 128);
				one->texY = ((d * one->texHeight) / one->spriteHeight) / 256;
				y++;
			}
		}
		i++;
	}*/
	return (1);
}

