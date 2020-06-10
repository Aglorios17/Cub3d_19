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

int		algomap1(t_pos *one, int i)
{
	if (one->map[i] == '\0')
	{
		write(1, "MAP ??", 6);
		return (-1);
	}
	while (one->map[i] != '\0')
	{
		if (one->mapa < ft_strlen2(one->map[i]))
			one->mapa = ft_strlen2(one->map[i]);
		i++;
	}
	while (one->map[one->mapf] != '\0')
		one->mapf++;
	one->mapg = 0;
	i = 0;
	while (one->map[i])
	{
		if (one->map[i][0] != ' ' &&
				one->map[i][0] != '1' && one->map[i][0] != '\0')
			one->mapg = 1;
		if (one->map[i][0] == ' ' && one->map[i][1] == '0')
			one->mapg = 1;
		i++;
	}
	return (1);
}

void	algostrlen(t_pos *one, int i, int j)
{
	i = 0;
	while (one->map[i])
	{
		j = ft_strlen2(one->map[i]) - 1;
		if (one->map[i][j] != '1')
			one->mapg = 1;
		i++;
	}
}

void	algomap2(t_pos *one, int i, int j)
{
	algostrlen(one, i, j);
	i = 0;
	while (one->map[0][i])
	{
		if (one->map[0][i] != '1' && one->map[0][i] != ' ')
			one->mapg = 1;
		if (one->map[0][i] == ' ' && one->map[1][i] == '0')
			one->mapg = 1;
		i++;
	}
	i = 0;
	while (one->map[one->mapf - 1][i])
	{
		if (one->map[one->mapf - 1][i] != '1' &&
				one->map[one->mapf - 1][i] != ' ')
			one->mapg = 1;
		if (one->map[one->mapf - 1][i] == ' ' &&
				one->map[one->mapf - 2][i] == '0')
			one->mapg = 1;
		i++;
	}
}

void	algomap3(t_pos *one, int j, int i)
{
	if (one->map[i][j - 1] != '1' && one->map[i][j - 1] != ' ' &&
			one->map[i][j - 1] != '\0')
		one->mapg = 1;
	if (one->map[i][j + 1] != '1' && one->map[i][j + 1] != ' ' &&
			one->map[i][j + 1] != '\0')
		one->mapg = 1;
	if (one->map[i + 1][j] != '1' && one->map[i + 1][j] != ' ' &&
			one->map[i + 1][j] != '\0')
		one->mapg = 1;
	if (one->map[i - 1][j] != '1' && one->map[i - 1][j] != ' ' &&
			one->map[i - 1][j] != '\0')
		one->mapg = 1;
	if (one->map[i - 1][j - 1] != '1' && one->map[i - 1][j - 1] != ' ' &&
			one->map[i - 1][j - 1] != '\0')
		one->mapg = 1;
	if (one->map[i + 1][j + 1] != '1' && one->map[i + 1][j + 1] != ' ' &&
			one->map[i + 1][j + 1] != '\0')
		one->mapg = 1;
	if (one->map[i + 1][j - 1] != '1' && one->map[i + 1][j - 1] != ' ' &&
			one->map[i + 1][j - 1] != '\0')
		one->mapg = 1;
	if (one->map[i - 1][j + 1] != '1' && one->map[i - 1][j + 1] != ' ' &&
			one->map[i - 1][j + 1] != '\0')
		one->mapg = 1;
}

int		check_errormap(t_pos *one)
{
	int i;
	int j;

	i = 0;
	one->mapa = 0;
	one->mapf = 0;
	if (algomap1(one, i) == -1)
		return (-1);
	j = 0;
	algomap2(one, i, j);
	i = 1;
	while (i < one->mapf - 1)
	{
		j = 1;
		while (j != ft_strlen2(one->map[i - 1]))
		{
			if (one->map[i][j] == ' ')
				algomap3(one, j, i);
			j++;
		}
		i++;
	}
	if (algomap4(one, i, j) == -1)
		return (-1);
	return (1);
}
