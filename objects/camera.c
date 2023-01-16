/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:21:51 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/16 11:10:54 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/types.h"
#include "enums.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

float	half_width(const float aspect, const float half_view)
{
	if (aspect >= 1)
	{
		return (half_view);
	}
	return (half_view * aspect);
}

float	half_height(const float aspect, const float half_view)
{
	if (aspect >= 1)
	{
		return (half_view / aspect);
	}
	return (half_view);
}

t_vec	normal_at(t_point obj_ori, t_point pnt)
{
	return (vec_normalize(vec_sub_vec(pnt, obj_ori)));
}

t_vec	reflect(t_vec in, t_vec normal)
{
	return (vec_sub_vec(in, vec_multi_value(normal,
				(2 * vec_dot_product_vec(in, normal)))));
}

/*
int	coloring(t_my_ray ray)
{
	t_color		colr;
	t_sp		sp = (t_sp){
		.n = (t_vec){.x = 0, .y = 0, .z = 0, .w = 1},
		.c = (t_vec){.x = 0, .y = 0, .z = 30, .w = 1},
		.d = 25,
		.rgb = BLU,
	};
	t_pl		pln;
	t_sol		inters;
	t_material	mat = (t_material){
		.clr = (t_color){1, 1, 1, 0},
		.ambient = 0.1,
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200.0,
	};
	t_color		result;
	t_light		light = (t_light){
		.intensity = (t_color){190,190,190,0},
		.position = (t_point){-15,25,-15,0},
	};
	t_point		pnt;
	t_vec		eye = (t_vec){0,0,-1,0};
	t_vec		normal;
	uint32_t	clr;
	(void)pln;
	(void)colr;
	inters = sp_get_intersections(ray, sp);
	clr = 0;
	if (inters.c == 1)
	{
		clr = sp.rgb;
	}
	if (inters.c == 2)
	{
		pnt = ray_position(ray, inters.t_val[0]);
		normal = normal_at(sp.c, pnt);
		eye = (t_vec){.x = -ray.direction.x, .y = -ray.direction.y,
		.z = -ray.direction.z, .w = 0};
		result = lighting(mat, light, pnt, eye, normal);
		clr = generate_color(result);
	}
	if (clr > 255 && clr == BLU)
		clr = 255;
	return (clr);
}
*/

// loop around all objects and get the closest intersection with positive value
t_sol	objects_coloring(const t_ray ray)
{
	t_sol		inters;
	t_sol		res;
	int			clr_t[2];
	const t_amb	amb = (t_amb){.la = 0, .ka = 0.2F};
	const t_sp	sph = (t_sp){
		.n = (t_vec){.x = 0, .y = 0, .z = 0, .w = 1},
		.c = (t_vec){.x = 0, .y = 0, .z = 30, .w = 1}, .d = 25, .rgb = BLU,
	};

	clr_t[0] = 0;
	clr_t[1] = 2e8;
	inters = sp_get_intersections(ray, sph);
	if (inters.c == 1 && inters.t_val[0] >= 0 && inters.t_val[0] < clr_t[1])
		clr_t[0] = generate_color(vec_multi_value(inters.rgb_clr, amb.ka));
	if (inters.c == 2)
	{
		if (inters.t_val[0] >= 0 && inters.t_val[0] < clr_t[1])
			clr_t[0] = generate_color(vec_multi_value(inters.rgb_clr, amb.ka));
		else if (inters.t_val[1] >= 0 && inters.t_val[1] < clr_t[1])
			clr_t[0] = generate_color(vec_multi_value(inters.rgb_clr, amb.ka));
	}
	res = inters;
	return (res);
}
