/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:38:25 by stamim            #+#    #+#             */
/*   Updated: 2023/01/29 17:16:00 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"

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

t_vec	rt_cyl_get_normal_at(const t_cyl cyl, const t_ray ray, const float t)
{
	const t_vec	o = vec_sub_vec(ray.o, cyl.c);
	const float	m
		= vec_dot_product_vec(ray.d, cyl.n) * t + vec_dot_product_vec(o, cyl.n);

	return (vec_normalize(vec_sub_vec(vec_add_vec(vec_multi_value(ray.d, t), o),
				vec_multi_value(cyl.n, m))));
}
