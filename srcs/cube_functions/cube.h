/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 18:37:30 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/24 16:30:23 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include "../mlx/mlx.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

#define ESC 53
#define W_KEY 13
#define S_KEY 1
#define A_KEY 0
#define D_KEY 2
#define UP_KEY 126
#define DOW_KEY 125
#define LEF_KEY 123
#define RIG_KEY 124

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_place {
	int			x;
	int			y;
	int			w;
	int			h;
	int			col;
	int			s_width;
	int			s_height;
	int			dir;
	char		*NO;
	char		*SO;
	char		*EA;
	char		*S;
	char		*WE;
	int			i;
	int			Fcol1;
	int			Fcol2;
	int			Fcol3;
	int			Ccol1;
	int			Ccol2;
	int			Ccol3;
	int			error;
	int			error_c;
	int			error_n;
	int			check_double;
	char		**cubemap;
	int			mapx;
	int			mapy;
	int			mapp;
	int			mapE;
	int			mapc;

	int			crouch;
}				t_place;

typedef struct	s_Double {
	int			D_R;
	int			D_NO;
	int			D_SO;
	int			D_EA;
	int			D_S;
	int			D_WE;

	int			D_F;
	int			D_C;
}				t_Double;

typedef struct	s_Ray {

	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
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
	int			h;
	int			x;
	int			yy;
	int			yyy;
	int			xx;
	int			eh;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			texNum;
	double		wallX;
	int			texX;
	int			texY;
	double		step;
	double		texPos;
	int			look;
}				t_Ray;

typedef struct	s_texture {
	void		*texture;
	int			*texture_adress;
	int			line_lenght;
	int			bits_per_pixel;
	int			texture_width;
	int			texture_height;
	int			endian;

}				t_texture;

typedef struct	s_sprite {

	double		spritex;
	double		spritey;
	double		invDet;

	double		transformX;
	double		transformY;

	int			spriteScreenX;
	int			vMoveScreen;

	int			spriteHeight;

	int			drawStartY;
	int			drawendY;
	int			drawStartX;
	int			drawendX;

	int			spriteWidth;
	int			stripe;

	double		first;
	int			second;

	int			begin;
	int			end;
}				t_sprite;

typedef struct	s_sprites {

	double		x;
	double		y;

}				t_sprites;

typedef	struct	s_keys {

	int			W;
	int			S;
	int			A;
	int			D;
	int			UP;
	int			DOW;
	int			LEF;
	int			RIG;
	float	rayDirX0;
	float	rayDirY0;
	float	rayDirX1;
	float	rayDirY1;
	int		p;
	float	posZ;
	float	rowDistance;
	float	floorStepX;
	float	floorStepY;
	float	floorX;
	float	floorY;
	int		cellX;
	int		cellY;
	int		tx;
	int		ty;
	int		colour;

}				t_keys;

typedef struct	s_struct_m {
	t_data		img;
	t_vars		vars;
	t_place		place;
	t_Double	Double;
	t_Ray		Ray;
	t_texture	texture[5];
	t_sprite	sprite;
	t_sprites	*sprites;
	t_keys		keys;

	int			numSprites;
	double		*ZBuffer;
	int			*spriteOrder;
	double		*spriteDistance;
	char		**cubecopy;
	char		**cubecopytwo;
	int			count;
	char		*map;
}				t_struct_m;

void			my_mlx_pixel_put(t_struct_m *main, int x, int y, int color);
int				wasd(int keycode, t_struct_m *main);

void			cube(t_struct_m *main);
int				background(t_struct_m *main);
int				ft_read_map(t_struct_m *main);
int				ft_read_map_where(t_struct_m *main, char *map);
int				ft_get_info(t_struct_m *main, char *map);
int				ft_strnstr_map(const char *haystack, const char *needle,
size_t len);
int				ft_check_for_map(char *map, t_struct_m *main);

