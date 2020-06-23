/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_value.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 13:26:52 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/23 17:01:52 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void		set_value(t_struct_m *main)
{
//for raycasting

// moves bonus

	main->place.crouch = 0;

//cube
	main->place.x = 100;//position
	main->place.y = 100;//position
	main->place.w = 100;//width
	main->place.h = 100;//height
	main->place.col = 0xFFFF0000;

//map
	main->place.s_width = -1;
	main->place.s_height = -1;
	main->place.dir = -1; // if -1, give error
	main->place.Fcol1 = -1;
	main->place.Fcol2 = -1;
	main->place.Fcol3 = -1;
	main->place.Ccol1 = -1;
	main->place.Ccol2 = -1;
	main->place.Ccol3 = -1;

	main->place.error = -1;
	main->place.error_c = 0;
	main->place.error_n = -1;
	main->place.check_double = 0;

//for cube
	main->place.x = 100;//position
	main->place.y = 100;//position
	main->place.w = 100;//width
	main->place.h = 100;//height
	main->place.col = 0xFFFF0000;
	main->place.s_width = 1200;
	main->place.s_height = 800;


//CHECK MAP DOUBLE
	main->Double.D_R = 0;
	main->Double.D_NO = 0;
	main->Double.D_SO = 0;
	main->Double.D_WE = 0;
	main->Double.D_EA = 0;
	main->Double.D_S = 0;
	main->Double.D_F = 0;
	main->Double.D_C = 0;

//strings
	main->place.NO = NULL;
	main->place.SO = NULL;
	main->place.EA = NULL;
	main->place.S  = NULL;
	main->place.WE = NULL;
//map checks

	main->place.mapx = 0;
	main->place.mapy = 0;
	main->place.mapp = 0;
	main->place.mapE = 0;
	main->place.mapc = -1;

	main->place.cubemap = NULL;
	main->cubecopytwo = NULL;

	main->keys.W = 0;
	main->keys.S = 0;
	main->keys.A = 0;
	main->keys.D = 0;
	main->keys.UP = 0;
	main->keys.DOW = 0;
	main->keys.LEF = 0;
	main->keys.RIG = 0;
	main->Ray.look = 0;
}