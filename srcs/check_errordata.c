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

int	rgb(pos *one, int i)
{
	while (one->textf[i] >= '0' && one->textf[i] <= '9' &&
		one->textf[i] != ',')
	{
		one->r = one->r * 10 + (one->textf[i] - 48);
		i++;
	}
	i++;
	while (one->textf[i] >= '0' && one->textf[i] <= '9' &&
		one->textf[i] != ',')
	{
		one->g = one->g * 10 + (one->textf[i] - 48);
		i++;
	}
	i++;
	while (one->textf[i] >= '0' && one->textf[i] <= '9' &&
		one->textf[i] != ',')
	{
		one->b = one->b * 10 + (one->textf[i] - 48);
		i++;
	}
	return (i);
}

int	textf(pos *one)
{
	int i;

	i = 0;
	one->r = 0;
	one->g = 0;
	one->b = 0;
	while (one->textf[i] != '\0')
	{
		while (one->textf[i] == 'F' || one->textf[i] == ' ')
			i++;
		if (one->textf[i] != '.')
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
		write(1, "\nError", 7);
		return (-1);
	}
	return (1);
}

int	rgb2(pos *one, int i)
{
	while (one->textc[i] >= '0' && one->textc[i] <= '9' &&
		one->textc[i] != ',')
	{
		one->r = one->r * 10 + (one->textc[i] - 48);
		i++;
	}
	i++;
	while (one->textc[i] >= '0' && one->textc[i] <= '9' &&
		one->textc[i] != ',')
	{
		one->g = one->g * 10 + (one->textc[i] - 48);
		i++;
	}
	i++;
	while (one->textc[i] >= '0' && one->textc[i] <= '9' &&
		one->textc[i] != ',')
	{
		one->b = one->b * 10 + (one->textc[i] - 48);
		i++;
	}
	return (i);
}

int	textc(pos *one)
{
	int i;

	i = 0;
	one->r = 0;
	one->g = 0;
	one->b = 0;
	while (one->textc[i] != '\0')
	{
		while (one->textc[i] == 'C' || one->textc[i] == ' ')
			i++;
		if (one->textc[i] != '.')
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
		write(1, "\nError", 7);
		return (-1);
	}
	return (1);
}

int	check_errordata(pos *one)
{
	int i;

	i = 0;
	if (rscreen(one, i) == -1)
		return (-1);
	if (textf(one) == -1)
		return (-1);
	one->ground = transform_to_hex(one->r, one->g, one->b);
	if (textc(one) == -1)
		return (-1);
	one->sky = transform_to_hex(one->r, one->g, one->b);
	return (1);
}
