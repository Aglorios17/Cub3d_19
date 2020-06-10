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

int	spritemalloc(t_pos *one)
{
	if (!(one->spritex = malloc(sizeof(int *) * one->numsprites + 1)))
		return (-1);
	if (!(one->spritey = malloc(sizeof(int *) * one->numsprites + 1)))
		return (-1);
	return (1);
}

int	parsesprite(t_pos *one)
{
	int		i;
	int		j;
	double	a;

	i = 0;
	a = 0;
	if (!(spritemalloc(one)))
		return (-1);
	while (one->map[i] != '\0')
	{
		j = 0;
		while (one->map[i][j] != '\0')
		{
			if (one->map[i][j] == '2')
			{
				one->spritex[(int)a] = j + 0.5;
				one->spritey[(int)a] = i + 0.5;
				a++;
			}
			j++;
		}
		i++;
	}
	return (1);
}
