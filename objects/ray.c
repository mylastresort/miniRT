/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:45:45 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/21 14:20:50 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enums.h"
#include "types.h"
#include "declarations.h"
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

// t_ray	ray_for_pixel(t_camera cam, int x, int y)
// {
// 	t_ray		ray;
// 	const float	world_x = cam.half_width - ((x + 0.5) * cam.pixel_size);
// 	const float	world_y = cam.half_height - ((y + 0.5) * cam.pixel_size);
// 	const t_vec	pixel = matr4x4_multi_vec(invers_matr4x4(cam.transform),
// 			(t_vec){.x = world_x, .y = world_y, .z = -1, .w = 1});
// 	ray.o = matr4x4_multi_vec(invers_matr4x4(cam.transform),
// 			(t_vec){.x = 0, .y = 0, .z = 0, .w = 1});
// 	ray.d = vec_normalize(vec_sub_vec(pixel, ray.o));
// 	return (ray);
// }

// const float	p_ndc_x = (x + 0.5) / (float)width;
// const float	p_ndc_y = (y + 0.5) / (float)height;
// const float	p_screen_x = 2 * p_ndc_x - 1;
// const float	p_screen_y = 1 - 2 * p_ndc_y;

t_ray	ray_for_pixel(t_camera cam, int x, int y)
{
	const float	p_x = (2 * (((float)x + 0.5) / (float)width) - 1)
		* tan(deg_to_rad(cam.fov / 2)) * cam.aspect;
	const float	p_y = (1 - 2 * (((float)y + 0.5) / (float)height))
		* tan(deg_to_rad(cam.fov / 2));

	return ((t_ray){
		.o = (t_vec){.x = 0, .y = 0, .z = 0, .w = 1},
		.d = vec_normalize(vec_sub_vec(
				(t_vec){.x = p_x, .y = p_y, .z = -1, .w = 1},
				(t_vec){.x = 0, .y = 0, .z = 0, .w = 1})),
	});
}
