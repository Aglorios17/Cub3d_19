/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_flat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:22:28 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/11 15:30:17 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		texture(t_pos *one)
{
	if (one->side == 0)
		one->wallx = one->posy + one->perpwalldist * one->raydiry;
	else
		one->wallx = one->posx + one->perpwalldist * one->raydirx;
	one->wallx -= floor((one->wallx));
	one->texx = (int)(one->wallx * (double)TEXWIDTH);
	if (one->side == 0 && one->raydirx > 0)
		one->texx = TEXWIDTH - one->texx - 1;
	if (one->side == 1 && one->raydiry < 0)
		one->texx = TEXWIDTH - one->texx - 1;
	one->step = 1.0 * TEXWIDTH / one->lineheight;
	one->texpos = (one->drawstart - one->screenheight / 2 +
			one->lineheight / 2) * one->step;
	return (0);
}

void	raycastdraw2(t_pos *one, int x, int y)
{
	if (one->co == 1)
		one->addr[y * one->screenwidth + x] = one->sky;
	else
	{
		one->texy = (int)one->texpos & (TEXHEIGHT - 1);
		one->texpos += one->step;
		one->color = one->addrc[TEXHEIGHT * one->texy + one->texx];
		one->addr[y * one->screenwidth + x] = one->color;
	}
}

void	raycastdraw3(t_pos *one, int x, int y)
{
	one->texy = (int)one->texpos & (TEXHEIGHT - 1);
	one->texpos += one->step;
	if (one->side == 1 && one->raydiry < 0)
		one->color = one->addrno[TEXHEIGHT * one->texy + one->texx];
	if (one->side == 1 && one->raydiry > 0)
		one->color = one->addrso[TEXHEIGHT * one->texy + one->texx];
	if (one->side == 0 && one->raydirx < 0)
		one->color = one->addrwe[TEXHEIGHT * one->texy + one->texx];
	if (one->side == 0 && one->raydirx > 0)
		one->color = one->addrea[TEXHEIGHT * one->texy + one->texx];
	one->addr[y * one->screenwidth + x] = one->color;
}

void	raycastdraw4(t_pos *one, int x, int y)
{
	if (one->fo == 1)
		one->addr[y * one->screenwidth + x] = one->ground;
	else
	{
		one->texy = (int)one->texpos & (TEXHEIGHT - 1);
		one->texpos += one->step;
		one->color = one->addrf[TEXHEIGHT * one->texy + one->texx];
		one->addr[y * one->screenwidth + x] = one->color;
	}
}

void	raycastdraw(t_pos *one, int x)
{
	int y;

	y = 0;
	while (y < one->drawstart)
	{
		raycastdraw2(one, x, y);
		y++;
	}
	while (y <= one->drawend)
	{
		raycastdraw3(one, x, y);
		y++;
	}
	while (y < one->screenheight)
	{
		raycastdraw4(one, x, y);
		y++;
	}
	one->zbuffer[x] = one->perpwalldist;
}
