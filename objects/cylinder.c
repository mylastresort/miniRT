/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:26:31 by stamim            #+#    #+#             */
/*   Updated: 2023/01/16 13:28:25 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <math.h>
#include <stdbool.h>

typedef struct s_cy
{
	t_vec	n;
	t_vec	c;
	float	h;
	float	d;
	int		rgb;
}	t_cy;

t_sol	cy_get_intersections(const t_ray r, const t_cy cyl)
{
	const float	a = powf(r.d.x, 2) + powf(r.d.y, 2);
	const float	b = 2 * (r.d.x * r.o.x + r.d.y * r.o.y);
	const float	c = powf(r.o.x, 2) + powf(r.o.y, 2) - powf(cyl.d, 2) / 4;
	const float	d = powf(b, 2) - 4 * a * c;
	float		s[2];

	if (d == 0)
	{
		s[0] = -b / (2 * a);
		return ((t_sol){.c = 1,
			.x1 = {.x = r.o.x + r.d.x * s[0],
				.y = r.o.y + r.d.y * s[0], .z = r.o.z + r.d.z * s[0]}});
	}
	if (d > 0)
	{
		s[0] = -b + sqrtf(d) / (2 * a);
		s[1] = -b - sqrtf(d) / (2 * a);
		return ((t_sol){.c = 2,
			.x1 = {.x = r.o.x + r.d.x * s[0],
				.y = r.o.y + r.d.y * s[0],
				.z = r.o.z + r.d.z * s[0]},
			.x2 = {.x = r.o.x + r.d.x * s[1],
				.y = r.o.y + r.d.y * s[1], .z = r.o.z + r.d.z * s[1]}});
	}
	return ((t_sol){.c = 0});
}

void	cy_translate(t_cy *const cy, const t_vec fac)
{
	cy->c.x += fac.x;
	cy->c.y += fac.y;
	cy->c.z += fac.z;
}
