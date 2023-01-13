/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:21:51 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/13 13:25:54 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/linear_algebra.h"
#include "../include/types.h"
#include <math.h>
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

int	coloring(t_my_ray ray)
{
	t_color		colr;
	t_sp		sp;
	t_pl		pln;
	t_sol		inters;
	int 		clr;

	sp = (t_sp){
		.n = (t_vec){.x = 0, .y = 0, .z = 0, .w = 1},
		.c = (t_vec){.x = 2, .y = 2, .z = 20, .w = 1},
		.d = 2,
		.rgb = 56413,
	};
	(void)pln;
	inters = sp_get_intersections(ray, sp);
	clr = 0;
	if (inters.c == 1)
	{
		colr.x = 0xFFFFFF;
		colr.y = 0xFFFFFF;
		colr.z = 0xFFFFFF;
		clr = 0xFFFFFF;
	}
	if (inters.c == 2)
	{
		colr.x = sp.rgb;
		colr.y = sp.rgb;
		colr.z = sp.rgb;
		clr = sp.rgb;
	}
	return (clr);
}

void	debug_camera(t_camera cam)
{
	print_vec(cam.cam_ori);
	print_vec(cam.cam_dir);
	printf("file_view: %.2f\n", cam.filed_of_view);
	printf("hsize %.2f\n", cam.hsize);
	printf("vsize %.2f\n", cam.vsize);
	print_matr4x4(cam.transform);
	printf("aspect %.2f\n", cam.aspect);
	printf("half_view %.2f\n", cam.half_view);
	printf("half_width %.2f\n", cam.half_width);
	printf("half_height %.2f\n", cam.half_height);
	printf("pixel_size %.2f\n", cam.pixel_size);
}
