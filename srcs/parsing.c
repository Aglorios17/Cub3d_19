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

int	check_numsprite(pos *one)
{
	int i;
	int j;

	i = 0;
	while (one->map[i] != '\0')
	{
		j = 0;
		while (one->map[i][j] != '\0')
		{
			if (one->map[i][j] == '2')
				one->numsprites += 1;
			j++;
		}
		i++;
	}
	return (1);
}

int	check(pos *one, int fd, char *line)
{
	if (!one->size)
		return (-1);
	one->datamap = ft_strjoin(one->datamap, line);
	one->datamap = ft_strjoin(one->datamap, "\0");
	free(line);
	close(fd);
	one->map = ft_split(one->datamap, '\n');
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

void	linecheck(pos *one, char *line)
{
	if (line[0] == 'R')
		one->size = ft_strjoin(one->size, line);
	if (line[0] == 'N')
		one->textno = ft_strjoin(one->textno, line);
	if (line[0] == 'W')
		one->textwe = ft_strjoin(one->textwe, line);
	if (line[0] == 'E')
		one->textea = ft_strjoin(one->textea, line);
	if (line[0] == 'F')
		one->textf = ft_strjoin(one->textf, line);
	if (line[0] == 'C')
		one->textc = ft_strjoin(one->textc, line);
	if (line[0] == 'S')
	{
		if (line[1] == 'O')
			one->textso = ft_strjoin(one->textso, line);
		else
			one->textobj = ft_strjoin(one->textobj, line);
	}
}

int	mapgnl(pos *one, char *line, int a, int b)
{
	if (line[0] != '\0' && a > 8)
	{
		one->datamap = ft_strjoin(one->datamap, line);
		free(line);
		one->datamap = ft_strjoin(one->datamap, "\n");
		b = 1;
	}
	return (b);
}

int	parsing(pos *one, char *file)
{
	int	fd;
	char	*line;

	inittext(one);
	line = NULL;
	one->agnl = 0;
	one->bgnl = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		write(1, "fail open", 9);
		return (-1);
	}
	while (get_next_line3d(fd, &line))
	{
		if (line[0] != '\0')
		{
			linecheck(one, line);
			one->agnl++;
		}
		if (mapgnl(one, line, one->agnl, one->bgnl) == 1)
			one->bgnl++;
	}
	if (err(one, one->bgnl, fd, line) == -1)
		return (-1);
	return (1);
}
