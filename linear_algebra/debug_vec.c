/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:21:11 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/08 16:22:53 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linear_algebra.h"
#include "../include/types.h"

void	print_vec(t_vec vec)
{
	printf("vector x: %f | y: %f | z: %f | (w: %f)\n", vec.x, vec.y,
		vec.z, vec.w);
}

void	print_pnt(t_point pnt)
{
	printf("point x: %f | y: %f | z: %f | (w: %f)\n", pnt.x, pnt.y,
		pnt.z, pnt.w);
}
