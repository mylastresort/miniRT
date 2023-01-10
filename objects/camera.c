/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:21:51 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/10 19:59:25 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/linear_algebra.h"
#include "../include/types.h"
#include <stdint.h>

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

t_my_ray	ray_for_pixel(t_camera cam, uint32_t x, uint32_t y)
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

t_color	coloring(t_my_ray ray)
{
	t_color	colr;
	t_sphe

	colr.x = ;
	colr.y = ;
	colr.z = ;
	return (colr);
	// return ((t_color){
	// 	.x = ,
	// 	.y = ,
	// 	.z = ,
	// 	.w = ,
	// });
}
