/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:36:50 by rgaia             #+#    #+#             */
/*   Updated: 2019/02/28 16:53:32 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

#include "../minilibx_macos/mlx.h"
#include "../minilibx_macos/mlx_int.h" //you might not need this here

# define TRUE 1
# define FALSE 0
# define MAX_X 255 // we're using unsigned chars for now to learn how to 
# define MAX_Y 255 // best fill in those data values 
# define MAX_Z 255 // (X,Y) is always positive? Z allows negative

# define ORIGIN_X 0
# define ORIGIN_Y 0
# define ORIGIN_Z 0
# define MAX(x,y) (x > y ? x : y)
# define MIN(x,y) (x > y ? y : x)

/*typedef struct		s_2dpoint
{
	unsigned char	x; //later on expand from 1 byte (char) to 2-4 bytes (int)
	unsigned char	y; //... using GLuint (still unsigned)
	int				color;
}					t_2dpoint;

typedef struct		s_3dpoint
{
	t_2dpoint		point2;
	unsigned char	z; //Z will need GLint, as it allows (plus/negative) direxns
}					t_3dpoint;*/

typedef struct		s_point //a point is really just a pixel for us. Call it pixel?
{
	int				color;
	unsigned char	x;
	unsigned char	y;
	unsigned char	z;
}					t_point;


//typedef struct	s_view to hold all data about CAMERA_VIEW


/******************* [MATH] Vector and Matrix Operations: *********************/

//matrix addition



//matrix multiplication


//what are other matrix functions we could add to our library?


/******************* [MINILIBX] Graphics-related Functions: *******************/

/*
** @in:
** @err: Pixel Placed? (1/0)-(Successfully / Failed)
** 
** Obs: use WHITE as Default Color
*/
t_bool				ft_putpixel(t_point *point);
//t_bool			ft_putpixel_color(t_point *point, int color);


/*
** Connects two (X, Y, Z) Coordinates together
** @err: (1/0)-(Success/Failed)
**
** Obs: use WHITE as Default Color
*/
t_bool				ft_putline(t_point *p1, t_point *p2);
//t_bool			ft_putline(t_point *p1, t_point *p2);


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
