/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:30:18 by stamim            #+#    #+#             */
/*   Updated: 2023/01/06 14:39:34 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "enums.h"
# include "linear_algebra.h"
# include <stdint.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_keycode	t_keycode;
typedef t_vec			t_color;
typedef t_vec			t_point;
typedef t_vec			t_tuple;

typedef struct cam
{
	uint32_t	val;
}	t_cam;

typedef struct amb
{
	uint32_t	val;
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

typedef struct s_projectile
{
	// t_vec	position;
	// t_point	pnt_position;
	// t_vec	vec_velocity;
	t_tuple	pnt_position;
	t_tuple	vec_velocity;
}	t_projectile;

typedef struct s_environment
{
	// t_vec	vec_gravity;
	// t_vec	vec_wind;
	t_tuple	vec_gravity;
	t_tuple	vec_wind;
}	t_environment;

typedef struct s_ray
{
	t_vec	o;
	t_vec	d;
}	t_ray;

typedef struct s_sp
{
	t_vec	n;
	t_vec	c;
	float	d;
	int		rgb;
}	t_sp;

typedef struct s_sol
{
	int		count;
	t_vec	x1;
	t_vec	x2;
}	t_sol;

#endif