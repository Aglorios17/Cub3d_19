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

int	notext(t_pos *one, int h, int w, char *mur)
{
	int i;

	i = 0;
	if (one->textno[i] == 'N' && one->textno[i + 1] == 'O')
		i += 2;
	while (one->textno[i] != '\0' && one->textno[i] == ' ')
		i++;
	mur = &one->textno[i];
	if (!(one->imgno = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	one->addrno = (int*)mlx_get_data_addr(one->imgno, &one->bits_per_pixel,
		&one->line_length, &one->endian);
	return (1);
}

int	sotext(t_pos *one, int h, int w, char *mur)
{
	int i;

	i = 0;
	mur = 0;
	if (one->textso[i] == 'S' && one->textso[i + 1] == 'O')
		i += 2;
	while (one->textso[i] != '\0' && one->textso[i] == ' ')
		i++;
	mur = &one->textso[i];
	if (!(one->imgso = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	one->addrso = (int*)mlx_get_data_addr(one->imgso, &one->bits_per_pixel,
		&one->line_length, &one->endian);
	return (1);
}

int	wetext(t_pos *one, int h, int w, char *mur)
{
	int i;

	i = 0;
	mur = 0;
	if (one->textwe[i] == 'W' && one->textwe[i + 1] == 'E')
		i += 2;
	while (one->textwe[i] != '\0' && one->textwe[i] == ' ')
		i++;
	mur = &one->textwe[i];
	if (!(one->imgwe = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	one->addrwe = (int*)mlx_get_data_addr(one->imgwe, &one->bits_per_pixel,
		&one->line_length, &one->endian);
	return (1);
}

int	eatext(t_pos *one, int h, int w, char *mur)
{
	int i;

	i = 0;
	mur = 0;
	if (one->textea[i] == 'E' && one->textea[i + 1] == 'A')
		i += 2;
	while (one->textea[i] != '\0' && one->textea[i] == ' ')
		i++;
	mur = &one->textea[i];
	if (!(one->imgea = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	one->addrea = (int*)mlx_get_data_addr(one->imgea, &one->bits_per_pixel,
		&one->line_length, &one->endian);
	return (1);
}

int	checktexture(t_pos *one)
{
	int		h;
	int		w;
	char	*mur;

	h = 0;
	w = 0;
	mur = 0;
	if (one->textno[2] != ' ' || notext(one, h, w, mur) == -1)
		return (-1);
	if (one->textso[2] != ' ' || sotext(one, h, w, mur) == -1)
	{
		mlx_destroy_image(one->mlx, one->imgno);
		return (-1);
	}
	if (one->textwe[2] != ' ' || wetext(one, h, w, mur) == -1)
	{
		mlx_destroy_image(one->mlx, one->imgno);
		mlx_destroy_image(one->mlx, one->imgso);
		return (-1);
	}
	if (checktexture2(one, h, w, mur) == -1)
		return (-1);
	return (1);
}
