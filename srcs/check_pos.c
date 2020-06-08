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

void	lettercheck2(pos *one, int i, int j)
{
	if (one->map[i][j] == 'W')
	{
		one->planeX = 0;
		one->planeY = 0.66;
		one->dirX = -1;
		one->dirY = 0;
	}
	if (one->map[i][j] == 'E')
	{
		one->planeX = 0;
		one->planeY = -0.66;
		one->dirX = 1;
		one->dirY = 0;
	}
}

void	lettercheck(pos *one, int i, int j, int a)
{
	one->posY = i + 0.5;
	one->posX = j + 0.5;
	if (one->map[i][j] == 'S')
	{
		one->planeX = 0.66;
		one->planeY = 0;
		one->dirX = 0;
		one->dirY = 1;
	}
	if (one->map[i][j] == 'N')
	{
		one->planeX = -0.66;
		one->planeY = 0;
		one->dirX = 0;
		one->dirY = -1;
	}
	lettercheck2(one, i, j);
	one->map[i][j] = '0';
	a = 1;
}

int	error(pos *one, int i, int j, int a)
{
	if (a == 0 && (one->map[i][j] == 'N' ||
		one->map[i][j] == 'S' || one->map[i][j] == 'W' ||
			one->map[i][j] == 'E'))
		lettercheck(one, i, j, a);
	else
	{
		write(1, "\nError", 7);
		return (-1);
	}
	return (1);
}

int	check_pos(pos *one)
{
	int i;
	int j;
	int a;

	i = 0;
	a = 0;
	while (one->map[i] != '\0')
	{
		j = 0;
		while (one->map[i][j] != '\0')
		{
			if (ft_isalpha(one->map[i][j]))
				if (error(one, i, j, a) == -1)
					return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	transform_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
