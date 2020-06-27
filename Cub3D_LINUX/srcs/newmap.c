/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsesprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:35:32 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/11 16:09:00 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*new(char *old, int x)
{
	int		i;
	char	*nw;

	i = 0;
	if (!(nw = malloc(x + 1)))
		return (NULL);
	while (old[i])
	{
		nw[i] = old[i];
		i++;
	}
	while (i < x)
		nw[i++] = ' ';
	nw[i] = 0;
	free(old);
	return (nw);
}

int		newmap(t_pos *one)
{
	int		my;
	int		x;

	my = 0;
	x = 0;
	while (one->map[my])
	{
		if (ft_strlen2(one->map[my]) > x)
			x = ft_strlen(one->map[x]);
		my++;
	}
	my = 0;
	while (one->map[my])
	{
		if (ft_strlen2(one->map[my]) < x)
		{
			if (!(one->map[my] = new(one->map[my], x)))
				return (-1);
		}
		my++;
	}
	return (1);
}
