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

int	rgb(t_pos *one, int i)
{
	one->r = ft_atoi(&one->textf[i]);
	while (one->textf[i] != '\0' && one->textf[i - 1] != ',')
		i++;
	if (one->textf[i] == '\0')
		return (i);
	one->g = ft_atoi(&one->textf[i]);
	i++;
	while (one->textf[i] != '\0' && one->textf[i - 1] != ',')
		i++;
	if (one->textf[i] == '\0')
		return (i);
	one->b = ft_atoi(&one->textf[i]);
	return (i);
}

int	textf(t_pos *one)
{
	int i;

	i = 0;
	one->r = -1;
	one->g = -1;
	one->b = -1;
	if (one->textf[i] != '\0')
	{
		while (one->textf[i] == 'F' || one->textf[i] == ' ')
			i++;
		if (one->textf[i] != '.' && one->textf[i] != ',')
		{
			i = rgb(one, i);
			one->fo = 1;
		}
		else
			i = ft_strlen(one->textf);
	}
	if (one->r > 255 || one->g > 255 || one->b > 255 ||
		one->r < 0 || one->g < 0 || one->b < 0)
	{
		write(1, "\nError color", 13);
		return (-1);
	}
	return (1);
}

int	rgb2(t_pos *one, int i)
{
	one->r = ft_atoi(&one->textc[i]);
	while (one->textc[i] != '\0' && one->textc[i - 1] != ',')
		i++;
	if (one->textc[i] == '\0')
		return (i);
	one->g = ft_atoi(&one->textc[i]);
	i++;
	while (one->textc[i] != '\0' && one->textc[i - 1] != ',')
		i++;
	if (one->textc[i] == '\0')
		return (i);
	one->b = ft_atoi(&one->textc[i]);
	return (i);
}

int	textc(t_pos *one)
{
	int i;

	i = 0;
	one->r = -1;
	one->g = -1;
	one->b = -1;
	if (one->textc[i] != '\0')
	{
		while (one->textc[i] == 'C' || one->textc[i] == ' ')
			i++;
		if (one->textc[i] != '.' && one->textc[i] != ',')
		{
			i = rgb2(one, i);
			one->co = 1;
		}
		else
			i = ft_strlen(one->textc);
	}
	if (one->r > 255 || one->g > 255 || one->b > 255 ||
		one->r < 0 || one->g < 0 || one->b < 0)
	{
		write(1, "\nError color", 13);
		return (-1);
	}
	return (1);
}

int	check_errordata(t_pos *one)
{
	int i;

	i = 0;
	if (rscreen(one, i) == -1)
	{
		write(1, "\nError screen", 14);
		return (-1);
	}
	if (ft_strchr(one->textc, '-') || ft_strchr(one->textf, '-'))
	{
		write(1, "\nError negatif color", 20);
		return (-1);
	}
	if (one->textf[1] != ' ' || textf(one) == -1)
		return (-1);
	one->ground = transform_to_hex(one->r, one->g, one->b);
	if (one->textc[1] != ' ' || textc(one) == -1)
		return (-1);
	one->sky = transform_to_hex(one->r, one->g, one->b);
	return (1);
}
