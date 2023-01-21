/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:21:51 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/21 17:29:35 by hjabbour         ###   ########.fr       */
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

t_vec	reflect(t_vec in, t_vec normal)
{
	return (vec_sub_vec(in, vec_multi_value(normal,
				(2 * vec_dot_product_vec(in, normal)))));
}

void	generate_camera(t_scene *scn)
{
	scn->cam.aspect = (float)width / (float)height;
	scn->cam.transform = matr4x4_translation(scn->cam.cam_ori.x,
			scn->cam.cam_ori.y, scn->cam.cam_ori.z);
	scn->cam.half_view = tanf(scn->cam.fov / 2);
	scn->cam.half_width = half_width(scn->cam.aspect, scn->cam.half_view);
	scn->cam.half_height = half_height(scn->cam.aspect, scn->cam.half_view);
	scn->cam.pixel_size = (scn->cam.half_width * 2) / (float)height;
}

// loop around all objects and get the closest intersection with positive value
t_color	objects_coloring(const t_ray ray, const t_scene *scn)
{
	t_sol		inters;
	t_color		clr;

	inters = sp_get_intersections(ray, scn->objs->sph);
	clr = (t_color){0};
	if (inters.c > 0)
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