/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:06:39 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/25 12:30:45 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linear_algebra.h"

t_vec	vec_div_value(t_vec vec, float val)
{
	vec.x /= val;
	vec.y /= val;
	vec.z /= val;
	return (vec);
}

t_vec	vec_div_vec(t_vec vec, t_vec val)
{
	vec.x /= val.x;
	vec.y /= val.y;
	vec.z /= val.z;
	return (vec);
}

t_vec	vec_multi_value(t_vec vec, float val)
{
	vec.x = val;
	vec.y = val;
	vec.z = val;
	return (vec);
}

t_vec	vec_multi_vec(t_vec vec, t_vec val)
{
	vec.x = val.x;
	vec.y = val.y;
	vec.z = val.z;
	return (vec);
}
