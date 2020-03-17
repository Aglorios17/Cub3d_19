/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsesprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:35:32 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/11 16:09:00 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int parsesprite(one *pos)
{
	int i;
	int j;
	double a;

	i = 0;
	k = 0;
	if (!(one->spriteX = malloc(sizeof(int *) * one->numSprites + 1)))
		return (-1);
	if (!(one->spriteY = malloc(sizeof(int *) * one->numSprites + 1)))
		return (-1);
	while (one->map[i] != '\0')
	{
		while (one->map[i][j] != '\0')
		{
			j = 0;
			if (one->map[i][j] == '2')
			{
				one->spriteX[k] = j + 0.5;
				one->spriteY[k] = i + 0.5;
				k++;
			}
			j++;
		}
		i++:
	}
	return (1);	
}
