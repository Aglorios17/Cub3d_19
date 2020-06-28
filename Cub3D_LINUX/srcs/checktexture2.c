/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:23:42 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/11 16:08:54 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		objtext(t_pos *one, int h, int w, char *mur)
{
	int i;

	i = 0;
	mur = 0;
	if (one->textobj[i] == 'S')
		i += 2;
	while (one->textobj[i] != '\0' && one->textobj[i] == ' ')
		i++;
	mur = &one->textobj[i];
	if (!(one->imgobj = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "\nError path texture", 19);
		return (-1);
	}
	one->addrobj = (int*)mlx_get_data_addr(one->imgobj, &one->bits_per_pixel,
		&one->line_length, &one->endian);
	return (1);
}

int		ftext(t_pos *one, int h, int w, char *mur)
{
	int i;

	i = 0;
	mur = 0;
	if (one->fo != 1)
	{
		if (one->textf[i] == 'F')
			i += 2;
		while (one->textf[i] != '\0' && one->textf[i] == ' ')
			i++;
		mur = &one->textf[i];
		if (!(one->imgf = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
		{
			write(1, "\nError path texture", 19);
			return (-1);
		}
		one->addrf = (int*)mlx_get_data_addr(one->imgf,
			&one->bits_per_pixel, &one->line_length, &one->endian);
	}
	return (1);
}

int		ctext(t_pos *one, int h, int w, char *mur)
{
	int i;

	i = 0;
	mur = 0;
	if (one->co != 1)
	{
		if (one->textc[i] == 'C')
			i += 2;
		while (one->textc[i] != '\0' && one->textc[i] == ' ')
			i++;
		mur = &one->textc[i];
		if (!(one->imgc = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
		{
			write(1, "\nError path texture", 19);
			return (-1);
		}
		one->addrc = (int*)mlx_get_data_addr(one->imgc, &one->bits_per_pixel,
		&one->line_length, &one->endian);
	}
	return (1);
}

int		checktexture2(t_pos *one, int h, int w, char *mur)
{
	if (one->textea[2] != ' ' || eatext(one, h, w, mur) == -1)
	{
		mlx_destroy_image(one->mlx, one->imgwe);
		mlx_destroy_image(one->mlx, one->imgso);
		mlx_destroy_image(one->mlx, one->imgno);
		return (-1);
	}
	if (one->textobj[1] != ' ' || objtext(one, h, w, mur) == -1)
	{
		mlx_destroy_image(one->mlx, one->imgwe);
		mlx_destroy_image(one->mlx, one->imgso);
		mlx_destroy_image(one->mlx, one->imgno);
		mlx_destroy_image(one->mlx, one->imgea);
		return (-1);
	}
	if (ftext(one, h, w, mur) == -1)
		return (-1);
	if (ctext(one, h, w, mur) == -1)
		return (-1);
	return (1);
}
