/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:21:00 by stamim            #+#    #+#             */
/*   Updated: 2023/01/23 10:20:26 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"

void	pl_get_coefficients(t_pl *const pln)
{
	pln->a = pln->n.x;
	pln->b = pln->n.y;
	pln->c = pln->n.z;
	pln->d = -(pln->p.x * pln->n.x + pln->p.y * pln->n.y + pln->p.z * pln->n.z);
}

t_sol	pl_get_intersections(const t_pl pln, const t_ray ray)
{
	const float	den = pln.n.x * ray.d.x + pln.n.y * ray.d.y + pln.n.z * ray.d.z;
	float		num;
	float		sol;

	if (is_equal(den, 0.0F))
	{
		return ((t_sol){.c = 0});
	}
	num = pln.a * ray.o.x + pln.b * ray.o.y + pln.c * ray.o.z + pln.d;
	if (is_equal(num, 0.0F))
	{
		return ((t_sol){.c = 0});
	}
	sol = -num / den;
	return ((t_sol){.c = 1,
		.x1 = {.x = ray.o.x + ray.d.x * sol,
			.y = ray.o.y + ray.d.y * sol,
			.z = ray.o.z + ray.d.z * sol}});
}