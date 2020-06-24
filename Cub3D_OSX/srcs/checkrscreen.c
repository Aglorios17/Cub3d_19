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

int	rscreen(t_pos *one, int i)
{
	i = 1;
	while (one->size[i] == ' ')
		i++;
	if (!ft_isdigit(one->size[i]))
		return (-1);
	one->screenwidth = ft_atoi(&one->size[i]);
	while (ft_isdigit(one->size[i]))
		i++;
	while (one->size[i] == ' ')
		i++;
	if (!ft_isdigit(one->size[i]))
		return (-1);
	one->screenheight = ft_atoi(&one->size[i]);
	while (ft_isdigit(one->size[i]))
		i++;
	if (one->size[i] != '\0')
		return (-1);
	if (one->screenheight <= 0 || one->screenwidth <= 0)
	{
		write(1, "screen ?!", 15);
		return (-1);
	}
	else
		return (1);
}
