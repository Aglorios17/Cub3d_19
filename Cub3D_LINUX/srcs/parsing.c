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
	if (checkfonction(one) == -1)
	{
		write(1, "\nError in check parse", 22);
		return (-1);
	}
	return (1);
}

void	linecheck(t_pos *one, char *line)
{
	char *tmp;

	tmp = NULL;
	if (line[0] == 'R' && one->size[0] == '\0')
	{
		tmp = one->size;
		one->size = ft_strjoin(one->size, line);
		free(tmp);
	}
	if (line[0] == 'N' && one->textno[0] == '\0')
	{
		tmp = one->textno;
		one->textno = ft_strjoin(one->textno, line);
		free(tmp);
	}
	if (line[0] == 'W' && one->textwe[0] == '\0')
	{
		tmp = one->textwe;
		one->textwe = ft_strjoin(one->textwe, line);
		free(tmp);
	}
	linecheck2(one, line);
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
	if ((fd = open(file, O_RDONLY)) <= 0)
	{
		write(1, "\nError fail open", 17);
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
