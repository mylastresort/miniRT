/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:39:06 by stamim            #+#    #+#             */
/*   Updated: 2023/01/29 17:17:11 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"

static t_qud	rt_sol_qua_eq(const float cf1, const float cf2, const float cf3)
{
	const float	dis = powf(cf2, 2) - 4 * cf1 * cf3;
	float		den;
	float		sqr;
	t_qud		sol;

	if (dis == .0F)
	{
		sol.count = 1;
		sol.sl1 = -cf2 / (2 * cf1);
		return (sol);
	}
	if (dis > .0F)
	{
		sol.count = 2;
		sqr = sqrtf(dis);
		den = 2 * cf1;
		sol.sl1 = (-cf2 - sqr) / den;
		sol.sl2 = (-cf2 + sqr) / den;
		return (sol);
	}
	sol.count = 0;
	return (sol);
}

t_hit	rt_pln_closest_hit(const t_pln pln, const t_ray ray)
{
	const float	den = vec_dot_product_vec(ray.d, pln.n);
	const t_vec	org = vec_sub_vec(ray.o, pln.p);
	const float	num = -vec_dot_product_vec(org, pln.n);
	t_hit		hit;

	if (den != .0F && ((den > .0F && num > .0F) || (den < .0F && num < .0F)))
	{
		hit.exist = true;
		hit.pnt = vec_add_vec(ray.o, vec_multi_value(ray.d, num / den));
		return (hit);
	}
	hit.exist = false;
	return (hit);
}

t_hit	rt_sph_closest_hit(const t_sph sph, const t_ray ray)
{
	const t_vec	org = vec_sub_vec(ray.o, sph.c);
	t_hit		hit;
	t_qud		sol;

	sol = rt_sol_qua_eq(vec_dot_product(ray.d),
			2 * vec_dot_product_vec(ray.d, org),
			vec_dot_product(org) - powf(sph.d, 2) / 4);
	if (sol.count >= 1)
	{
		if (sol.count > 1 && sol.sl2 > 0 && sol.sl2 < sol.sl1)
		{
			sol.sl1 = sol.sl2;
		}
		if (sol.sl1 > 0)
		{
			hit.exist = true;
			hit.pnt = vec_add_vec(ray.o, vec_multi_value(ray.d, sol.sl1));
			return (hit);
		}
	}
	hit.exist = false;
	return (hit);
}

t_hit	rt_cyl_closest_hit(const t_cyl cyl, const t_ray ray)
{
	const t_vec	o = vec_sub_vec(ray.o, cyl.c);
	float		v[4];
	t_qud		sol;

	v[0] = vec_dot_product_vec(ray.d, cyl.n);
	v[1] = vec_dot_product_vec(o, cyl.n);
	sol = rt_sol_qua_eq(vec_dot_product(ray.d) - powf(v[0], 2),
			2 * (vec_dot_product_vec(ray.d, o) - v[0] * v[1]),
			vec_dot_product_vec(o, o) - powf(v[1], 2) - powf(cyl.d, 2) / 4);
	if (sol.count >= 1)
	{
		v[2] = v[0] * sol.sl1 + v[1];
		v[3] = v[0] * sol.sl2 + v[1];
		if (sol.sl1 < .0F || v[2] <= -cyl.h / 2 || v[2] >= cyl.h / 2)
		{
			v[2] = v[3];
			sol.sl1 = sol.sl2;
		}
		if (sol.sl1 > .0F && v[2] >= -cyl.h / 2 && v[2] <= cyl.h / 2)
		{
			return ((t_hit){.exist = true, .sol = sol.sl1,
				.pnt = vec_add_vec(ray.o, vec_multi_value(ray.d, sol.sl1))});
		}
	}
	return ((t_hit){.exist = false});
}
