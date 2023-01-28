/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:48:09 by stamim            #+#    #+#             */
/*   Updated: 2023/01/28 13:31:26 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"
#include <math.h>

t_sol	sp_get_intersections(const t_ray r, const t_sp sp)
{
	const t_vec	x = vec_sub_vec(r.o, sp.c);
	const float	cft[3] = {vec_dot_product(r.d),
		2 * vec_dot_product_vec(r.d, x),
		vec_dot_product(x) - powf(sp.d, 2) / 4};
	const float	dis = powf(cft[1], 2) - 4 * cft[0] * cft[2];
	float		s[2];

	if (dis == 0)
	{
		s[0] = -cft[1] / (2 * cft[0]);
		return ((t_sol){.c = 1,
			.x1 = vec_add_vec(r.o, vec_multi_value(r.d, s[0]))});
	}
	if (dis > 0)
	{
		s[0] = (-cft[1] - sqrtf(dis)) / (2 * cft[0]);
		s[1] = (-cft[1] + sqrtf(dis)) / (2 * cft[0]);
		return ((t_sol){.c = 1,
			.x1 = vec_add_vec(r.o, vec_multi_value(r.d, s[0])),
			.x2 = vec_add_vec(r.o, vec_multi_value(r.d, s[1]))});
	}
	return ((t_sol){.c = 0});
}

t_vec	normal_at_sphere(t_point obj_ori, t_point pnt)
{
	return (vec_normalize(vec_sub_vec(pnt, obj_ori)));
}
