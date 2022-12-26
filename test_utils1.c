/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:37:03 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/25 14:24:30 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/enums.h"
#include "include/declarations.h"
#include "include/macros.h"
#include "include/types.h"

t_tuple	tup_div_vec(t_tuple vec, t_tuple val)
{
	vec.x /= val.x;
	vec.y /= val.y;
	vec.z /= val.z;
	vec.w /= val.w;
	return (vec);
}

t_tuple	tup_multi_value(t_tuple vec, float val)
{
	vec.x = val;
	vec.y = val;
	vec.z = val;
	vec.w = val;
	return (vec);
}

t_tuple	tup_multi_vec(t_tuple vec, t_tuple val)
{
	vec.x = val.x;
	vec.y = val.y;
	vec.z = val.z;
	vec.w = val.w;
	return (vec);
}

float	tup_length(const t_vec *vec)
{
	return (sqrtf((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z)));
}

t_tuple	tup_normalize(t_tuple vec)
{
	const float	length = tup_length(&vec);
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
