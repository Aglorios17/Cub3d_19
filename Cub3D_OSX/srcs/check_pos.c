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

void	lettercheck2(t_pos *one, int i, int j)
{
	if (one->map[i][j] == 'W')
	{
		one->planex = 0;
		one->planey = -0.66;
		one->dirx = -1;
		one->diry = 0;
		one->popo += 1;
	}
	if (one->map[i][j] == 'E')
	{
		one->planex = 0;
		one->planey = 0.66;
		one->dirx = 1;
		one->diry = 0;
		one->popo += 1;
	}
}

void	lettercheck(t_pos *one, int i, int j, int a)
{
	one->posy = i + 0.5;
	one->posx = j + 0.5;
	if (one->map[i][j] == 'S')
	{
		one->planex = -0.66;
		one->planey = 0;
		one->dirx = 0;
		one->diry = 1;
		one->popo += 1;
	}
	if (one->map[i][j] == 'N')
	{
		one->planex = 0.66;
		one->planey = 0;
		one->dirx = 0;
		one->diry = -1;
		one->popo += 1;
	}
	lettercheck2(one, i, j);
	one->map[i][j] = '0';
	a -= a + 1;
}

int		error(t_pos *one, int i, int j, int a)
{
	if (a == 0 && (one->map[i][j] == 'N' ||
		one->map[i][j] == 'S' || one->map[i][j] == 'W' ||
			one->map[i][j] == 'E'))
	{
		if (autour(one, i, j) == -1)
		{
			write(1, "Error\nletter\n", 13);
			return (-1);
		}
		lettercheck(one, i, j, a);
	}
	else
	{
		write(1, "Error\nletter\n", 13);
		return (-1);
	}
	return (1);
}

int		check_pos(t_pos *one)
{
	int i;
	int j;
	int a;

	i = 0;
	a = 0;
	one->popo = 0;
	while (one->map && one->map[i])
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
	if (one->popo != 1)
	{
		write(1, "Error\nposition\n", 14);
		return (-1);
	}
	return (1);
}

int		transform_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
