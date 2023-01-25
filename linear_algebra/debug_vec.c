/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:21:11 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/24 12:59:57 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	print_vec(t_vec vec)
{
	printf("vector x: %.5f | y: %.5f | z: %.5f | (w: %.5f)\n", vec.x, vec.y,
		vec.z, vec.w);
}

void	print_clr(t_color clr)
{
	printf("color r: %d | g: %d | b: %d\n", clr.r, clr.g, clr.b);
}

void	print_pnt(t_point pnt)
{
	printf("point x: %.2f | y: %.2f | z: %.2f | (w: %.2f)\n", pnt.x, pnt.y,
		pnt.z, pnt.w);
}
