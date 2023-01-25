/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:45:45 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/25 16:42:05 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enums.h"
#include "types.h"
#include "declarations.h"
#include <i386/types.h>
#include <math.h>
#include <stdio.h>

t_point	ray_position(t_ray ray, float t)
{
	return (vec_add_vec(ray.o, vec_multi_value(ray.d, t)));
}

void	debug_ray(t_ray ray)
{
	print_vec(ray.o);
	print_vec(ray.d);
}

static float	offset(float idx, float pixel_size)
{
	return ((idx + 0.5f) * pixel_size);
}

// t_ray	ray_for_pixel(t_camera cam, int y, int x)
// {
// 	float	world_x;
// 	float	world_y;
// 	t_point	pixel;
// 	t_point	origin;
// 	t_vec	direction;

// 	world_x = cam.half_height - offset((float)x, cam.pixel_size);
// 	world_y = cam.half_width - offset((float)y, cam.pixel_size);
// 	pixel = matr4x4_multi_point(
// 			invers_matr4x4(cam.transform), point(world_y, world_x, -1));
// 	origin = cam.cam_ori;
// 	direction = vec_normalize(vec_sub_vec(pixel, origin));
// 	return ((t_ray){
// 		.o = point(origin.x, origin.y, origin.z),
// 		.d = vector(direction.x, direction.y, direction.z)
// 	});
// }

t_ray	ray_for_pixel(t_camera cam, int y, int x)
{
	float	world_x;
	float	world_y;
	t_point	origin;
	t_vec	direction;

	// world_x = cam.half_height - offset((float)x, cam.pixel_size);
	// world_y = cam.half_width - offset((float)y, cam.pixel_size);
	world_x = cam.half_width - offset((float)x, cam.pixel_size);
	world_y = cam.half_height - offset((float)y, cam.pixel_size);
	origin = cam.cam_ori;
	direction = vec_add_vec(cam.forward,
			vec_add_vec(vec_multi_value(cam.left, world_x),
				vec_multi_value(cam.up, world_y)));
	direction = vec_normalize(direction);
	return ((t_ray){
		.o = point(origin.x, origin.y, origin.z),
		.d = vector(direction.x, direction.y, direction.z)
	});
}
