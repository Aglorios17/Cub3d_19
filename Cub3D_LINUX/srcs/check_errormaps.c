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

int		algomap1suite(t_pos *one, int maxy)
{
	int j;

	j = 0;
	while (one->map[maxy - 1][j] == ' ')
		j++;
	if (one->map[maxy - 1][j] != '1')
		return (-1);
	while (one->map[maxy - 1][j])
	{
		if (one->map[maxy - 1][j] != '1' && one->map[maxy - 1][j] != ' ')
			return (-1);
		j++;
	}
	return (1);
}

int		algomap1(t_pos *one)
{
	int j;
	int maxy;

	j = 0;
	maxy = 0;
	while (one->map[maxy])
		maxy++;
	one->mapf = maxy;
	while (one->map[0][j] == ' ')
		j++;
	if (one->map[0][j] != '1')
		return (-1);
	while (one->map[0][j])
	{
		if (one->map[0][j] != '1' && one->map[0][j] != ' ')
			return (-1);
		j++;
	}
	if (algomap1suite(one, maxy) == -1)
		return (-1);
	return (1);
}

int		algomap2(t_pos *one)
{
	int	i;
	int j;

	i = 1;
	while (one->map[i + 1])
	{
		j = 0;
		while (one->map[i][j] == ' ')
			j++;
		if (one->map[i][j] != '1')
			return (-1);
		while (one->map[i][j])
		{
			if ((one->map[i][j] < '0' ||
				one->map[i][j] > '2') && one->map[i][j] != ' ')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	algomap3(t_pos *one, int j, int i)
{
	if (one->map[i][j - 1] == ' ')
		one->mapg = 1;
	if (one->map[i][j + 1] == ' ')
		one->mapg = 1;
	if (one->map[i + 1][j] == ' ')
		one->mapg = 1;
	if (one->map[i - 1][j] == ' ')
		one->mapg = 1;
	if (one->map[i - 1][j - 1] == ' ')
		one->mapg = 1;
	if (one->map[i + 1][j + 1] == ' ')
		one->mapg = 1;
	if (one->map[i + 1][j - 1] == ' ')
		one->mapg = 1;
	if (one->map[i - 1][j + 1] == ' ')
		one->mapg = 1;
}

int		check_errormap(t_pos *one)
{
	int i;
	int j;

	i = 0;
	one->mapa = 0;
	one->mapf = 0;
	if (algomap1(one) == -1 || algomap2(one) == -1)
		return (-1);
	i = 1;
	while (one->map && one->map[i + 1])
	{
		j = 1;
		while (one->map[i][j + 1])
		{
			if (one->map[i][j] == '0' || one->map[i][j] == '2')
				if (autour(one, i, j) == -1)
					return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
