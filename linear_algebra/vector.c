/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:26:44 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/24 18:37:53 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linear_algebra.h"
#include "../include/macros.h"

// TODO: (H-J) vec3 length normalize dotProdact crossprodact
// vec3 point addition subtraction

float	vec_length(const t_vec *vec)
{
	return (sqrtf((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z)));
}

t_vec	vec_normalize(t_vec vec)
{
	const float	length = vec_length(&vec);
	float		invers;

	if (length > 0)
	{
		invers = 1 / length;
		vec.x *= invers;
		vec.y *= invers;
		vec.z *= invers;
	}
	return (vec);
}

float	vec_dot_prodact(const t_vec *vec)
{
	return ((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z)
		+ (vec->w * vec->w));
}

// TODO : (H-J) free all destroy win and exit
t_vec	vec_cross_prodact(const t_vec *first, const t_vec *second)
{
	return ((t_vec){
		.x = (first->y * second->z) - (first->z * second->y),
		.y = (first->z * second->x) - (first->x * second->z),
		.z = (first->x * second->y) - (first->y * second->x),
		.w = 0
	});
}
