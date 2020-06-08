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

int	check_errormap(pos *one)
{
	int i;
	int a;
	int j;
	int g;
	int f;

	i = 0;
	a = 0;
	if (one->map[i] == '\0')
	{
		write(1, "MAP ??", 6);
		return (-1);
	}
	while (one->map[i] != '\0')
	{
		if (a < ft_strlen2(one->map[i]))
			a = ft_strlen2(one->map[i]);
		i++;
	}
	f = 0;
	while (one->map[f] != '\0')
		f++;
	g = 0;
	i = 0;
	while (one->map[i])
	{
		if (one->map[i][0] != ' ' &&
			one->map[i][0] != '1' && one->map[i][0] != '\0')
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
				if (one->map[i][j - 1] != '1' &&
					one->map[i][j - 1] != ' ' && one->map[i][j - 1] != '\0')
					g = 1;
				if (one->map[i][j + 1] != '1' &&
					one->map[i][j + 1] != ' ' && one->map[i][j + 1] != '\0')
					g = 1;
				if (one->map[i + 1][j] != '1' &&
					one->map[i + 1][j] != ' ' && one->map[i + 1][j] != '\0')
					g = 1;
				if (one->map[i - 1][j] != '1' &&
					one->map[i - 1][j] != ' ' && one->map[i - 1][j] != '\0')
					g = 1;
				if (one->map[i - 1][j - 1] != '1' &&
					one->map[i - 1][j - 1] != ' ' &&
						one->map[i - 1][j - 1] != '\0')
					g = 1;
				if (one->map[i + 1][j + 1] != '1' &&
					one->map[i + 1][j + 1] != ' ' &&
						one->map[i + 1][j + 1] != '\0')
					g = 1;
				if (one->map[i + 1][j - 1] != '1' &&
					one->map[i + 1][j - 1] != ' ' &&
						one->map[i + 1][j - 1] != '\0')
					g = 1;
				if (one->map[i - 1][j + 1] != '1' &&
					one->map[i - 1][j + 1] != ' ' &&
						one->map[i - 1][j + 1] != '\0')
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
	i = 0;
	while (one->map[i] != '\0')
	{
		j = 0;
		g = 0;
		if (ft_strlen2(one->map[i]) < a)
		{
			j = a - ft_strlen2(one->map[i]);
			while (g < j)
			{
				one->map[i] = ft_strjoin(one->map[i], " ");
				g++;
			}
		}
		i++;
	}
	return (1);
}
