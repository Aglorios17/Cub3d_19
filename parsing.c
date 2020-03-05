/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:23:42 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/05 17:55:58 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_pos(pos *one)
{
	int i;
	int j;

	i = 0;
	while (one->map[i] != '\0')
	{
		j = 0;
		while (one->map[i][j] != '\0')
		{
			if (ft_isalpha(one->map[i][j]))
			{
				if (one->map[i][j] == 'N' || one->map[i][j] == 'S' || one->map[i][j] == 'W' || one->map[i][j] == 'E')
				{
					one->posY = i + 0.5;
					one->posX = j + 0.5;
					if (one->map[i][j] == 'E')
					{
						one->planeX = 0;
						one->planeY = -0.66;
						one->dirX = 1;
						one->dirY = 0;
					}
					if (one->map[i][j] == 'W')
					{
						one->planeX = 0;
						one->planeY = 0.66;
						one->dirX = -1;
						one->dirY = 0;
					}
					if (one->map[i][j] == 'N')
					{
						one->planeX = 0.66;
						one->planeY = 0;
						one->dirX = 0;
						one->dirY = 1;
					}
					if (one->map[i][j] == 'S')
					{
						one->planeX = -0.66;
						one->planeY = 0;
						one->dirX = 0;
						one->dirY = -1;
					}
					one->map[i][j] = '0';
					return (1);
				}
				else
				{
					write (1, "\nError", 7);
					return (-1);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int transform_to_hex(int r, int g, int b)
{
	return (r<<16 | g<<8 | b);
}

int	check_errordata(pos *one)
{
	int i;
	int j;
	int r;
	int g;
	int b;

	i = 0;
	j = 0;
	r = 0;
	g = 0;
	b = 0;
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
	i = 0;
	while (one->textF[i] != '\0')
	{
		while (one->textF[i] == 'F' || one->textF[i] == ' ')
			i++;
		while (one->textF[i] >= '0' && one->textF[i] <= '9' && one->textF[i] != ',')
		{
			r = r * 10 + (one->textF[i] - 48);
			i++;
		}
		i++;
		while (one->textF[i] >= '0' && one->textF[i] <= '9' && one->textF[i] != ',')
		{
			g = g * 10 + (one->textF[i] - 48);
			i++;
		}
		i++;
		while (one->textF[i] >= '0' && one->textF[i] <= '9' && one->textF[i] != ',')
		{
			b = b * 10 + (one->textF[i] - 48);
			i++;
		}
	}
	if (r > 255 || g > 255 || b > 255)
	{
		write(1, "\nError", 7);
		return (-1);
	}
	one->ground = transform_to_hex(r, g, b);
	i = 0;
	r = 0;
	g = 0;
	b = 0;
	while (one->textC[i] != '\0')
	{
		while (one->textC[i] == 'C' || one->textF[i] == ' ')
			i++;
		while (one->textC[i] >= '0' && one->textC[i] <= '9' && one->textC[i] != ',')
		{
			r = r * 10 + (one->textC[i] - 48);
			i++;
		}
		i++;
		while (one->textC[i] >= '0' && one->textC[i] <= '9' && one->textC[i] != ',')
		{
			g = g * 10 + (one->textC[i] - 48);
			i++;
		}
		i++;
		while (one->textC[i] >= '0' && one->textC[i] <= '9' && one->textC[i] != ',')
		{
			b = b * 10 + (one->textC[i] - 48);
			i++;
		}
	}
	if (r > 255 || g > 255 || b > 255)
	{
		write(1, "\nError", 7);
		return (-1);
	}
	one->sky = transform_to_hex(r, g, b);
//	printf("w||%i||", one->screenwidth);
//	printf("\nh||%i||", one->screenheight);
//	printf("\nr||%i||", r);
//	printf("\ng||%i||", g);
//	printf("\nb||%i||", b);
//	printf("\ng||%u||", one->ground);
	return (1);
}

int	parsing(pos *one, char *file)
{
	int fd;
	int i;
	int j;
	int a;
	char *line = NULL;

	one->map = 0;
	one->datamap = "";
	one->size = "";
	one->textNO = "";
	one->textSO = "";
	one->textWE = "";
	one->textEA = "";
	one->textS = "";
	one->textF = "";
	one->textC = "";
	i = 0;
	j = 0;
	a = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line3d(fd, &line))
	{
		if (line[0] != '\0')
		{
			if (line[0] == 'R')
			{
				one->size = ft_strjoin(one->size, line);
				free(line);
			}
			if (line[0] == 'N')
			{
				one->textNO = ft_strjoin(one->textNO, line);
				free(line);
			}
			if (line[0] == 'W')
			{
				one->textWE = ft_strjoin(one->textWE, line);
				free(line);
			}
			if (line[0] == 'E')
			{
				one->textEA = ft_strjoin(one->textEA, line);
				free(line);
			}
			if (line[0] == 'F')
			{
				one->textF = ft_strjoin(one->textF, line);
				free(line);
			}
			if (line[0] == 'C')
			{
				one->textC = ft_strjoin(one->textC, line);
				free(line);
			}
			if (line[0] == 'S')
			{
				if (line[1] == 'O')
					one->textSO = ft_strjoin(one->textSO, line);
				else
					one->textS = ft_strjoin(one->textS, line);
				free(line);
			}
			a++;
		}
		if (line[0] != '\0' && a > 8)
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
//	printf("||%s||", one->textF);
	one->map = ft_split(one->datamap, '\n');
	if (check_errordata(one) == -1) ///////////////// bug error return
		return (-1);
	if (check_pos(one) == -1)
		return (-1);
	return (1);
}
