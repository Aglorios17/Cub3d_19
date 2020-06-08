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
	while (one->textF[i] >= '0' && one->textF[i] <= '9' &&
		one->textF[i] != ',')
	{
		one->r = one->r * 10 + (one->textF[i] - 48);
		i++;
	}
	i++;
	while (one->textF[i] >= '0' && one->textF[i] <= '9' &&
		one->textF[i] != ',')
	{
		one->g = one->g * 10 + (one->textF[i] - 48);
		i++;
	}
	i++;
	while (one->textF[i] >= '0' && one->textF[i] <= '9' &&
		one->textF[i] != ',')
	{
		one->b = one->b * 10 + (one->textF[i] - 48);
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
	while (one->textF[i] != '\0')
	{
		while (one->textF[i] == 'F' || one->textF[i] == ' ')
			i++;
		if (one->textF[i] != '.')
		{
			i = rgb(one, i);
			one->fo = 1;
		}
		else
			i = ft_strlen(one->textF);
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
	while (one->textC[i] >= '0' && one->textC[i] <= '9' &&
		one->textC[i] != ',')
	{
		one->r = one->r * 10 + (one->textC[i] - 48);
		i++;
	}
	i++;
	while (one->textC[i] >= '0' && one->textC[i] <= '9' &&
		one->textC[i] != ',')
	{
		one->g = one->g * 10 + (one->textC[i] - 48);
		i++;
	}
	i++;
	while (one->textC[i] >= '0' && one->textC[i] <= '9' &&
		one->textC[i] != ',')
	{
		one->b = one->b * 10 + (one->textC[i] - 48);
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
	while (one->textC[i] != '\0')
	{
		while (one->textC[i] == 'C' || one->textF[i] == ' ')
			i++;
		if (one->textC[i] != '.')
		{
			i = rgb2(one, i);
			one->co = 1;
		}
		else
			i = ft_strlen(one->textC);
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
