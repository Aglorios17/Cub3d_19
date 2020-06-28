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

int		ft_strlen2(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	initmain(t_pos *one)
{
	one->datamap = NULL;
	one->spritex = 0;
	one->spritey = 0;
	one->size = 0;
	one->textno = 0;
	one->textso = 0;
	one->textwe = 0;
	one->textea = 0;
	one->textf = 0;
	one->textc = 0;
	one->textobj = 0;
	one->mlx = 0;
	one->mlx_win = 0;
	one->ex = 0;
}

void	inittext(t_pos *one)
{
	one->map = 0;
	one->datamap = 0;
	one->size = ft_strdup("");
	one->textno = ft_strdup("");
	one->textso = ft_strdup("");
	one->textwe = ft_strdup("");
	one->textea = ft_strdup("");
	one->textobj = ft_strdup("");
	one->textf = ft_strdup("");
	one->textc = ft_strdup("");
	one->agnl = 0;
	one->bgnl = 0;
}

int		err(t_pos *one, int b, int fd, char *line)
{
	if (b < 3)
	{
		write(1, "map error", 9);
		free(line);
		return (-1);
	}
	if (check(one, fd, line) == -1)
		return (-1);
	return (1);
}

int		checkfonction(t_pos *one)
{
	if (check_pos(one) == -1)
		return (-1);
	if (check_errormap(one) == -1)
		return (-1);
	if (check_errordata(one) == -1)
		return (-1);
	if (check_numsprite(one) == -1)
		return (-1);
	if (parsesprite(one) == -1)
		return (-1);
	if (checktexture(one) == -1)
		return (-1);
	return (1);
}
