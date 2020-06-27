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

int		exit_hook(void *ok, t_pos *one)
{
	(void)ok;
	(void)one;
	exit(1);
	return (0);
}

void	key1(t_pos *one, int keycode)
{
	if (keycode == 65307)
	{
		exit_end(one);
		exit(1);
	}
	if (keycode == 119 || keycode == 65362)
	{
		if (one->map[(int)one->posy][(int)(one->posx + one->dirx *
			0.5)] != '1')
			one->posx += one->dirx * one->movespeed;
		if (one->map[(int)(one->posy + one->diry * 0.5)]
			[(int)one->posx] != '1')
			one->posy += one->diry * one->movespeed;
	}
	if (keycode == 115 || keycode == 65364)
	{
		if (one->map[(int)one->posy][(int)(one->posx - one->dirx *
			0.5)] != '1')
			one->posx -= one->dirx * one->movespeed;
		if (one->map[(int)(one->posy - one->diry * 0.5)]
			[(int)one->posx] != '1')
			one->posy -= one->diry * one->movespeed;
	}
}

void	key2(t_pos *one, int keycode)
{
	if (keycode == 97)
	{
		if (one->map[(int)(one->posy + one->dirx * 0.5)][(int)one->posx] != '1')
			one->posy += one->dirx * 0.4;
		if (one->map[(int)one->posy][(int)(one->posx - one->diry * 0.5)] != '1')
			one->posx -= one->diry * 0.4;
	}
	if (keycode == 100)
	{
		if (one->map[(int)(one->posy - one->dirx * 0.5)][(int)one->posx] != '1')
			one->posy -= one->dirx * 0.4;
		if (one->map[(int)one->posy][(int)(one->posx + one->diry * 0.5)] != '1')
			one->posx += one->diry * 0.4;
	}
}

void	key3(t_pos *one, int keycode)
{
	if (keycode == 65363)
	{
		one->olddirx = one->dirx;
		one->dirx = one->dirx * cos(-(one->rotspeed)) - one->diry *
			sin(-(one->rotspeed));
		one->diry = one->olddirx * sin(-(one->rotspeed)) + one->diry *
			cos(-(one->rotspeed));
		one->oldplanex = one->planex;
		one->planex = one->planex * cos(-(one->rotspeed)) - one->planey *
			sin(-(one->rotspeed));
		one->planey = one->oldplanex * sin(-(one->rotspeed)) + one->planey *
			cos(-(one->rotspeed));
	}
}

int		ft_keyboard(int keycode, t_pos *one)
{
	(void)one;
	one->movespeed = 0.4;
	one->rotspeed = 0.25;
	key1(one, keycode);
	key2(one, keycode);
	key3(one, keycode);
	if (keycode == 65361)
	{
		one->olddirx = one->dirx;
		one->dirx = one->dirx * cos(one->rotspeed) -
			one->diry * sin(one->rotspeed);
		one->diry = one->olddirx * sin(one->rotspeed) +
			one->diry * cos(one->rotspeed);
		one->oldplanex = one->planex;
		one->planex = one->planex * cos(one->rotspeed) -
			one->planey * sin(one->rotspeed);
		one->planey = one->oldplanex * sin(one->rotspeed) +
			one->planey * cos(one->rotspeed);
	}
	raycast_flat(one);
	mlx_put_image_to_window(one->mlx, one->mlx_win, one->img, 0, 0);
	return (0);
}
