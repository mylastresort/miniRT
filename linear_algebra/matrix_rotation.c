/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:44:36 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/08 17:10:56 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/linear_algebra.h"
#include "../include/types.h"

t_matrix_4x4	matr4x4_rotation_x(const t_rad rad)
{
	return ((t_matrix_4x4){
		.m[0][0] = 1, .m[0][1] = 0, .m[0][2] = 0, .m[0][3] = 0,
		.m[1][0] = 0, .m[1][1] = cos(rad), .m[1][2] = -(sin(rad)), .m[1][3] = 0,
		.m[2][0] = 0, .m[2][1] = sin(rad), .m[2][2] = cos(rad), .m[2][3] = 0,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = 0, .m[3][3] = 1,
	});
}

t_matrix_4x4	matr4x4_rotation_y(const t_rad rad)
{
	return ((t_matrix_4x4){
		.m[0][0] = cos(rad), .m[0][1] = 0, .m[0][2] = sin(rad), .m[0][3] = 0,
		.m[1][0] = 0, .m[1][1] = 1, .m[1][2] = 0, .m[1][3] = 0,
		.m[2][0] = -(sin(rad)), .m[2][1] = 0, .m[2][2] = cos(rad), .m[2][3] = 0,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = 0, .m[3][3] = 1,
	});
}

t_matrix_4x4	matr4x4_rotation_z(const t_rad rad)
{
	return ((t_matrix_4x4){
		.m[0][0] = cos(rad), .m[0][1] = -sin(rad), .m[0][2] = 0, .m[0][3] = 0,
		.m[1][0] = sin(rad), .m[1][1] = cos(rad), .m[1][2] = 0, .m[1][3] = 0,
		.m[2][0] = 0, .m[2][1] = 0, .m[2][2] = 1, .m[2][3] = 0,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = 0, .m[3][3] = 1,
	});
}
