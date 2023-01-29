/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:39:06 by stamim            #+#    #+#             */
/*   Updated: 2023/01/29 20:26:39 by stamim           ###   ########.fr       */
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
		hit.dis = num / den;
		return (hit);
	}
	hit.dis = -1;
	return (hit);
}

t_hit	rt_sph_closest_hit(const t_sph sph, const t_ray ray)
{
	const t_vec	org = vec_sub_vec(ray.o, sph.c);
	const t_qud	sol = rt_sol_qua_eq(vec_dot_product(ray.d),
			2 * vec_dot_product_vec(ray.d, org),
			vec_dot_product(org) - sph.sqrt_radius);
	t_hit		hit;

	if (sol.count >= 1)
	{
		hit.dis = sol.sl1;
		if (sol.count > 1 && sol.sl2 > 0 && sol.sl2 < hit.dis)
		{
			hit.dis = sol.sl2;
		}
		if (hit.dis > 0)
		{
			return (hit);
		}
	}
	hit.dis = -1;
	return (hit);
}

static t_hit	rt_cyl_closest_hit_disk(void)
{
	t_hit	hit;

	hit.dis = -1;
	hit.type = 0;
	return (hit);
}

t_hit	rt_cyl_closest_hit(const t_cyl cyl, const t_ray ray)
{
	const t_vec	org = vec_sub_vec(ray.o, cyl.c);
	const float	dp[2] = {vec_dot_product_vec(ray.d, cyl.n),
		vec_dot_product_vec(org, cyl.n)};
	const t_qud	sol = rt_sol_qua_eq(vec_dot_product(ray.d) - powf(dp[0], 2),
			2 * (vec_dot_product_vec(ray.d, org) - dp[0] * dp[1]),
			vec_dot_product_vec(org, org) - powf(dp[1], 2) - cyl.sqrt_radius);
	float		*hgt;
	t_hit		hit;

	if (sol.count >= 1)
	{
		hit = rt_cyl_closest_hit_disk();
		if (hit.type != 0)
			return (hit);
		hit.dis = sol.sl1;
		hgt = (float [2]){dp[0] * sol.sl1 + dp[1], dp[0] * sol.sl2 + dp[1]};
		if (hit.dis < .0F || hgt[0] <= -cyl.h / 2 || hgt[0] >= cyl.h / 2)
		{
			hgt[0] = hgt[1];
			hit.dis = sol.sl2;
		}
		if (hit.dis > .0F && hgt[0] >= -cyl.h / 2 && hgt[0] <= cyl.h / 2)
			return (hit);
	}
	return ((t_hit){.dis = -1});
}
