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

	y = one->drawstarty;
	d = 0;
	while (y < one->drawendy)
	{
		d = y * 256 - one->screenheight * 128 + one->spriteheight * 128;
		one->texy = ((d * 64) / one->spriteheight) / 256;
		if ((one->addrobj[64 * one->texy + one->texx] & 0x00FFFFFF) != 0)
			one->addr[y * one->screenwidth + stripe] =
				one->addrobj[64 * one->texy + one->texx];
		y++;
	}
}

void	stripe(pos *one)
{
	int stripe;

	stripe = one->drawstartx;
	while (stripe < one->drawendx)
	{
		one->texx = (int)((stripe -
			(-one->spritewidth / 2 + one->spritescreenx)) *
				64 / one->spritewidth);
		if (one->transformy > 0 && stripe > 0 &&
			stripe < one->screenwidth &&
				one->transformy < one->zbuffer[stripe] &&
					one->texx < 64)
			drawsprite(one, stripe);
		stripe++;
	}
}
