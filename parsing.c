/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:23:42 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/09 15:16:42 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_pos(pos *one)
{
	int i;
	int j;
	int a;

	i = 0;
	a = 0;
	while (one->map[i] != '\0')
	{
		j = 0;
		while (one->map[i][j] != '\0')
		{
			if (ft_isalpha(one->map[i][j]))
			{
				if (a == 0 && (one->map[i][j] == 'N' || one->map[i][j] == 'S' || one->map[i][j] == 'W' || one->map[i][j] == 'E'))
				{
					one->posY = i + 0.5;
					one->posX = j + 0.5;
					if (one->map[i][j] == 'S')
					{
						one->planeX = 0.66;
						one->planeY = 0;
						one->dirX = 0;
						one->dirY = 1;
					}
					if (one->map[i][j] == 'N')
					{
						one->planeX = -0.66;
						one->planeY = 0;
						one->dirX = 0;
						one->dirY = -1;
					}
					if (one->map[i][j] == 'W')
					{
						one->planeX = 0;
						one->planeY = 0.66;
						one->dirX = -1;
						one->dirY = 0;
					}
					if (one->map[i][j] == 'E')
					{
						one->planeX = 0;
						one->planeY = -0.66;
						one->dirX = 1;
						one->dirY = 0;
					}
					one->map[i][j] = '0';
					a = 1;
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
		if (one->textF[i] != '.')
		{
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
			one->fo = 1;
		}
		else
			i = ft_strlen(one->textF);		
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
		if (one->textC[i] != '.')
		{
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
			one->co = 1;
		}
		else
			i = ft_strlen(one->textC);		

	}
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
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

int	checktexture(pos *one)
{
	int i;
	int h;
	int w;
	char *mur;

	h = 0;
	w = 0;
	i = 0;
	mur = 0;
	if (one->textNO[i] == 'N' && one->textNO[i + 1] == 'O')
		i += 2;
	while (one->textNO[i] != '\0' && one->textNO[i] == ' ')
		i++;
	mur = ft_strdup(&one->textNO[i]);
	if (!(one->imgNO = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "\nError", 7);
		return (-1);
	}
	one->addrNO = (int*)mlx_get_data_addr(one->imgNO, &one->bits_per_pixel, &one->line_length, &one->endian); 
	/////////////////////////////////////////////////////////////////////////////////////
	i = 0;
	mur = 0;
	if (one->textSO[i] == 'S' && one->textSO[i + 1] == 'O')
		i += 2;
	while (one->textSO[i] != '\0' && one->textSO[i] == ' ')
		i++;
	mur = ft_strdup(&one->textSO[i]);
	if (!(one->imgSO = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "\nError", 7);
		return (-1);
	}
	one->addrSO = (int*)mlx_get_data_addr(one->imgSO, &one->bits_per_pixel, &one->line_length, &one->endian);
	/////////////////////////////////////////////////////////////////////////////////////
	i = 0;
	mur = 0;
	if (one->textWE[i] == 'W' && one->textWE[i + 1] == 'E')
		i += 2;
	while (one->textWE[i] != '\0' && one->textWE[i] == ' ')
		i++;
	mur = ft_strdup(&one->textWE[i]);
	if (!(one->imgWE = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "\nError", 7);
		return (-1);
	}
	one->addrWE = (int*)mlx_get_data_addr(one->imgWE, &one->bits_per_pixel, &one->line_length, &one->endian);
	/////////////////////////////////////////////////////////////////////////////////////
	i = 0;
	mur = 0;
	if (one->textEA[i] == 'E' && one->textEA[i + 1] == 'A')
		i += 2;
	while (one->textEA[i] != '\0' && one->textEA[i] == ' ')
		i++;
	mur = ft_strdup(&one->textEA[i]);
	if (!(one->imgEA = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
	{
		write(1, "\nError", 7);
		return (-1);
	}
	one->addrEA = (int*)mlx_get_data_addr(one->imgEA, &one->bits_per_pixel, &one->line_length, &one->endian);
	/////////////////////////////////////////////////////////////////////////////////////
	i = 0;
	mur = 0;
	if (one->fo != 1)
	{
		if (one->textF[i] == 'F')
			i += 2;
		while (one->textF[i] != '\0' && one->textF[i] == ' ')
			i++;
		mur = ft_strdup(&one->textF[i]);
		if (!(one->imgF = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
		{
			write(1, "\nError", 7);
			return (-1);
		}
		one->addrF = (int*)mlx_get_data_addr(one->imgF, &one->bits_per_pixel, &one->line_length, &one->endian);
	}
	/////////////////////////////////////////////////////////////////////////////////////
	i = 0;
	mur = 0;
	if (one->co != 1)
	{
		if (one->textC[i] == 'C')
			i += 2;
		while (one->textC[i] != '\0' && one->textC[i] == ' ')
			i++;
		mur = ft_strdup(&one->textC[i]);
		if (!(one->imgC = mlx_xpm_file_to_image(one->mlx, mur, &h, &w)))
		{
			write(1, "\nError", 7);
			return (-1);
		}
		one->addrC = (int*)mlx_get_data_addr(one->imgC, &one->bits_per_pixel, &one->line_length, &one->endian);
	}
	//	printf("\nmur||%s||", mur);
	//	printf("\n&||%s||", &one->textNO[i]);
	//	printf("\n&||%s||", &one->textSO[i]);
	//	printf("\n&||%s||", &one->textWE[i]);
	//	printf("\n&||%s||", &one->textEA[i]);
	//	printf("\n&||%s||", &one->textF[i]);
	//	printf("\n&||%s||", &one->textC[i]);
	//	printf("\n||%s||", one->textNO);
	return (1);
}

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

int	check_errormap(pos *one)
{
	int i;
	int	a;
	int j;
	int g;
	int f;

	i = 0;
	a = 0;
	while (one->map[i] != '\0')
	{
		if (a < ft_strlen2(one->map[i]))
			a = ft_strlen2(one->map[i]);
		i++;
	}

	f = 0;
	while (one->map[f] != '\0')
	{
		//		printf("\n%s|", one->map[f]);
		f++;
	}
//	printf("f|\n%i|", f);
	//	printf("a|\n%i|", a);
	g = 0;
	i = 0;
//	while (one->map[f][i] != '\0')
//	{
//		if (one->map[f][i] != ' ' && one->map[f][i] != '1')
//			g = 1;
//		i++;
//	}

	i = 0;
	while (one->map[i])
	{
		if (one->map[i][0] != ' ' && one->map[i][0] != '1' && one->map[i][0] != '\0')
			g = 1;
		if (one->map[i][0] == ' ' && one->map[i][1] == '0')
			g = 1;
		i++;
	}

	i = 0;
	while (one->map[i])
	{
		j = ft_strlen2(one->map[i]) - 1;
		if (one->map[i][j] != '1')
			g = 1;
		i++;
	}

	i = 0;
	while (one->map[0][i])
	{
		if (one->map[0][i] != '1' && one->map[0][i] != ' ')
			g = 1;
		if (one->map[0][i] == ' ' && one->map[1][i] == '0')
			g = 1;
		i++;
	}

	i = 0;
	while (one->map[f - 1][i])
	{
		if (one->map[f - 1][i] != '1' && one->map[f - 1][i] != ' ')
			g = 1;
		if (one->map[f - 1][i] == ' ' && one->map[f - 2][i] == '0')
			g = 1;
		i++;
	}

	i = 1;
	while (i < f - 1)
	{
		j = 1;
		while (j != ft_strlen2(one->map[i - 1]))
		{
			if (one->map[i][j] == ' ')
			{
				if (one->map[i][j - 1] != '1' && one->map[i][j - 1] != ' ' && one->map[i][j - 1] != '\0')
					g = 1;
				if (one->map[i][j + 1] != '1' && one->map[i][j + 1] != ' ' && one->map[i][j + 1] != '\0')
					g = 1;
				if (one->map[i + 1][j] != '1' && one->map[i + 1][j] != ' ' && one->map[i + 1][j] != '\0')
					g = 1;
				if (one->map[i - 1][j] != '1' && one->map[i - 1][j] != ' ' && one->map[i - 1][j] != '\0')
					g = 1;
				if (one->map[i - 1][j - 1] != '1' && one->map[i - 1][j - 1] != ' ' && one->map[i - 1][j - 1] != '\0')
					g = 1;
				if (one->map[i + 1][j + 1] != '1' && one->map[i + 1][j + 1] != ' ' && one->map[i + 1][j + 1] != '\0')
					g = 1;
				if (one->map[i + 1][j - 1] != '1' && one->map[i + 1][j - 1] != ' ' && one->map[i + 1][j - 1] != '\0')
					g = 1;
				if (one->map[i - 1][j + 1] != '1' && one->map[i - 1][j + 1] != ' ' && one->map[i - 1][j + 1] != '\0')
					g = 1;
			}
			j++;
		}
		i++;
	}
	if (g == 1)
	{
		write(1, "\nError", 7);
		return (-1);
	}

	//	printf("a |%d|", a);
	i = 0;
	while (one->map[i] != '\0')
	{
		j = 0;
		g = 0;
		if (ft_strlen2(one->map[i]) < a)
		{
			j = a - ft_strlen2(one->map[i]);
			//			printf("j |%d|", j);
			while (g < j)
			{
				one->map[i] = ft_strjoin(one->map[i], " ");
				g++;
			}
		}
		i++;
	}
	/*	f = 0;
		while (one->map[f] != '\0')
		{
		printf("\n%s|", one->map[f]);
		f++;
		}*/
	//	printf("f|\n%i|", f);
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
	//	printf("||%s||", one->textNO);
	one->map = ft_split(one->datamap, '\n');
	if (check_pos(one) == -1)
		return (-1);
	if (check_errormap(one) == -1)
		return (-1);
	if (check_errordata(one) == -1)
		return (-1);
	if (checktexture(one) == -1)
		return (-1);
	return (1);
}
