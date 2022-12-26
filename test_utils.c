/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:35:28 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/25 14:24:19 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/enums.h"
#include "include/declarations.h"
#include "include/macros.h"
#include "include/types.h"

t_tuple	tuple_add_value(t_tuple vec, float val)
{
	vec.x += val;
	vec.y += val;
	vec.z += val;
	vec.w += val;
	return (vec);
}

t_tuple	tuple_add_vec(t_tuple vec, t_tuple val)
{
	vec.x += val.x;
	vec.y += val.y;
	vec.z += val.z;
	vec.w += val.w;
	return (vec);
}

t_tuple	tuple_sub_value(t_tuple vec, float val)
{
	vec.x -= val;
	vec.y -= val;
	vec.z -= val;
	vec.w -= val;
	return (vec);
}

t_tuple	tuple_sub_vec(t_tuple vec, t_tuple val)
{
	vec.x -= val.x;
	vec.y -= val.y;
	vec.z -= val.z;
	vec.w -= val.w;
	return (vec);
}

t_tuple	tup_div_value(t_tuple vec, float val)
{
	vec.x /= val;
	vec.y /= val;
	vec.z /= val;
	vec.w /= val;
	return (vec);
}
