/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:23:42 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/02 15:33:12 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(pos *one, char *file)
{
	int fd;
	char *line = NULL;

	one->map = 0;
	fd = open(file, O_RDONLY);
//	while (ft_get_next_line(fd, &line))
//	{
		if (line == 0)
//		{
			printf("%c", 'K');
//			return (0);
//		}	
//	}
	close(fd);
	//ft_get_next_line(fd, &file);
	return (0);
}
