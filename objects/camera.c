/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:21:51 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/18 15:16:12 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/types.h"
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

t_vec	normal_at_sphere(t_point obj_ori, t_point pnt)
{
	return (vec_normalize(vec_sub_vec(pnt, obj_ori)));
}

t_vec	reflect(t_vec in, t_vec normal)
{
	return (vec_sub_vec(in, vec_multi_value(normal,
				(2 * vec_dot_product_vec(in, normal)))));
}

// loop around all objects and get the closest intersection with positive value
t_color	objects_coloring(const t_ray ray)
{
	t_sol		inters;
	t_color		clr;
	const t_sp	sph = (t_sp){
		.n = (t_vec){.x = 0, .y = 0, .z = 0, .w = 1},
		.c = (t_vec){.x = 0, .y = 0, .z = 10, .w = 1},
		.d = 8,
		.rgb = (t_color){.r = 1, .g = 0, .b = 1},
		.dif_fac = 0.9F,
		.spec_fac = 0.9F
	};

	inters = sp_get_intersections(ray, sph);
	clr = (t_color){0};
	if (inters.c > 0)
	{
		clr = light_coloring(ray, inters, sph);
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