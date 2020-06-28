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

void	raycastcam(t_pos *one, int x)
{
	one->camerax = 2 * x / (double)one->screenwidth - 1;
	one->raydirx = one->dirx + one->planex * one->camerax;
	one->raydiry = one->diry + one->planey * one->camerax;
	one->mapx = (int)one->posx;
	one->mapy = (int)one->posy;
	one->deltadistx = fabs(1 / one->raydirx);
	one->deltadisty = fabs(1 / one->raydiry);
	one->hit = 0;
}

void	drawcalcul(t_pos *one, int x)
{
	if (one->side == 0)
	{
		one->perpwalldist = (one->mapx - one->posx +
			(1 - one->stepx) / 2) / one->raydirx;
	}
	else
	{
		one->perpwalldist = (one->mapy - one->posy +
			(1 - one->stepy) / 2) / one->raydiry;
	}
	one->lineheight = (int)(one->screenheight / one->perpwalldist);
	one->drawstart = -one->lineheight / 2 + one->screenheight / 2;
	if (one->drawstart < 0)
		one->drawstart = 0;
	one->drawend = one->lineheight / 2 + one->screenheight / 2;
	if (one->drawend >= one->screenheight)
		one->drawend = one->screenheight - 1;
	texture(one);
	raycastdraw(one, x);
}

void	raycast2(t_pos *one, int x)
{
	raycastcam(one, x);
	if (one->raydirx < 0)
	{
		one->stepx = -1;
		one->sidedistx = (one->posx - one->mapx) * one->deltadistx;
	}
	else
	{
		one->stepx = 1;
		one->sidedistx = (one->mapx + 1.0 - one->posx) * one->deltadistx;
	}
	if (one->raydiry < 0)
	{
		one->stepy = -1;
		one->sidedisty = (one->posy - one->mapy) * one->deltadisty;
	}
	else
	{
		one->stepy = 1;
		one->sidedisty = (one->mapy + 1.0 - one->posy) * one->deltadisty;
	}
}

void	raycast(t_pos *one, int x)
{
	raycast2(one, x);
	while (one->hit == 0)
	{
		if (one->sidedistx < one->sidedisty)
		{
			one->sidedistx += one->deltadistx;
			one->mapx += one->stepx;
			one->side = 0;
		}
		else
		{
			one->sidedisty += one->deltadisty;
			one->mapy += one->stepy;
			one->side = 1;
		}
		if (one->map[one->mapy][one->mapx] == '1')
			one->hit = 1;
	}
	drawcalcul(one, x);
}

int		raycast_flat(t_pos *one)
{
	int	x;

	x = 0;
	if (!(one->zbuffer = malloc(sizeof(int *) * one->screenwidth + 1)))
		return (0);
	while (x < one->screenwidth)
	{
		raycast(one, x);
		x++;
	}
	sprites(one);
	if (one->save == 1)
	{
		if (!bmp(one))
			one->save = 5;
		else
			one->save = 0;
		exit(1);
	}
	free(one->zbuffer);
	return (0);
}
