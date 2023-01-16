/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:30:18 by stamim            #+#    #+#             */
/*   Updated: 2023/01/16 11:10:54 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "enums.h"
# include <fcntl.h>
// # include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_vec {
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec;

typedef enum e_keycode		t_keycode;
typedef t_vec				t_color;
typedef t_vec				t_point;
typedef t_vec				t_tuple;
typedef float				t_rad;
typedef float				t_deg;
typedef uint32_t			t_buf[height][width];

typedef struct s_matrix_2x2 {
	float	m[2][2];
}	t_matrix_2x2;

typedef struct s_matrix_3x3 {
	float	m[3][3];
}	t_matrix_3x3;

typedef struct s_matrix_4x4 {
	float	m[4][4];
}	t_matrix_4x4;

typedef struct cam
{
	uint32_t	val;
}	t_cam;

typedef struct amb
{
	uint32_t	la;
	float		ka;
}	t_amb;

// NOLINTNEXTLINE
typedef struct scene
{
	t_cam	*cam;
	t_amb	*amb;
	void	*img;
	void	*win;
	void	*mlx;
}	t_scene;

typedef struct s_ray
{
	t_vec	o;
	t_vec	d;
}	t_ray;
typedef struct s_sp
{
	t_vec		n;
	t_vec		c;
	float		d;
	int			rgb;
}	t_sp;

typedef struct s_pl
{
	t_vec	n;
	t_vec	p;
	float	a;
	float	b;
	float	c;
	float	d;
	int		rgb;
}	t_pl;

typedef struct s_sol
{
	int		c;
	t_vec	x1;
	t_vec	x2;
	int		t_val[2];
	int		clr;
	t_color	rgb_clr;
}	t_sol;

typedef struct s_camera
{
	float			hsize;
	float			vsize;
	float			filed_of_view;
	float			aspect;
	float			pixel_size;
	float			half_view;
	float			half_width;
	float			half_height;
	t_matrix_4x4	transform;
	t_point			cam_ori;
	t_vec			cam_dir;
}	t_camera;

typedef struct s_light
{
	t_color	clr;
	float	brigth;
	t_point	position;
}	t_light;

typedef struct s_material
{
	t_color	clr;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

#endif