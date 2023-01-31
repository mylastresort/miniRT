/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:38:25 by stamim            #+#    #+#             */
/*   Updated: 2023/01/30 15:52:47 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "enums.h"
#include "types.h"
#include <stdint.h>

t_vec	rt_sph_get_normal_at(const t_sph sph, const t_vec pnt)
{
	return (vec_normalize(vec_sub_vec(pnt, sph.c)));
}

t_vec	rt_pln_get_normal_at(const t_pln pln, const t_vec dir)
{
	if (vec_dot_product_vec(dir, pln.n) < .0F)
	{
		return (vec_multi_value(pln.n, -1));
	}
	return (pln.n);
}

t_vec	rt_cyl_normal_at(
	const t_cyl cyl,
	const float dis,
	const t_ray ray,
	const uint8_t type)
{
	t_vec	org;

	if (type != CYLINDER)
	{
		if (vec_dot_product_vec(ray.d, cyl.nrm) > .0F)
		{
			return (vec_multi_value(cyl.nrm, -1));
		}
		return (cyl.nrm);
	}
	org = vec_sub_vec(ray.o, cyl.cnt);
	return (vec_normalize(
			vec_sub_vec(vec_add_vec(vec_multi_value(ray.d, dis), org),
				vec_multi_value(cyl.nrm,
					vec_dot_product_vec(ray.d, cyl.nrm) * dis
					+ vec_dot_product_vec(org, cyl.nrm)))));
}
