/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:45:45 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/13 11:24:17 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linear_algebra.h"
#include "../include/types.h"
#include "../include/declarations.h"

t_point	ray_position(t_ray ray, float t)
{
	return (vec_add_vec(ray.o, vec_multi_value(ray.d, t)));
}

void	debug_ray(t_my_ray ray)
{
	print_vec(ray.origin);
	print_vec(ray.direction);
}
