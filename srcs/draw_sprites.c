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

#include "../include/cub3d.h"

void	drawsprite(pos *one, int stripe)
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
			one->addr[y * one->screenwidth + stripe] =
				one->addrobj[64 * one->texY + one->texX];
		y++;
	}
}

void	stripe(pos *one)
{
	int stripe;

	stripe = one->drawStartX;
	while (stripe < one->drawEndX)
	{
		one->texX = (int)((stripe -
			(-one->spriteWidth / 2 + one->spriteScreenX)) *
				64 / one->spriteWidth);
		if (one->transformY > 0 && stripe > 0 &&
			stripe < one->screenwidth &&
				one->transformY < one->zbuffer[stripe] &&
					one->texX < 64)
			drawsprite(one, stripe);
		stripe++;
	}
}
