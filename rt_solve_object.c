/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:39:06 by stamim            #+#    #+#             */
/*   Updated: 2023/02/01 18:43:52 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"
#include <math.h>

void	rt_pln_closest_hit(const t_pln pln, const t_ray ray, t_hit *const hit)
{
	const float	den = vec_dot_product_vec(ray.d, pln.n);
	const t_vec	org = vec_sub_vec(ray.o, pln.p);

	if (den != .0F)
	{
		hit->dis = -vec_dot_product_vec(org, pln.n) / den;
		return ;
	}
	hit->dis = -1;
}

t_qud	rt_sol_qua_eq(const float cf1, const float cf2, const float cf3)
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

void	rt_sph_closest_hit(const t_sph sph, const t_ray ray, t_hit *const hit)
{
	const t_vec	org = vec_sub_vec(ray.o, sph.c);
	const t_qud	sol = rt_sol_qua_eq(vec_dot_product(ray.d),
			2 * vec_dot_product_vec(ray.d, org),
			vec_dot_product(org) - sph.sq_r);

	if (sol.count >= 1)
	{
		hit->dis = sol.sl1;
		if (sol.count > 1 && sol.sl2 > 0 && sol.sl2 < hit->dis)
		{
			hit->dis = sol.sl2;
		}
		return ;
	}
	hit->dis = -1;
}

void	rt_cyl_closest_hit(const t_cyl cyl, const t_ray ray, t_hit *const hit)
{
	const t_vec	org = vec_sub_vec(ray.o, cyl.cnt);
	const float	dpa = vec_dot_product_vec(ray.d, cyl.nrm);
	const float	dpb = vec_dot_product_vec(org, cyl.nrm);
	const t_qud	sol
		= rt_sol_qua_eq(vec_dot_product(ray.d) - powf(dpa, 2),
			2 * (vec_dot_product_vec(ray.d, org) - dpa * dpb),
			vec_dot_product(org) - powf(dpb, 2) - cyl.rd2);
	float		prm;

	hit->dis = MAXFLOAT;
	if (sol.count == 2 && sol.sl2 > .0F)
	{
		prm = dpa * sol.sl2 + dpb;
		if (prm >= -cyl.hgt / 2 && prm <= cyl.hgt / 2)
			*hit = (t_hit){.dis = sol.sl2, .prm = prm};
	}
	if (sol.count >= 1 && sol.sl1 > .0F && sol.sl1 < hit->dis)
	{
		prm = dpa * sol.sl1 + dpb;
		if (prm >= -cyl.hgt / 2 && prm <= cyl.hgt / 2)
			*hit = (t_hit){.dis = sol.sl1, .prm = prm};
	}
	if (hit->dis == MAXFLOAT)
		hit->dis = -1;
}
