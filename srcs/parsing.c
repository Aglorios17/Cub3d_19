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
				one->numSprites += 1;
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
		one->textNO = ft_strjoin(one->textNO, line);
	if (line[0] == 'W')
		one->textWE = ft_strjoin(one->textWE, line);
	if (line[0] == 'E')
		one->textEA = ft_strjoin(one->textEA, line);
	if (line[0] == 'F')
		one->textF = ft_strjoin(one->textF, line);
	if (line[0] == 'C')
		one->textC = ft_strjoin(one->textC, line);
	if (line[0] == 'S')
	{
		if (line[1] == 'O')
			one->textSO = ft_strjoin(one->textSO, line);
		else
			one->textobj = ft_strjoin(one->textobj, line);
	}
}

void	mapgnl(pos *one, char *line, int a)
{
	if (line[0] != '\0' && a > 8)
	{
		one->datamap = ft_strjoin(one->datamap, line);
		free(line);
		one->datamap = ft_strjoin(one->datamap, "\n");
	}
}

int	parsing(pos *one, char *file)
{
	int fd;
	int a;
	char	*line;

	inittext(one);
	line = NULL;
	a = 0;
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
			a++;
		}
		mapgnl(one, line, a);
	}
	if (check(one, fd, line) == -1)
		return (-1);
	return (1);
}
