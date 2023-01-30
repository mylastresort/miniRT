/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:39:06 by stamim            #+#    #+#             */
/*   Updated: 2023/01/30 03:31:56 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "enums.h"
#include "types.h"

void	rt_pln_closest_hit(const t_pln pln, const t_ray ray, t_hit *const hit)
{
	const float	den = vec_dot_product_vec(ray.d, pln.n);
	const t_vec	org = vec_sub_vec(ray.o, pln.p);
	const float	num = -vec_dot_product_vec(org, pln.n);

	if (den != .0F && ((den > .0F && num > .0F) || (den < .0F && num < .0F)))
	{
		hit->dis = num / den;
	}
	hit->dis = -1;
}

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

void	rt_sph_closest_hit(const t_sph sph, const t_ray ray, t_hit *const hit)
{
	const t_vec	org = vec_sub_vec(ray.o, sph.c);
	const t_qud	sol = rt_sol_qua_eq(
			vec_dot_product(ray.d),
			2 * vec_dot_product_vec(ray.d, org),
			vec_dot_product(org) - sph.sq_r);

	if (sol.count >= 1)
	{
		hit->dis = sol.sl1;
		if (sol.count > 1 && sol.sl2 > 0 && sol.sl2 < hit->dis)
		{
			hit->dis = sol.sl2;
		}
		if (hit->dis > 0)
		{
			return ;
		}
	}
	hit->dis = -1;
}

void	rt_cyl_hit_disk(const t_cyl cyl, const t_ray ray, t_hit *const hit)
{
	const t_vec	cap1 = vec_multi_value(cyl.nrm, cyl.hgt / 2);
	const t_vec	cap2 = vec_multi_value(cyl.nrm, -cyl.hgt / 2);

	hit->dis = -vec_dot_product_vec(vec_sub_vec(ray.o, vec_add_vec(cyl.cnt,
					cap1)), cyl.nrm) / vec_dot_product_vec(ray.d, cyl.nrm);
	hit->type = CYLINDER_DISK_1;
	if (vec_dot_product(vec_sub_vec(vec_add_vec(ray.o, vec_multi_value(ray.d,
						hit->dis)), vec_add_vec(cyl.cnt, cap1))) <= cyl.rd2)
		return ;
	hit->dis = -vec_dot_product_vec(vec_sub_vec(ray.o, vec_add_vec(cyl.cnt,
					cap2)), cyl.nrm) / vec_dot_product_vec(ray.d, cyl.nrm);
	hit->type = CYLINDER_DISK_2;
	if (vec_dot_product(vec_sub_vec(vec_add_vec(ray.o, vec_multi_value(ray.d,
						hit->dis)), vec_add_vec(cyl.cnt, cap2))) <= cyl.rd2)
		return ;
	hit->dis = .0F;
	hit->type = CYLINDER;
}

void	rt_cyl_closest_hit(const t_cyl cyl, const t_ray ray, t_hit *const hit)
{
	const t_vec	org = vec_sub_vec(ray.o, cyl.cnt);
	const float	dpt[2] = {vec_dot_product_vec(ray.d, cyl.nrm),
		vec_dot_product_vec(org, cyl.nrm)};
	const t_qud	sol = rt_sol_qua_eq(vec_dot_product(ray.d) - powf(dpt[0], 2),
			2 * (vec_dot_product_vec(ray.d, org) - dpt[0] * dpt[1]),
			vec_dot_product_vec(org, org) - powf(dpt[1], 2) - cyl.rd2);
	float		prmm[2];

	if (rt_cyl_hit_disk(cyl, ray, hit), sol.count >= 1)
	{
		prmm[0] = sol.sl1;
		prmm[1] = dpt[0] * sol.sl1 + dpt[1];
		if (sol.count > 1 && prmm[0] > .0F && (prmm[0] > hit->dis
				|| prmm[1] <= -cyl.hgt / 2 || prmm[1] >= cyl.hgt / 2))
		{
			prmm[0] = sol.sl2;
			prmm[1] = dpt[0] * sol.sl2 + dpt[1];
		}
		if (hit->dis > .0F && prmm[0] > .0F && prmm[0] > hit->dis)
			return ;
		if (prmm[1] <= -cyl.hgt / 2 || prmm[1] >= cyl.hgt / 2)
		{
			hit->dis = -1;
			return ;
		}
		hit->dis = prmm[0];
	}
}
