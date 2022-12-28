/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4x4_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:32:06 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/28 11:03:47y hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linear_algebra.h"
#include "../include/types.h"
#include "../include/declarations.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//TODO: (H-J) complete this one below
float	minor_matr4x4(t_matrix_4x4 mat)
{
	float	res;

	res = 0;
	(void)mat;
	return (res);
}

float	determ_matr4x4(t_matrix_4x4 mat)
{
	float			res;
	float			tmp;
	int				idx;

	idx = 0;
	res = 0;
	while (idx < 4)
	{
		tmp = determ_matr3x3(sub_matr4x4(mat, 0, idx));
		if (idx % 2 != 0)
		{
			tmp *= -1;
		}
		res += (tmp * mat.m[0][idx]);
		idx++;
	}
	return (res);
}

bool	is_invertible4x4(t_matrix_4x4 mat)
{
	return (determ_matr4x4(mat) != 0);
}

// TODO: (H-J) free and destroy the image befor exit
t_matrix_4x4	invers_matr4x4(t_matrix_4x4 mat)
{
	t_matrix_4x4	ret;
	const float		determ = determ_matr4x4(mat);
	float			cofac;
	int				idx;
	int				jdx;

	if (determ == 0)
	{
		write_error("Matrix not inversable");
		exit(EXIT_FAILURE);
	}
	idx = 0;
	while (idx < 4)
	{
		jdx = 0;
		while (jdx < 4)
		{
			// cofac = cofactor_matr3x3(sub_matr4x4(mat, idx, jdx), idx, jdx);
			cofac = determ_matr3x3(sub_matr4x4(mat, idx, jdx));
			ret.m[jdx][idx] = cofac / determ;
			if ((idx + jdx) % 2 != 0)
			{
				ret.m[jdx][idx] *= -1;
			}
			// ret.m[idx][jdx] = cofac / determ;
			jdx++;
		}
		idx++;
	}
	return (ret);
}
