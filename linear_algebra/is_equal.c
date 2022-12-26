/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:21:50 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/25 19:23:07 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/linear_algebra.h"

bool	is_equal(float val1, float val2)
{
	if (fabsf(val1 - val2) < EPSILON)
	{
		return (true);
	}
	return (false);
}

bool	is_equal_matrix2(t_matrix_2x2 mat1, t_matrix_2x2 mat2)
{
	return (is_equal(mat1.m[0][0], mat2.m[0][0])
		&& is_equal(mat1.m[0][1], mat2.m[0][1])
		&& is_equal(mat1.m[1][0], mat2.m[1][0])
		&& is_equal(mat1.m[1][1], mat2.m[1][1]));
}

bool	is_equal_matrix3(t_matrix_3x3 mat1, t_matrix_3x3 mat2)
{
	return (is_equal(mat1.m[0][0], mat2.m[0][0])
		&& is_equal(mat1.m[0][1], mat2.m[0][1])
		&& is_equal(mat1.m[0][2], mat2.m[0][2])
		&& is_equal(mat1.m[1][0], mat2.m[1][0])
		&& is_equal(mat1.m[1][1], mat2.m[1][1])
		&& is_equal(mat1.m[1][2], mat2.m[1][2])
		&& is_equal(mat1.m[2][0], mat2.m[2][0])
		&& is_equal(mat1.m[2][1], mat2.m[2][1])
		&& is_equal(mat1.m[2][2], mat2.m[2][2])
		);
}

bool	is_equal_matrix4(t_matrix_4x4 mat1, t_matrix_4x4 mat2)
{
	return (is_equal(mat1.m[0][0], mat2.m[0][0])
		&& is_equal(mat1.m[0][1], mat2.m[0][1])
		&& is_equal(mat1.m[0][2], mat2.m[0][2])
		&& is_equal(mat1.m[0][3], mat2.m[0][3])
		&& is_equal(mat1.m[1][0], mat2.m[1][0])
		&& is_equal(mat1.m[1][1], mat2.m[1][1])
		&& is_equal(mat1.m[1][2], mat2.m[1][2])
		&& is_equal(mat1.m[1][3], mat2.m[1][3])
		&& is_equal(mat1.m[2][0], mat2.m[2][0])
		&& is_equal(mat1.m[2][1], mat2.m[2][1])
		&& is_equal(mat1.m[2][2], mat2.m[2][2])
		&& is_equal(mat1.m[2][3], mat2.m[2][3])
		&& is_equal(mat1.m[3][0], mat2.m[3][0])
		&& is_equal(mat1.m[3][1], mat2.m[3][1])
		&& is_equal(mat1.m[3][2], mat2.m[3][2])
		&& is_equal(mat1.m[3][3], mat2.m[3][3])
		);
}
