/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:48:09 by stamim            #+#    #+#             */
/*   Updated: 2023/01/16 10:40:25 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/types.h"
#include "../include/declarations.h"
#include <sys/time.h>

void	sp_translate(t_sp *const sp, const t_vec fac)
{
	sp->c.x += fac.x;
	sp->c.y += fac.y;
	sp->c.z += fac.z;
}

t_sol	sp_get_intersections(const t_ray r, const t_sp sp)
{
	const float	a = powf(r.d.x, 2) + powf(r.d.y, 2) + powf(r.d.z, 2);
	const float	b = -2 * (r.d.x * (r.o.x + sp.c.x) + r.d.y * (r.o.y + sp.c.y)
			+ r.d.z * (r.o.z + sp.c.z));
	const float	c = 2 * (r.o.x * sp.c.x + r.o.y * sp.c.y + r.o.z * sp.c.z)
		+ powf(r.o.x, 2) + powf(sp.c.x, 2) + powf(r.o.y, 2) + powf(sp.c.y, 2)
		+ powf(r.o.z, 2) + powf(sp.c.z, 2) - powf(sp.d, 2) / 4;
	const float	d = powf(b, 2) - (4 * a * c);
	float		s[2];

	if (d == 0)
	{
		s[0] = -b / (2 * a);
		return ((t_sol){.c = 1, .x1 = {.x = r.o.x + r.d.x * s[0], .y = r.o.y
				+ r.d.y * s[0], .z = r.o.z + r.d.z * s[0]}});
	}
	if (d > 0)
	{
		s[0] = (-b - sqrtf(d)) / (2 * a);
		s[1] = (-b + sqrtf(d)) / (2 * a);
		return ((t_sol){.c = 2, .x1 = {.x = r.o.x + r.d.x * s[0], .y = r.o.y
				+ r.d.y * s[0], .z = r.o.z + r.d.z * s[0]}, .x2 = {.x = r.o.x
				+ r.d.x * s[1], .y = r.o.y + r.d.y * s[1], .z = r.o.z + r.d.z
				* s[1]}});
	}
	return ((t_sol){.c = 0});
}
