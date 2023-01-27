/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:21:00 by stamim            #+#    #+#             */
/*   Updated: 2023/01/27 14:30:41 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"

t_sol	pl_get_intersections(const t_pl pln, const t_ray ray)
{
	const float	den = pln.n.x * ray.d.x + pln.n.y * ray.d.y + pln.n.z * ray.d.z;
	const float	num = pln.n.x * ray.o.x + pln.n.y * ray.o.y + pln.n.z * ray.o.z
		+ pln.d;
	float		sol;

	if (is_equal(den, 0.0F))
	{
		return ((t_sol){.c = 0});
	}
	if (is_equal(num, 0.0F))
	{
		return ((t_sol){.c = 0});
	}
	sol = -num / den;
	if (sol < 0)
	{
		return ((t_sol){.c = 0});
	}
	return ((t_sol){.c = 1,
		.x1 = {.x = ray.o.x + ray.d.x * sol,
			.y = ray.o.y + ray.d.y * sol,
			.z = ray.o.z + ray.d.z * sol}});
}
