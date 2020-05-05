/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:35:32 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/11 16:09:00 by aglorios         ###   ########.fr       */
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
#define screenWidth 1920
#define screenHeight 1080
#define	texWidth 64
#define	texHeight 64

typedef	struct	first
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
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
	unsigned	wall1;
	unsigned	wall2;
	////////////////////////////
	char		**map;
	int			mapwidth;		
	int			mapheight;		
	int			screenwidth;		
	int			screenheight;		
	char		*datamap;
	char		*size;
	char		*textNO;
	char		*textSO;
	char		*textWE;
	char		*textEA;
	char		*textobj;
	char		*textF;
	char		*textC;
	////////////////////////////
	char		*murNO;
	void		*imgNO;
	int			*addrNO;
	////////////////////////////
	char		*murSO;
	void		*imgSO;
	int			*addrSO;
	////////////////////////////
	char		*murWE;
	void		*imgWE;
	int			*addrWE;
	////////////////////////////
	char		*murEA;
	void		*imgEA;
	int			*addrEA;
	////////////////////////////
	char		*murobj;
	void		*imgobj;
	int			*addrobj;
	////////////////////////////
	char		*murF;
	void		*imgF;
	int			*addrF;
	int			fo;
	////////////////////////////
	char		*murC;
	void		*imgC;
	int			*addrC;
	int			co;
	////////////////////////////
	int			texNum;
	int			texcolor;
	int			texX;
	int			texY;
	double		wallX;
	double		step;
	double		texPos;
	int			**buffer;
	////////////////////////////
	int			numSprites;
	int			spriteOrder;
	int			*sprtcolor;
	double		*zbuffer;
	double		spriteDistance;
	double		*spriteX;
	double		*spriteY;
	double		sprtX;
	double		sprtY;
	double		invDet;
	double		transformX;
	double		transformY;
	int			spriteScreenX;
	int			spriteHeight;
	int			spriteWidth;
	int			drawStartY;
	int			drawStartX;
	int			drawEndX;
	int			drawEndY;
	int		vmovescreen;
	int		stripe;
	////////////////////////////
	int		save;
}				pos;				

void			*raycast_flat(void *mlx1, pos *one);
int				ft_keyboard(int keycode, pos *one);
int				parsing(pos *one, char *file);
int				sprites(pos *one);
int				parsesprite(pos *one);
int			bmp(pos *one);

#endif
