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
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef	struct	s_first
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		posx;
	double		posy;
	double		dirx;
	double		olddirx;
	double		diry;
	double		planex;
	double		oldplanex;
	double		planey;
	double		time;
	double		oldtime;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
	double		frametime;
	double		movespeed;
	double		rotspeed;
	unsigned	sky;
	unsigned	ground;
	unsigned	wall1;
	unsigned	wall2;
	char		**map;
	int			mapwidth;
	int			mapheight;
	int			screenwidth;
	int			screenheight;
	char		*datamap;
	char		*size;
	char		*textno;
	char		*textso;
	char		*textwe;
	char		*textea;
	char		*textobj;
	char		*textf;
	char		*textc;
	char		*murno;
	void		*imgno;
	int			*addrno;
	char		*murso;
	void		*imgso;
	int			*addrso;
	char		*murwe;
	void		*imgwe;
	int			*addrwe;
	char		*murea;
	void		*imgea;
	int			*addrea;
	char		*murobj;
	void		*imgobj;
	int			*addrobj;
	char		*murf;
	void		*imgf;
	int			*addrf;
	int			fo;
	char		*murc;
	void		*imgc;
	int			*addrc;
	int			co;
	int			texnum;
	int			texcolor;
	int			texx;
	int			texy;
	double		wallx;
	double		step;
	double		texpos;
	int			**buffer;
	int			numsprites;
	int			spriteorder;
	int			*sprtcolor;
	double		*zbuffer;
	double		spritedistance;
	double		*spritex;
	double		*spritey;
	double		sprtx;
	double		sprty;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			spritewidth;
	int			drawstarty;
	int			drawstartx;
	int			drawendx;
	int			drawendy;
	int			vmovescreen;
	int			stripe;
	int			save;
	int			r;
	int			g;
	int			b;
	int			mapa;
	int			mapg;
	int			mapf;
	int			popo;
	int			agnl;
	int			bgnl;
	int			ex;
}				t_pos;

void			initmain(t_pos *one);
void			*raycast_flat(t_pos *one);
int				ft_keyboard(int keycode, t_pos *one);
void			raycastdraw(t_pos *one, int x);
int				texture(t_pos *one);
int				parsing(t_pos *one, char *file);
void			linecheck2(t_pos *one, char *line);
int				err(t_pos *one, int b, int fd, char *line);
int				check(t_pos *one, int fd, char *line);
int				checkfonction(t_pos *one);
void			inittext(t_pos *one);
int				check_errormap(t_pos *one);
int				check_numsprite(t_pos *one);
int				algomap4(t_pos *one, int i, int j);
int				ft_strlen2(char *s);
int				checktexture(t_pos *one);
int				checktexture2(t_pos *one, int h, int w, char *mur);
int				eatext(t_pos *one, int h, int w, char *mur);
int				objtext(t_pos *one, int h, int w, char *mur);
int				ctext(t_pos *one, int h, int w, char *mur);
int				ftext(t_pos *one, int h, int w, char *mur);
int				check_errordata(t_pos *one);
int				rscreen(t_pos *one, int i);
int				transform_to_hex(int r, int g, int b);
int				check_pos(t_pos *one);
int				sprites(t_pos *one);
void			stripe(t_pos *one);
int				parsesprite(t_pos *one);
int				bmp(t_pos *one);
int				exit_hook2(void *ok, t_pos *one);
void			exit_end(t_pos *one);
void			exit_end2(t_pos *one);
void			exit_end3(t_pos *one);
void			dest(t_pos *one);
void			screenmaxmin(t_pos *one);
int				newmap(t_pos *one);

#endif