int				ft_read_EA(t_struct_m *main, char *map);
int				ft_read_C(t_struct_m *main, char *map);
int				ft_read_F(t_struct_m *main, char *map);
int				ft_read_NO(t_struct_m *main, char *map);
int				ft_read_R(t_struct_m *main, char *map);
int				ft_read_S(t_struct_m *main, char *map);
int				ft_read_SO(t_struct_m *main, char *map);
int				ft_read_WE(t_struct_m *main, char *map);
void			ft_read_cubecube(t_struct_m *main, char *map);

void			set_value_texture_no(t_struct_m *main, int fd);
void			set_value_texture_so(t_struct_m *main, int fd);
void			set_value_texture_we(t_struct_m *main, int fd);
void			set_value_texture_s(t_struct_m *main, int fd);
void			set_value_texture_ea(t_struct_m *main, int fd);

void			wasd_s_d(t_struct_m *main, double movesp, double rotsp);
void			wasd_a(t_struct_m *main, double movesp, double rotsp);
void			wasd_r_l(t_struct_m *main, double movesp, double rotsp);
void			readmap(t_struct_m *main);
void			read_string(t_struct_m *main, char *map);
void			ft_check(t_struct_m *main, char *map);

int				check_R(t_struct_m *main, char *map, int i);
int				check_NO(t_struct_m *main, char *map, int i);
int				check_SO(t_struct_m *main, char *map, int i);
int				check_S(t_struct_m *main, char *map, int i);
int				check_WE(t_struct_m *main, char *map, int i);
int				check_EA(t_struct_m *main, char *map, int i);
int				check_F(t_struct_m *main, char *map, int i);
int				check_C(t_struct_m *main, char *map, int i);
void			set_value(t_struct_m *main);

void			ft_error(t_struct_m *main);

int				ft_size_store_map(t_struct_m *main);
int				get_size_map(t_struct_m *main, char *map);
int				ft_map_line(t_struct_m *main, char *map);
void			set_location(t_struct_m *main);
void			spritesnumb(t_struct_m *main);
void			get_spritenumber(t_struct_m *main, int y, int x);
int				check_fill(t_struct_m *main);
void			flood_fill(int x, int y, t_struct_m *main);
int				if_empty(int x, int y, t_struct_m *main);
int				ft_check_empty(int x, int y, t_struct_m *main);
int				ft_atoi_cube(char *str, t_struct_m *main, int i);
int				ft_isalnummer(int i, char *str);
int				ft_strlenght(char *s);
int				ft_strleng(char *str, int i);
char			*ft_cp_string(char *str, int i, int lenght);
void			ft_putchar(char *str);
void			ft_putstr(char *str);
void			space_cubemap(t_struct_m *main);

int				render_next_frame(t_struct_m *main);
int				ft_raycasting(t_struct_m *main);
int				ft_floor_casting(t_struct_m *main);
// int			ft_cealing_casting(t_struct_m *main);
int				wasd_2(t_struct_m *main);
int				ft_push_key(int keycode, t_struct_m *main);
int				ft_release_key(int keycode, t_struct_m *main);
int				ft_close(int keycode, t_struct_m *main);
void			verLine(int x, int drawStart, int drawEnd,
				int col, t_struct_m *main);
int				create_trgb(int r, int g, int b);

void			printmap(t_struct_m *main);
int				render_next_frame_structure(t_struct_m *main);
void			verLine_texture(int x, t_struct_m *main);
void			set_value_texture(t_struct_m *main);
void			verline_structure(t_struct_m *main);

int				render_next_frame_sprites(t_struct_m *main);
int				render_next_frame_sprites_copy(t_struct_m *main);
void			swap(t_struct_m *main, int j);
void			bubble_sort(t_struct_m *main);
void			ft_bmp(t_struct_m *main);
void			ft_end_function(t_struct_m *main);
char			*map_copy_top(t_struct_m *main, int y, int len);
int				ft_empty_space(t_struct_m *main);
int				ft_check_empty_line(t_struct_m *main);
int				ft_map_line_get_x(char *map);
#endif