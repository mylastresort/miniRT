/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:21:11 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/25 12:12:37 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// all the function tha debug the linear algebra and print them

#include "../include/linear_algebra.h"

void	print_vec(t_vec vec)
{
	printf("vector x: %f | y: %f | z: %f | (w: %f)\n", vec.x, vec.y,
		vec.z, vec.w);
}

void	print_pnt(t_vec vec)
{
	printf("point x: %f | y: %f | z: %f | (w: %f)\n", vec.x, vec.y,
		vec.z, vec.w);
}
