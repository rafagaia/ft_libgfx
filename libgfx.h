/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:36:50 by rgaia             #+#    #+#             */
/*   Updated: 2019/03/06 23:23:35 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

#include "../minilibx_macos/mlx.h"
#include "../ft_libft/libft.h"
#include <math.h>
#include <time.h> //FOR USING TIME AS SEED TO RANDOM NUMBERS
#include <fcntl.h> //WHAT'S THIS LIBRARY FOR?

# define TRUE 1
# define FALSE 0
# define MAX_X 255 // we're using chars for now to learn how to 
# define MAX_Y 255 // best fill in those data values 
# define MAX_Z 255 // (X,Y) is always positive? Z allows negative

# define ORIGIN_X 0
# define ORIGIN_Y 0
# define ORIGIN_Z 0
# define MAX(x,y) (x > y ? x : y)
# define MIN(x,y) (x > y ? y : x)

typedef struct			s_mlx
{
	void				*init;
	void				*window;
	void				*image;
}						t_mlx;

typedef struct			s_image
{
	char				*data;
	int					size; //24?
	int					bpp; //filled with # of bits for color precision (24bit)
	int					endian; //how pixel color in s_image needs to be stored
}						t_image;

typedef struct			s_map
{
	t_list				**field; //list_add as we read_in each new_line
	int					f_x_height; //positive down
	int					f_y_width; //positive right
	int					x_coordinate; //increases downward towards EOF
	int					y_coordinate; //increases right towards End of LINE
	int					x0;
	int					x1;
	int					y0;
	int					y1;
	int					zoom;
	int					isometric;
	double				x_angle;
	double				y_angle;
	double				z_depth; //-z: Normal backwards to screen. +z: front
}						t_map;

/* PIXEL - RELATED STRUCTS: t_color, t_2dvec, t_pixel */
typedef struct			s_color
{
	char				RED;
	char				GREEN;
	char				BLUE;
}						t_color;

typedef struct			s_2dvec
{
	int					x;
	int					y;
}						t_2dvec;

typedef struct			s_pixel
{
	int					z; //Depth
	t_2dvec				vec; //(Height, Width)
	t_color				color;
}						t_pixel; //( +Height, +Width, -+Depth )



/******************* [MATH] Vector and Matrix Operations: *********************/

//matrix addition



//matrix multiplication


//what are other matrix functions we could add to our library?


/******************* [MINILIBX] Graphics-related Functions: *******************/

/*
** @in:
** @err: Pixel Placed? (1/0)-(Successfully / Failed)
*/
t_bool				ft_putpixel(t_pixel *p1);

/*
** Connects two (X, Y, Z) Coordinates together
** @err: (1/0)-(Success/Failed)
*/
t_bool				ft_putline(t_pixel *p1, t_pixel *p2);

/*
** This function handles when client presses 'ESC' Key
** State Change: here we flip a bit and a While Loop is (break)ed
** FDF Returns (0) -> (Successful Status - ProgramReturnsAsExpected)
** Should be an EventListener that checks that bit/address every once a while -
** (milisecond magnitude)
** NOT an Interrupt - for now

** THERE'S MINILIBX STUFF FOR THIS:
** CHECK MLX.h
** mlx_key_hook
** mlx_expose_hook
** mlx_loop_hook -> this is where you'll set how often to loop and how long
** mlx_loop
*/
int					ft_handlekey(t_UEFI *board_state);





#endif /* LIBGFX_H */
