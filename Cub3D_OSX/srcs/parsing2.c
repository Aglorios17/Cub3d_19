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

void	linecheck3(t_pos *one, char *line)
{
	char *tmp;

	tmp = NULL;
	if (line[0] == 'C' && one->textc[0] == '\0')
	{
		tmp = one->textc;
		one->textc = ft_strjoin(one->textc, line);
		free(tmp);
	}
	if (line[0] == 'S')
	{
		if (line[1] == 'O' && one->textso[0] == '\0')
		{
			tmp = one->textso;
			one->textso = ft_strjoin(one->textso, line);
			free(tmp);
		}
		if (line[1] == ' ' && one->textobj[0] == '\0')
		{
			tmp = one->textobj;
			one->textobj = ft_strjoin(one->textobj, line);
			free(tmp);
		}
	}
}

void	linecheck2(t_pos *one, char *line)
{
	char *tmp;

	tmp = NULL;
	if (line[0] == 'E' && one->textea[0] == '\0')
	{
		tmp = one->textea;
		one->textea = ft_strjoin(one->textea, line);
		free(tmp);
	}
	if (line[0] == 'F' && one->textf[0] == '\0')
	{
		tmp = one->textf;
		one->textf = ft_strjoin(one->textf, line);
		free(tmp);
	}
	linecheck3(one, line);
}
