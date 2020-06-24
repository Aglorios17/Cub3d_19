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

int	algomap4(t_pos *one, int i, int j)
{
	if (one->mapg == 1)
	{
		write(1, "\nError", 7);
		return (-1);
	}
	i = 0;
	while (one->map[i])
	{
		j = 0;
		one->mapg = 0;
		if (ft_strlen2(one->map[i]) < one->mapa)
		{
			j = one->mapa - ft_strlen2(one->map[i]);
			while (one->mapg < j)
			{
				one->map[i] = ft_strjoin(one->map[i], " ");
				one->mapg++;
			}
		}
		i++;
	}
	return (1);
}
