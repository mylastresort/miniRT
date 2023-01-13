/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:21:00 by stamim            #+#    #+#             */
/*   Updated: 2023/01/12 15:02:07 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/types.h"

void	pl_get_coefficients(t_pl *const pl)
{
	pl->a = pl->n.x;
	pl->b = pl->n.y;
	pl->c = pl->n.z;
	pl->d = -(pl->p.x * pl->n.x + pl->p.y * pl->n.y + pl->p.z * pl->n.z);
}

// t_sol	pl_get_intersections(const t_pl pl, const t_ray r)
// {
// 	const float	a = pl.n.x * r.d.x + pl.n.y * r.d.y + pl.n.z * r.d.z;
// 	float		sol;

// 	if (a != 0)
// 	{
// 		sol = -(pl.a * r.o.x + pl.b * r.o.y + pl.c * r.o.z + pl.d) / a;
// 		return ((t_sol){.c = 1, .x1 = {.x = r.o.x + r.d.x * sol, .y = r.o.y
// 				+ r.d.y * sol, .z = r.o.z + r.d.z * sol}});
// 	}
// 	return ((t_sol){.c = 0});
// }

t_sol	pl_get_intersections(const t_pl pl, const t_my_ray r)
{
	// const float	a = pl.n.x * r.d.x + pl.n.y * r.d.y + pl.n.z * r.d.z;
	// float		sol;

	// if (a != 0)
	// {
	// 	sol = -(pl.a * r.o.x + pl.b * r.o.y + pl.c * r.o.z + pl.d) / a;
	// 	return ((t_sol){.c = 1, .x1 = {.x = r.o.x + r.d.x * sol, .y = r.o.y
	// 			+ r.d.y * sol, .z = r.o.z + r.d.z * sol}});
	// }
	// return ((t_sol){.c = 0});
	const float	a = pl.n.x * r.direction.x + pl.n.y * r.direction.y + pl.n.z * r.direction.z;
	float		sol;

	if (a != 0)
	{
		sol = -(pl.a * r.origin.x + pl.b * r.origin.y + pl.c * r.origin.z + pl.d) / a;
		return ((t_sol){.c = 1, .x1 = {.x = r.origin.x + r.direction.x * sol, .y = r.origin.y
				+ r.direction.y * sol, .z = r.origin.z + r.direction.z * sol}});
	}
	return ((t_sol){.c = 0});
}
