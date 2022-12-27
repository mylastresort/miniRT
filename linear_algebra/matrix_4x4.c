/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4x4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:01:03 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/27 10:32:18 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// add 2 matrice multiple 2matri sub2matr divid 2mat
//for the invers of a matrix we need to create a dot prodact for a matrix first

#include "../include/linear_algebra.h"
#include "../include/types.h"
#include "../include/declarations.h"
#include <stdio.h>

t_matrix_4x4	matr4x4_multi_matr4x4(t_matrix_4x4 mat1, t_matrix_4x4 mat2)
{
	int				rows;
	int				cols;
	t_matrix_4x4	mat;

	rows = 0;
	while (rows < 4)
	{
		cols = 0;
		while (cols < 4)
		{
			mat.m[rows][cols] = (mat1.m[rows][0] * mat2.m[0][cols])
				+ (mat1.m[rows][1] * mat2.m[1][cols])
				+ (mat1.m[rows][2] * mat2.m[2][cols])
				+ (mat1.m[rows][3] * mat2.m[3][cols]);
			cols++;
		}
		rows++;
	}
	return (mat);
}

t_tuple	matr4x4_multi_tuple(t_matrix_4x4 mat, t_tuple tup)
{
	int		rows;
	t_tuple	ret;

	rows = 0;
	ret.x = (mat.m[rows][0] * tup.x)
		+ (mat.m[rows][1] * tup.y)
		+ (mat.m[rows][2] * tup.z)
		+ (mat.m[rows][3] * tup.w);
	rows++;
	ret.y = (mat.m[rows][0] * tup.x)
		+ (mat.m[rows][1] * tup.y)
		+ (mat.m[rows][2] * tup.z)
		+ (mat.m[rows][3] * tup.w);
	rows++;
	ret.z = (mat.m[rows][0] * tup.x)
		+ (mat.m[rows][1] * tup.y)
		+ (mat.m[rows][2] * tup.z)
		+ (mat.m[rows][3] * tup.w);
	rows++;
	ret.w = (mat.m[rows][0] * tup.x)
		+ (mat.m[rows][1] * tup.y)
		+ (mat.m[rows][2] * tup.z)
		+ (mat.m[rows][3] * tup.w);
	return (ret);
}

void	print_matr4x4(t_matrix_4x4 mat)
{
	int	rows;

	rows = 0;
	while (rows < 4)
	{
		printf("| %f | %f | %f | %f |\n", mat.m[rows][0], mat.m[rows][1],
			mat.m[rows][2], mat.m[rows][3]);
		rows++;
	}
}

t_matrix_4x4	matr4x4_transpos(t_matrix_4x4 mat)
{
	int		rows;
	int		cols;
	float	tmp;

	rows = 0;
	while (rows < 4)
	{
		cols = rows + 1;
		while (cols < 4)
		{
			tmp = mat.m[rows][cols];
			mat.m[rows][cols] = mat.m[cols][rows];
			mat.m[cols][rows] = tmp;
			cols++;
		}
		rows++;
	}
	return (mat);
}

t_matrix_3x3	sub_matr4x4(t_matrix_4x4 mat, int row, int col)
{
	t_matrix_3x3	ret;
	int				rows;
	int				cols;
	float			iidx;
	int				jidx;

	rows = 0;
	iidx = 0;
	while (rows < 4)
	{
		cols = 0;
		jidx = 0;
		while (cols < 4 && rows != row)
		{
			if (cols != col && rows != row)
			{
				ret.m[(int)iidx][jidx] = mat.m[rows][cols];
				jidx++;
			}
			iidx += 0.25;
			cols++;
		}
		rows++;
	}
	return (ret);
}
