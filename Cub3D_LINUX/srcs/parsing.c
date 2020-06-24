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

int		check_numsprite(t_pos *one)
{
	int i;
	int j;

	i = 0;
	if (!one->map)
		return (-1);
	while (one->map[i])
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

int		check(t_pos *one, int fd, char *line)
{
	char *fr;

	fr = 0;
	if (!one->size)
		return (-1);
	fr = one->datamap;
	one->datamap = ft_strjoin(fr, line);
	free(fr);
	fr = one->datamap;
	one->datamap = ft_strjoin(fr, "\0");
	free(fr);
	free(line);
	close(fd);
	fr = one->datamap;
	one->map = ft_split(fr, '\n');
	free(one->datamap);
	if (checkfonction(one) == -1)
		return (-1);
	return (1);
}

void	linecheck(t_pos *one, char *line)
{
	if (line[0] == 'R' && one->size[0] == '\0')
		one->size = ft_strjoin(one->size, line);
	if (line[0] == 'N' && one->textno[0] == '\0')
		one->textno = ft_strjoin(one->textno, line);
	if (line[0] == 'W' && one->textwe[0] == '\0')
		one->textwe = ft_strjoin(one->textwe, line);
	if (line[0] == 'E' && one->textea[0] == '\0')
		one->textea = ft_strjoin(one->textea, line);
	if (line[0] == 'F' && one->textf[0] == '\0')
		one->textf = ft_strjoin(one->textf, line);
	if (line[0] == 'C' && one->textc[0] == '\0')
		one->textc = ft_strjoin(one->textc, line);
	if (line[0] == 'S')
	{
		if (line[1] == 'O' && one->textso[0] == '\0')
			one->textso = ft_strjoin(one->textso, line);
		if (line[1] == ' ' && one->textobj[0] == '\0')
			one->textobj = ft_strjoin(one->textobj, line);
	}
}

int		mapgnl(t_pos *one, char *line, int a, int b)
{
	char *fr;

	if (line[0] != '\0' && a > 8)
	{
		fr = one->datamap;
		one->datamap = ft_strjoin(fr, line);
		free(fr);
		fr = one->datamap;
		one->datamap = ft_strjoin(fr, "\n");
		free(fr);
		b = 1;
	}
	return (b);
}

int		parsing(t_pos *one, char *file)
{
	int		fd;
	char	*line;

	inittext(one);
	line = NULL;
	one->datamap = ft_strdup("");
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
		free(line);
	}
	if (err(one, one->bgnl, fd, line) == -1)
		return (-1);
	return (1);
}
