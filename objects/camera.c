/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:21:51 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/28 19:04:03 by stamim           ###   ########.fr       */
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

t_matrix_4x4	view_transform(t_vec forward, t_point from, t_vec up)
{
	t_matrix_4x4	mat;
	t_vec			left;
	t_vec			true_up;

	up = vec_normalize(up);
	forward = vec_normalize(forward);
	left = vec_cross_product(forward, up);
	true_up = vec_cross_product(left, forward);
	mat = (t_matrix_4x4){.m = {
	{left.x, left.y, left.z, 0},
	{true_up.x, true_up.y, true_up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1},
	}};
	return (matr4x4_multi_matr4x4(mat,
			matr4x4_translation(-from.x, -from.y, -from.z)));
}

static void	up_left_forward(t_vec forward, t_vec up, t_camera *cam)
{
	up = vec_normalize(up);
	cam->forward = vec_normalize(forward);
	cam->left = vec_cross_product(forward, up);
	cam->up = vec_cross_product(cam->left, forward);
}

void	generate_camera(t_scene *scn)
{
	scn->cam.aspect = (float)width / (float)height;
	scn->cam.half_view = tanf(deg_to_rad(scn->cam.fov) / 2);
	scn->cam.half_width = half_width(scn->cam.aspect, scn->cam.half_view);
	scn->cam.half_height = half_height(scn->cam.aspect, scn->cam.half_view);
	scn->cam.pixel_size = (scn->cam.half_width * 2) / (float)width;
	scn->cam.transform = matr4x4_identity();
	up_left_forward(scn->cam.cam_dir, vector(0, 1, 0), &scn->cam);
}

t_color	objects_coloring(const t_ray ray, const t_scene *scn)
{
	t_hit		inters;
	t_color		clr;

	inters = rt_cyl_closest_hit(scn->objs->cyl, ray);
	clr = (t_color){0};
	if (inters.exist)
	{
		clr = light_coloring(ray, inters, scn);
		clr = clamp(clr);
		return (clr);
	}
	return (clr);
}
	// if (inters.c == 1 && inters.t_val[0] >= 0 && inters.t_val[0] < touch)
	// {
	// 	res = inters;
	// 	res.clr = generate_color(vec_multi_value(inters.rgb_clr, amb.ka));
	// }
	// if (inters.c == 2)
	// {
	// 	if (inters.t_val[0] >= 0 && inters.t_val[0] < touch)
	// 	{
	// 		res = inters;
	// 		res.clr = generate_color(vec_multi_value(inters.rgb_clr, amb.ka));
	// 	}
	// 	else if (inters.t_val[1] >= 0 && inters.t_val[1] < touch)
	// 	{
	// 		res = inters;
	// 		res.clr = generate_color(vec_multi_value(inters.rgb_clr, amb.ka));
	// 	}
	// }

// t_vec	up_vec(t_vec forw)
// {
// 	t_vec	left;
// 	t_vec	up;
// 	float	dot;

// 	// up = (t_vec){0, 1, 0, 0};
// 	up = (t_vec){0, 1, 0, 0};
// 	if (is_equal_vec(forw, up))
// 	{
// 		up = (t_vec){0, 0, 1, 0};
// 	}
// 	// dot = vec_dot_product_vec(forw, up);
// 	dot = vec_dot_product_vec(up, forw);
// 	if (dot != 1)
// 	{
// 		left = vec_cross_product(forw, up);
// 		// left = vec_cross_product(up, forw);
// 		up = vec_cross_product(left, forw);
// 		// up = vec_cross_product(left, forw);
// 	}
// 	return (vec_normalize(up));
// }

// t_vec	reflect(t_vec in, t_vec normal)
// {
// 	return (vec_sub_vec(in, vec_multi_value(normal,
// 				(2 * vec_dot_product_vec(in, normal)))));
// }