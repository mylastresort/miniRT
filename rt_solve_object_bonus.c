/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:56:17 by stamim            #+#    #+#             */
/*   Updated: 2023/02/01 18:28:02 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"

void	rt_con_closest_hit(const t_con con, const t_ray ray, t_hit *const hit)
{
	const t_vec	org = vec_sub_vec(ray.o, con.cnt);
	const float	dpa = vec_dot_product_vec(ray.d, con.nrm);
	const float	dpb = vec_dot_product_vec(org, con.nrm);
	const t_qud	sol = rt_sol_qua_eq(
			vec_dot_product(ray.d) - con.fac * powf(dpa, 2),
			2 * (vec_dot_product_vec(ray.d, org) - con.fac * dpa * dpb),
			vec_dot_product(org) - con.fac * powf(dpb, 2));
	float		prm;

	hit->dis = MAXFLOAT;
	if (sol.count == 2 && sol.sl2 > .0F)
	{
		prm = dpa * sol.sl2 + dpb;
		if (prm <= .0F && prm >= -con.hgt)
		{
			hit->dis = sol.sl2;
			hit->prm = prm;
		}
	}
	if (sol.count >= 1 && sol.sl1 > .0F && sol.sl1 < hit->dis)
	{
		prm = dpa * sol.sl1 + dpb;
		if (prm <= .0F && prm >= -con.hgt)
		{
			hit->prm = prm;
			hit->dis = sol.sl1;
		}
	}
	if (hit->dis == MAXFLOAT)
		hit->dis = -1;
}
