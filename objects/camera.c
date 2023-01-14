/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:21:51 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/14 21:26:23 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/linear_algebra.h"
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

// t_my_ray	ray_for_pixel(t_camera cam, uint32_t x, uint32_t y)
t_my_ray	ray_for_pixel(t_camera cam, int x, int y)
{
	t_my_ray	ray;

	ray.x_offset = (x + 0.5) * cam.pixel_size;
	ray.y_offset = (y + 0.5) * cam.pixel_size;
	ray.world_x = cam.half_width - ray.x_offset;
	ray.world_y = cam.half_height - ray.y_offset;
	ray.pixel = matr4x4_multi_vec(invers_matr4x4(cam.transform),
			(t_vec){.x = ray.world_x, .y = ray.world_y, .z = -1, .w = 1});
	ray.origin = matr4x4_multi_vec(invers_matr4x4(cam.transform),
			(t_vec){.x = 0, .y = 0, .z = 0, .w = 1});
	ray.direction = vec_normalize(vec_sub_vec(ray.pixel, ray.origin));
	return (ray);
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

// int	coloring(t_my_ray ray)
int	coloring(t_my_ray ray, int n)
{
	t_color		colr;
	t_sp		sp = (t_sp){
		.n = (t_vec){.x = 0, .y = 0, .z = 0, .w = 1},
		.c = (t_vec){.x = 0, .y = 0, .z = 30, .w = 1},
		.d = 25,
		.rgb = RED,
	};
	t_pl		pln;
	t_sol		inters;
	// t_amb		amb = (t_amb){
	// 	.la = 0x00FF,
	// 	.ka = 0.2,
	// };
	;
	t_material	mat = (t_material){
		.clr = (t_color){150, 100, 255, 0},
		.ambient = 0.1,
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200.0,
	};
	t_color		result;
	t_light		light = (t_light){
		.intensity = (t_color){190,190,190,0},
		.position = (t_point){-15,25,-15,0},
		// .position = (t_point){-15,25,10,0},
	};
	t_point		pnt;
	t_vec		eye = (t_vec){0,0,-1,0};
	t_vec		normal;
	int 		clr;
	// result = lighting(mat, light, pnt, eye, normal);
	// print_vec(result);
	;
	// exit(EXIT_FAILURE);
	;
	(void)pln;
	(void)colr;
	// clr = get_color(ray, sp, amb);
	inters = sp_get_intersections(ray, sp);
	clr = 0;
	// if (inters.c == 1)
	// {
	// 	pnt = ray_position(ray, inters.t_val[0]);
	// 	clr = generate_color(result);
	// }
	if ((inters.c == 1 || inters.c == 2 ) && n == 0)
	{
		// clr = inters.rgb;
		clr = sp.rgb;
	}
	if (inters.c == 2 && n == 1)
	{
		pnt = ray_position(ray, inters.t_val[0]);
		normal = normal_at(sp.c, pnt);
		eye = (t_vec){.x = -ray.direction.x, .y = -ray.direction.y, .z = -ray.direction.z, .w = 0};
		result = lighting(mat, light, pnt, eye, normal);
		clr = generate_color(result);
		// if (clr != 0)
		// {
		// 	clr = RED;
		// 	// printf("%d\n", clr);
		// }
	}
	return (clr);
}
