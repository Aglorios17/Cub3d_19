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
	free(one->datamap);
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
	while (one->map[i])
		free(one->map[i++]);
	free(one->map);
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
	while (one->map[i])
		free(one->map[i++]);
	free(one->map);
}

int		exit_hook2(void *ok, t_pos *one)
{
	(void)ok;
	exit_end(one);
	exit(1);
	return (0);
}
