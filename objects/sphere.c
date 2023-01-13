/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:48:09 by stamim            #+#    #+#             */
/*   Updated: 2023/01/13 12:03:00 by hjabbour         ###   ########.fr       */
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

// const float	a = vec_dot_product(r.d);
// const float	b = vec_dot_product_vec(r.d, r.o) * 2;
// const float	c = vec_dot_product(r.o) - powf((sp.d / 2), 2);
// this the one that works
// t_sol	sp_get_intersections(const t_ray r, const t_sp sp)
// {
// 	const float	a = powf(r.d.x, 2) + powf(r.d.y, 2) + powf(r.d.z, 2);
// 	const float	b = 2 * (r.d.x * (r.o.x + sp.c.x) + r.d.y * (r.o.y + sp.c.y)
// 			+ r.d.z * (r.o.z + sp.c.z));
// 	const float	c = 2 * (r.o.x * sp.c.x + r.o.y * sp.c.y + r.o.z * sp.c.z)
// 		+ powf(r.o.x, 2) + powf(sp.c.x, 2) + powf(r.o.y, 2) + powf(sp.c.y, 2)
// 		+ powf(r.o.z, 2) + powf(sp.c.z, 2) - powf(sp.d, 2) / 4;
// 	const float	d = powf(b, 2) - (4 * a * c);
// 	float		s[2];

// 	if (d == 0)
// 	{
// 		s[0] = -b / (2 * a);
// 		printf("%.2f\n", s[0]);
// 		return ((t_sol){.c = 1, .x1 = {.x = r.o.x + r.d.x * s[0], .y = r.o.y
// 				+ r.d.y * s[0], .z = r.o.z + r.d.z * s[0]}});
// 	}
// 	if (d > 0)
// 	{
// 		s[0] = (-b + sqrtf(d)) / (2 * a);
// 		s[1] = (-b - sqrtf(d)) / (2 * a);
// 		printf("%.2f | %.2f\n", s[0], s[1]);
// 		return ((t_sol){.c = 2, .x1 = {.x = r.o.x + r.d.x * s[0], .y = r.o.y
// 				+ r.d.y * s[0], .z = r.o.z + r.d.z * s[0]}, .x2 = {.x = r.o.x
// 				+ r.d.x * s[1], .y = r.o.y + r.d.y * s[1], .z = r.o.z + r.d.z
// 				* s[1]}});
// 	}
// 	return ((t_sol){.c = 0});
// }

t_sol	sp_get_intersections(const t_my_ray r, const t_sp sp)
{
	const float	a = powf(r.direction.x, 2) + powf(r.direction.y, 2) + powf(r.direction.z, 2);
	const float	b = -2 * (r.direction.x * (r.origin.x + sp.c.x) + r.direction.y * (r.origin.y + sp.c.y)
			+ r.direction.z * (r.origin.z + sp.c.z));
	const float	c = 2 * (r.origin.x * sp.c.x + r.origin.y * sp.c.y + r.origin.z * sp.c.z)
		+ powf(r.origin.x, 2) + powf(sp.c.x, 2) + powf(r.origin.y, 2) + powf(sp.c.y, 2)
		+ powf(r.origin.z, 2) + powf(sp.c.z, 2) - powf(sp.d, 2) / 4;
	const float	d = powf(b, 2) - (4 * a * c);
	float		s[2];

	if (d == 0)
	{
		s[0] = -b / (2 * a);
		// printf("%.2f\n", s[0]);
		return ((t_sol){.c = 1, .x1 = {.x = r.origin.x + r.direction.x * s[0], .y = r.origin.y
				+ r.direction.y * s[0], .z = r.origin.z + r.direction.z * s[0]}});
	}
	if (d > 0)
	{
		s[0] = (-b - sqrtf(d)) / (2 * a);
		s[1] = (-b + sqrtf(d)) / (2 * a);
		// printf("%.2f | %.2f\n", s[0], s[1]);
		return ((t_sol){.c = 2, .x1 = {.x = r.origin.x + r.direction.x * s[0], .y = r.origin.y
				+ r.direction.y * s[0], .z = r.origin.z + r.direction.z * s[0]}, .x2 = {.x = r.origin.x
				+ r.direction.x * s[1], .y = r.origin.y + r.direction.y * s[1], .z = r.origin.z + r.direction.z
				* s[1]}});
	}
	return ((t_sol){.c = 0});
}

// int	main(void)
// {
// 	t_ray		ray;
// 	t_sol		sols;
// 	const t_sp	sp = {.d = 100};

// 	printf("the diameter of the sphere is: %f\n", sp.d);
// 	printf("please enter the ray origin cordinates seperated by a space\n");
// 	(void)scanf("%f %f %f", &ray.o.x, &ray.o.y, &ray.o.z);
// 	printf("please enter the ray direction cordinates seperated by a space\n");
// 	(void)scanf("%f %f %f", &ray.d.x, &ray.d.y, &ray.d.z);
// 	sols = sp_get_intersections(ray, sp);
// 	printf("the number of solutions is %d\n", sols.c);
// 	if (sols.c >= 1)
// 	{
// 		printf("the first intersection is at: x = %f, y = %f, z = %f\n",
// 			sols.x1.x, sols.x1.y, sols.x1.z);
// 	}
// 	if (sols.c == 2)
// 	{
// 		printf("the second intersection is at: x = %f, y = %f, z = %f\n",
// 			sols.x2.x, sols.x2.y, sols.x2.z);
// 	}
// }
