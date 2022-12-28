/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3x3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:00:52 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/28 14:58:06 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// print matric add 2 matrice multiple 2matri sub2matr divid 2mat

#include "../include/linear_algebra.h"
#include "../include/declarations.h"
#include <stdbool.h>

void	print_matr3x3(t_matrix_3x3 mat)
{
	int	rows;

	rows = 0;
	while (rows < 3)
	{
		printf("| %f | %f | %f |\n", mat.m[rows][0], mat.m[rows][1],
			mat.m[rows][2]);
		rows++;
	}
}

t_matrix_2x2	sub_matr3x3(t_matrix_3x3 mat, int row, int col)
{
	t_matrix_2x2	ret;
	int				rows;
	int				cols;
	float			iidx;
	int				jidx;

	rows = 0;
	iidx = 0;
	while (rows < 3)
	{
		cols = 0;
		jidx = 0;
		while (cols < 3 && rows != row)
		{
			if (cols != col && rows != row)
			{
				ret.m[(int)iidx][jidx] = mat.m[rows][cols];
				iidx += 0.5;
				jidx++;
			}
			cols++;
		}
		rows++;
	}
	return (ret);
}

float	minor_matr3x3(t_matrix_3x3 mat, int row, int col)
{
	return (determ_matr2x2(sub_matr3x3(mat, row, col)));
}

float	cofactor_matr3x3(t_matrix_3x3 mat, int row, int col)
{
	if ((row + col) % 2 != 0)
	{
		return (determ_matr2x2(sub_matr3x3(mat, row, col)) * -1);
	}
	return (determ_matr2x2(sub_matr3x3(mat, row, col)));
	;
	// if ((row + col) % 2 != 0)
	// {
	// 	return (minor_matr3x3(mat, row, col) * -1);
	// }
	// return (minor_matr3x3(mat, row, col));
}

float	determ_matr3x3(t_matrix_3x3 mat)
{
	float	res;
	int		idx;

	res = 0;
	idx = 0;
	while (idx < 3)
	{
		res += (cofactor_matr3x3(mat, 0, idx) * mat.m[0][idx]);
		// res += (minor_matr3x3(mat, 0, idx) * mat.m[0][idx]);
		idx++;
	}
	return (res);
}
