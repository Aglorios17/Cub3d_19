/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:56:19 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/07 09:45:25 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	exit_end3(t_pos *one)
{
	free(one->mlx);
	exit(1);
}

void	exit_end2(t_pos *one)
{
	int i;

	i = 0;
	free(one->mlx);
	free(one->spritex);
	free(one->spritey);
	free(one->size);
	free(one->textno);
	free(one->textso);
	free(one->textwe);
	free(one->textea);
	free(one->textf);
	free(one->textc);
	free(one->textobj);
	while (one->map && *one->map && one->map[i])
	{
		free(one->map[i]);
		i++;
	}
	if (one->map)
		free(one->map);
	if (one->datamap)
		free(one->datamap);
	exit(1);
}

void	exit_end(t_pos *one)
{
	int i;

	i = 0;
	if (one->img)
		mlx_destroy_image(one->mlx, one->img);
	if (one->mlx && one->mlx_win)
		mlx_destroy_window(one->mlx, one->mlx_win);
	free(one->spritex);
	free(one->spritey);
	free(one->size);
	free(one->textno);
	free(one->textso);
	free(one->textwe);
	free(one->textea);
	free(one->textf);
	free(one->textc);
	free(one->textobj);
	while (one->map && one->map[i])
		free(one->map[i++]);
	free(one->map);
}

void	screenmaxmin(t_pos *one)
{
	if (one->screenwidth > 5120)
		one->screenwidth = 2560;
	if (one->screenheight > 2880)
		one->screenheight = 1440;
	if (one->screenwidth < 720)
		one->screenwidth = 720;
	if (one->screenheight < 480)
		one->screenheight = 480;
}

int		exit_hook2(void *ok, t_pos *one)
{
	(void)ok;
	exit_end(one);
	exit(1);
	return (0);
}
