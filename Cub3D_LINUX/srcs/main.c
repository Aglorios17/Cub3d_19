/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:56:19 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/07 09:45:25 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init(t_pos *one)
{
	one->sky = 0;
	one->ground = 0;
	one->wall1 = 0x0000FF;
	one->wall2 = 0xFF99CC;
	one->posx = 0;
	one->posy = 0;
	one->dirx = 0;
	one->diry = 0;
	one->planex = 0;
	one->planey = 0;
	one->time = 0;
	one->oldtime = 0;
	one->bits_per_pixel = 0;
	one->line_length = 0;
	one->endian = 0;
	one->screenheight = 0;
	one->screenwidth = 0;
	one->spritescreenx = 0;
	one->vmovescreen = 0;
	one->numsprites = 0;
	one->fo = 0;
	one->co = 0;
	one->zbuffer = 0;
	one->save = 0;
	initmain(one);
}

int		errorcheck(int argc, char **argv, t_pos *one)
{
	if (!ft_strchr(argv[1], '.') || (argc >= 2 && ft_strchr(argv[1], '.') &&
		ft_strncmp(ft_strchr(argv[1], '.'), ".cub", 4)))
	{
		write(1, "\nError extention.cub", 21);
		exit_end3(one);
		return (-1);
	}
	if (argc != 2)
	{
		if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
			one->save = 1;
		else
		{
			write(1, "\nError arguments", 18);
			exit_end3(one);
			return (-1);
		}
	}
	if (parsing(one, argv[1]) == -1)
	{
		write(1, "\nError Parsing", 15);
		return (-1);
	}
	screenmaxmin(one);
	return (1);
}

int		conf(int argc, char **argv, t_pos *one)
{
	init(one);
	one->mlx = mlx_init();
	if (errorcheck(argc, argv, one) == -1)
	{
		exit_end2(one);
		return (-1);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_pos	one;

	if (conf(argc, argv, &one) == -1)
		return (-1);
	one.img = mlx_new_image(one.mlx, one.screenwidth, one.screenheight);
	one.addr = (int*)mlx_get_data_addr(one.img, &one.bits_per_pixel,
		&one.line_length, &one.endian);
	raycast_flat(&one);
	if (one.save == 0)
	{
		one.mlx_win = mlx_new_window(one.mlx, one.screenwidth,
			one.screenheight, "Cub3D");
		mlx_hook(one.mlx_win, 17, 0, exit_hook2, (void*)&one);
	}
	if (one.save == 5)
	{
		write(1, "\nError bmp", 11);
		exit_end(&one);
		return (-1);
	}
	main_hok(&one);
	mlx_loop(one.mlx);
	exit_end(&one);
	return (0);
}
