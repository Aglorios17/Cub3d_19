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

void	tmp(t_pos *one, int i, int j, char coord)
{
	double	swap;

	if (coord == 'x')
	{
		swap = one->spritex[i];
		one->spritex[i] = one->spritex[j];
		one->spritex[j] = swap;
	}
	else
	{
		swap = one->spritey[i];
		one->spritey[i] = one->spritey[j];
		one->spritey[j] = swap;
	}
}

void	sortsprites(t_pos *one)
{
	int i;
	int j;

	i = 0;
	while (i < one->numsprites - 1)
	{
		one->spritedistance = ((one->posx - one->spritex[i]) *
			(one->posx - one->spritex[i]) +
			(one->posy - one->spritey[i]) *
			(one->posy - one->spritey[i]));
		j = i + 1;
		while (j < one->numsprites)
		{
			if (((one->posx - one->spritex[j]) *
				(one->posx - one->spritex[j]) +
				(one->posy - one->spritey[j]) *
				(one->posy - one->spritey[j])) > one->spritedistance)
			{
				tmp(one, i, j, 'x');
				tmp(one, i, j, 'y');
			}
			j++;
		}
		i++;
	}
}

void	calculdrawsprite(t_pos *one)
{
	one->vmovescreen = (int)(94 / one->transformy);
	one->spriteheight = (int)fabs((double)one->screenheight /
		one->transformy);
	one->drawstarty = -one->spriteheight / 2 + one->screenheight / 2;
	if (one->drawstarty < 0)
		one->drawstarty = 0;
	one->drawendy = one->spriteheight / 2 + one->screenheight / 2;
	if (one->drawendy >= one->screenheight)
		one->drawendy = one->screenheight - 1;
	one->spritewidth = (int)fabs((double)(one->screenheight /
		(one->transformy)));
	one->drawstartx = -one->spritewidth / 2 + one->spritescreenx;
	if (one->drawstartx < 0)
		one->drawstartx = 0;
	one->drawendx = one->spritewidth / 2 + one->spritescreenx;
	if (one->drawendx >= one->screenwidth)
		one->drawendx = one->screenwidth - 1;
}

int		sprites(t_pos *one)
{
	int i;

	i = 0;
	sortsprites(one);
	while (i < one->numsprites)
	{
		one->sprtx = one->spritex[i] - one->posx;
		one->sprty = one->spritey[i] - one->posy;
		one->invdet = 1.0 / (one->planex * one->diry - one->dirx * one->planey);
		one->transformx = one->invdet *
			(one->diry * one->sprtx - one->dirx * one->sprty);
		one->transformy = one->invdet *
			(-one->planey * one->sprtx + one->planex * one->sprty);
		one->spritescreenx = (int)((one->screenwidth / 2) *
			(1 + one->transformx / one->transformy));
		calculdrawsprite(one);
		stripe(one);
		i++;
	}
	return (1);
}
