/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:19:17 by hjabbour          #+#    #+#             */
/*   Updated: 2023/02/02 16:44:40 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/types.h"
#include "enums.h"
#include "macros.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

t_color	clamp(t_color clr)
{
	if (clr.r > 255)
		clr.r = 255;
	if (clr.r < 0)
		clr.r = 0;
	if (clr.g > 255)
		clr.g = 255;
	if (clr.g < 0)
		clr.g = 0;
	if (clr.b > 255)
		clr.b = 255;
	if (clr.b < 0)
		clr.b = 0;
	return (clr);
}

t_vec	reflect(t_vec in, t_vec normal)
{
	return (vec_sub_vec(in, vec_multi_value(normal,
				(2 * vec_dot_product_vec(in, normal)))));
}

static bool	is_shadowed(const t_scene *scn, t_vec pnt, const t_obj *jump)
{
	const float	dis = vec_length(vec_sub_vec(scn->light.pos, pnt));
	const t_vec	dir = vec_normalize(vec_sub_vec(scn->light.pos, pnt));
	const t_ray	ray = (t_ray){.o = point(pnt.x, pnt.y, pnt.z),
		.d = vector(dir.x, dir.y, dir.z)};
	t_hit		hit;
	t_obj		*obj;

	obj = NULL;
	hit = closest_object(&obj, ray, scn, jump);
	if (!obj)
		return (false);
	if (hit.dis > EPSILON && hit.dis < dis)
		return (true);
	return (false);
}

// the good one
// static t_color	the_ambient_light(const t_obj *obj, t_amb amb, t_light light)
// {
// 	t_color	clr;

// 	clr = (t_color){0};
// 	if (obj->type == SPHERE)
// 	{
// 		clr = clr_multi_value(clr_multi_clr(obj->sph.rgb, amb.la), amb.ka);
// 	}
// 	else if (obj->type == PLANE)
// 	{
// 		clr = clr_multi_value(clr_multi_clr(obj->pln.rgb, amb.la), amb.ka);
// 	}
// 	else if (obj->type == CYLINDER)
// 	{
// 		clr = clr_multi_value(clr_multi_clr(obj->cyl.rgb, amb.la), amb.ka);
// 	}
// 	return (clr);
// 	(void)light;
// }

// the good one
// t_color	light_coloring(const t_ray ray, const t_hit hit,
// 	const t_scene *scn, const t_obj *obj)
// {
// 	t_color			diffuse;
// 	const t_point	pnt = ray_position(ray, hit.dis);
// 	const t_vec		light_dir = vec_normalize(vec_sub_vec(scn->light.pos, pnt));
// 	const t_vec		normal_at = get_normal_at(obj, ray, hit, pnt);
// 	float			dif_coef;

// 	if (is_shadowed(scn, pnt, obj))
// 		return (the_ambient_light(obj, scn->amb, scn->light));
// 	dif_coef = vec_dot_product_vec(normal_at, light_dir);
// 	if (dif_coef < EPSILON)
// 		dif_coef = 0.0F;
// 	diffuse = clr_multi_value(clr_multi_value(scn->light.clr, scn->light.bri),
// 			dif_coef);
// 	return (clr_add_clr(diffuse, the_ambient_light(obj, scn->amb, scn->light)));
// }


static t_color	ambient_light(const t_obj *obj, t_amb amb, t_light light)
{
	t_color	clr;

	clr = clr_multi_value(clr_multi_clr(amb.la, light.clr), amb.ka);
	return (clr);
	(void)obj;
}

static t_color	diffuse_light(const t_obj *obj, t_amb amb, t_light light, float dif_coef)
{
	t_color	clr;

	clr = (t_color){0};
	if (obj->type == SPHERE)
	{
		clr = clr_multi_clr(obj->sph.rgb, light.clr);
	}
	else if (obj->type == PLANE)
	{
		clr = clr_multi_clr(obj->pln.rgb, light.clr);
	}
	else if (obj->type == CYLINDER)
	{
		clr = clr_multi_clr(obj->cyl.rgb, light.clr);
	}
	return (clr_multi_value(clr, dif_coef));
	(void)obj;
	(void)amb;
}

t_color	light_coloring(const t_ray ray, const t_hit hit,
	const t_scene *scn, const t_obj *obj)
{
	t_color			diffuse;
	t_color			ambient;
	const t_vec		pnt = vec_add_vec(ray.o, vec_multi_value(ray.d, hit.dis));
	const t_vec		light_dir = vec_normalize(vec_sub_vec(scn->light.pos, pnt));
	const t_vec		normal_at = get_normal_at(obj, ray, hit, pnt);
	float			dif_coef;

	ambient = ambient_light(obj, scn->amb, scn->light);
	if (is_shadowed(scn, pnt, obj))
		return (ambient);
	dif_coef = vec_dot_product_vec(normal_at, light_dir);
	if (dif_coef < EPSILON)
		diffuse = (t_color){0};
	else
		diffuse = diffuse_light(obj, scn->amb, scn->light, dif_coef);
	return (clr_add_clr(diffuse, ambient));
}
