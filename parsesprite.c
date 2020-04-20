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

#include "cub3d.h"

int parsesprite(pos *one)
{
	int i;
	int j;
	double a;

	i = 0;
	a = 0;
	if (!(one->spriteX = malloc(sizeof(int *) * one->numSprites + 1)))
		return (-1);
	if (!(one->spriteY = malloc(sizeof(int *) * one->numSprites + 1)))
		return (-1);
	while (one->map[i] != '\0')
	{
		j = 0;
		while (one->map[i][j] != '\0')
		{
			if (one->map[i][j] == '2')
			{
				one->spriteX[(int)a] = j + 0.5;
				one->spriteY[(int)a] = i + 0.5;
			//	printf("||%f||", one->spriteX[(int)a]);
			//	printf("||%f||", one->spriteY[(int)a]);
				a++;
			}
			j++;
		}
		i++;
	}
	return (1);	
}
