/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:23:42 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/05 13:50:20 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(pos *one, char *file)
{
	int fd;
	int i;
	int j;
	char *line = NULL;

	one->map = 0;
	one->datamap = "";
	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line3d(fd, &line))
	{
		if (line[0] != '\0')
		{
			one->datamap = ft_strjoin(one->datamap, line);
			free(line);
			one->datamap = ft_strjoin(one->datamap, "\n");
		}
	}
	one->datamap = ft_strjoin(one->datamap, line);
	one->datamap = ft_strjoin(one->datamap, "\0");
	free(line);
	close(fd);
//	printf("map ||\n%s||", one->datamap);
	one->map = ft_split(one->datamap, '\n');
	return (0);
}
