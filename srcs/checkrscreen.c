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

int	rscreen(pos *one, int i)
{
	while (one->size[i] != '\0')
	{
		if (one->size[i] == 'R' || one->size[i] == ' ')
			i++;
		while (one->size[i] >= '0' && one->size[i] <= '9')
		{
			one->screenheight = one->screenheight * 10 + (one->size[i] - 48);
			i++;
		}
		if (one->size[i] == ' ')
		{
			i++;
			while (one->size[i] >= '0' && one->size[i] <= '9')
			{
				one->screenwidth = one->screenwidth * 10 + (one->size[i] - 48);
				i++;
			}
		}
	}
	if (one->screenheight == 0 || one->screenwidth == 0)
	{
		write(1, "screen with 0 !", 15);
		return (-1);
	}
	return (1);
}
