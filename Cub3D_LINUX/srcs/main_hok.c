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

void	main_hok(t_pos *one)
{
	mlx_put_image_to_window(one->mlx, one->mlx_win, one->img, 0, 0);
	mlx_hook(one->mlx_win, 2, 1L << 0, ft_keyboard, one);
	mlx_hook(one->mlx_win, 17, 1L << 17, exit_hook, (void*)one);
	mlx_hook(one->mlx_win, 15, 1L << 16, visi, one);
}
