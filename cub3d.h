/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:35:32 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/24 18:20:01 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

typedef	struct	first
{
	void		*mlx;
	void		*mlx_win;
	double		posX;
	double		posY;
	double		dirX;
	double		oldDirX;
	double		dirY;
	double		planeX;
	double		oldPlaneX;
	double		planeY;
	double		time;
	double		oldtime;
//////////////////////////////////// 
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
///////////////////////////////////
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	//////////////////////////////
	int			lineHeight;
	int			drawStart;
	int			drawEnd;	
	////////////////////////////
	int			color;
	////////////////////////////
//	double		getTicks;
//	double		redraw;
//	double		cls;
	double		frametime;
	double		moveSpeed;
	double		rotSpeed;
	////////////////////////////
	unsigned	sky;
	unsigned	ground;
	unsigned	wall;
}				pos;				

//int				worldMap;
void			*raycast_flat(void *mlx1, pos *one);

#endif
