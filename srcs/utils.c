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

int	ft_strlen2(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	inittext(pos *one)
{
	one->map = 0;
	one->datamap = "";
	one->size = "";
	one->textno = "";
	one->textso = "";
	one->textwe = "";
	one->textea = "";
	one->textobj = "";
	one->textf = "";
	one->textc = "";
}

int	err(pos *one, int b, int fd, char *line)
{
	if (b < 3)
	{
		write(1, "map error", 9);
		return (-1);
	}
	if (check(one, fd, line) == -1)
		return (-1);
	return (1);
}
