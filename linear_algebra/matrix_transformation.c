/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:05:03 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/08 17:24:54 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/linear_algebra.h"
#include "../include/types.h"

t_matrix_4x4	matr4x4_translation(const float x, const float y, const float z)
{
	return ((t_matrix_4x4){
		.m[0][0] = 1, .m[0][1] = 0, .m[0][2] = 0, .m[0][3] = x,
		.m[1][0] = 0, .m[1][1] = 1, .m[1][2] = 0, .m[1][3] = y,
		.m[2][0] = 0, .m[2][1] = 0, .m[2][2] = 1, .m[2][3] = z,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = 0, .m[3][3] = 1,
	});
}

t_matrix_4x4	matr4x4_scaling(const float x, const float y, const float z)
{
	return ((t_matrix_4x4){
		.m[0][0] = x, .m[0][1] = 0, .m[0][2] = 0, .m[0][3] = 0,
		.m[1][0] = 0, .m[1][1] = y, .m[1][2] = 0, .m[1][3] = 0,
		.m[2][0] = 0, .m[2][1] = 0, .m[2][2] = z, .m[2][3] = 0,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = 0, .m[3][3] = 1,
	});
}

t_matrix_4x4	matr4x4_rotation(const float x, const float y, const float z)
{
	return ((t_matrix_4x4){
		.m[0][0] = x, .m[0][1] = 0, .m[0][2] = 0, .m[0][3] = 0,
		.m[1][0] = 0, .m[1][1] = y, .m[1][2] = 0, .m[1][3] = 0,
		.m[2][0] = 0, .m[2][1] = 0, .m[2][2] = z, .m[2][3] = 0,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = 0, .m[3][3] = 1,
	});
}

t_matrix_4x4	matr4x4_shearing(const float x[2],
		const float y[2], const float z[2])
{
	return ((t_matrix_4x4){
		.m[0][0] = 1, .m[0][1] = x[0], .m[0][2] = x[1], .m[0][3] = 0,
		.m[1][0] = y[0], .m[1][1] = 1, .m[1][2] = y[1], .m[1][3] = 0,
		.m[2][0] = z[0], .m[2][1] = z[1], .m[2][2] = 1, .m[2][3] = 0,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = 0, .m[3][3] = 1,
	});
}
