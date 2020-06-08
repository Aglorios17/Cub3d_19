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

int	checktexture(pos *one)
{
	int i;
	int h;
	int w;
	char *mur;

	h = 0;
	w = 0;
	i = 0;
	mur = 0;
	if (one->textNO[i] == 'N' && one->textNO[i + 1] == 'O')
		i += 2;
	while (one->textNO[i] != '\0' && one->textNO[i] == ' ')
		i++;
	mur = ft_strdup(&one->textNO[i]);
	if (!(one->imgNO = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "\nError", 7);
		return (-1);
	}
	one->addrNO = (int*)mlx_get_data_addr(one->imgNO, &one->bits_per_pixel, &one->line_length, &one->endian); 
	/////////////////////////////////////////////////////////////////////////////////////
	i = 0;
	mur = 0;
	if (one->textSO[i] == 'S' && one->textSO[i + 1] == 'O')
		i += 2;
	while (one->textSO[i] != '\0' && one->textSO[i] == ' ')
		i++;
	mur = ft_strdup(&one->textSO[i]);
	if (!(one->imgSO = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "\nError", 7);
		return (-1);
	}
	one->addrSO = (int*)mlx_get_data_addr(one->imgSO, &one->bits_per_pixel, &one->line_length, &one->endian);
	/////////////////////////////////////////////////////////////////////////////////////
	i = 0;
	mur = 0;
	if (one->textWE[i] == 'W' && one->textWE[i + 1] == 'E')
		i += 2;
	while (one->textWE[i] != '\0' && one->textWE[i] == ' ')
		i++;
	mur = ft_strdup(&one->textWE[i]);
	if (!(one->imgWE = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "\nError", 7);
		return (-1);
	}
	one->addrWE = (int*)mlx_get_data_addr(one->imgWE, &one->bits_per_pixel, &one->line_length, &one->endian);
	/////////////////////////////////////////////////////////////////////////////////////
	i = 0;
	mur = 0;
	if (one->textEA[i] == 'E' && one->textEA[i + 1] == 'A')
		i += 2;
	while (one->textEA[i] != '\0' && one->textEA[i] == ' ')
		i++;
	mur = ft_strdup(&one->textEA[i]);
	if (!(one->imgEA = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "\nError", 7);
		return (-1);
	}
	one->addrEA = (int*)mlx_get_data_addr(one->imgEA, &one->bits_per_pixel, &one->line_length, &one->endian);
/////////////////////////////////////////////////////////////////////////////////////
	i = 0;
	mur = 0;
	if (one->textobj[i] == 'S')
		i += 2;
	while (one->textobj[i] != '\0' && one->textobj[i] == ' ')
		i++;
	mur = ft_strdup(&one->textobj[i]);
	if (!(one->imgobj = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "\nError", 7);
		return (-1);
	}
	one->addrobj = (int*)mlx_get_data_addr(one->imgobj, &one->bits_per_pixel, &one->line_length, &one->endian);
	/////////////////////////////////////////////////////////////////////////////////////
	i = 0;
	mur = 0;
	if (one->fo != 1)
	{
		if (one->textF[i] == 'F')
			i += 2;
		while (one->textF[i] != '\0' && one->textF[i] == ' ')
			i++;
		mur = ft_strdup(&one->textF[i]);
		if (!(one->imgF = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
		{
			write(1, "\nError", 7);
			return (-1);
		}
		one->addrF = (int*)mlx_get_data_addr(one->imgF, &one->bits_per_pixel, &one->line_length, &one->endian);
	}
	/////////////////////////////////////////////////////////////////////////////////////
	i = 0;
	mur = 0;
	if (one->co != 1)
	{
		if (one->textC[i] == 'C')
			i += 2;
		while (one->textC[i] != '\0' && one->textC[i] == ' ')
			i++;
		mur = ft_strdup(&one->textC[i]);
		if (!(one->imgC = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
		{
			write(1, "\nError", 7);
			return (-1);
		}
		one->addrC = (int*)mlx_get_data_addr(one->imgC, &one->bits_per_pixel, &one->line_length, &one->endian);
	}
	return (1);
}
