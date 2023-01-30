/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:19:17 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/30 00:02:46 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/types.h"
#include "enums.h"
#include <math.h>
#include <stdint.h>

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

t_color	light_coloring(const t_ray ray, const t_hit hit, const t_scene *scn)
{
	t_color		final_ambient;
	t_color		dif_clr;
	float		dif_coef;
	const t_vec	pnt = vec_add_vec(ray.o, vec_multi_value(ray.d, hit.dis));
	const t_vec	light_dir = vec_normalize(vec_sub_vec(scn->light.pos, pnt));

	final_ambient = clr_multi_value(scn->objs->cyl.rgb, scn->amb.ka);
	dif_coef = vec_dot_product_vec(rt_cyl_normal_at(
				scn->objs->cyl,
				hit.dis,
				ray,
				hit.type), light_dir);
	if (dif_coef < 0.0F)
		dif_coef = 0;
	dif_clr = clr_multi_value(
			clr_multi_value(scn->light.clr, scn->light.bri), dif_coef);
	return (clr_add_clr(dif_clr, final_ambient));
	(void)ray;
}
