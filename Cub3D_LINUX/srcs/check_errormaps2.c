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

void	algomap5(t_pos *one, int i, char *tmp)
{
	tmp = one->map[i];
	one->map[i] = ft_strjoin(one->map[i], " ");
	free(tmp);
	one->mapg++;
}

int		algomap4(t_pos *one, int i, int j)
{
	char *tmp;

	tmp = NULL;
	i = 0;
	while (one->map && one->map[i])
	{
		j = 0;
		one->mapg = 0;
		if (ft_strlen2(one->map[i]) < one->mapa)
		{
			j = one->mapa - ft_strlen2(one->map[i]);
			while (one->mapg < j)
				algomap5(one, i, tmp);
		}
		i++;
	}
	if (one->mapg == 1)
	{
		write(1, "\nError map\n", 12);
		return (-1);
	}
	return (1);
}

int		autour(t_pos *one, int i, int j)
{
	if (one->map[i][j - 1] == ' ')
		return (-1);
	if (one->map[i][j + 1] == ' ')
		return (-1);
	if (one->map[i + 1][j] == ' ')
		return (-1);
	if (one->map[i - 1][j] == ' ')
		return (-1);
	if (one->map[i - 1][j - 1] == ' ')
		return (-1);
	if (one->map[i + 1][j + 1] == ' ')
		return (-1);
	if (one->map[i + 1][j - 1] == ' ')
		return (-1);
	if (one->map[i - 1][j + 1] == ' ')
		return (-1);
	return (1);
}
