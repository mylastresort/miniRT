/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4x4_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:32:06 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/27 19:18:45 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linear_algebra.h"
#include "../include/types.h"
#include "../include/declarations.h"
#include <stdbool.h>
#include <stdio.h>

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
