/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3x3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:00:52 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/26 19:51:21 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// print matric add 2 matrice multiple 2matri sub2matr divid 2mat

#include "../include/linear_algebra.h"
#include "../include/declarations.h"

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

	print_matr3x3(mat);
	ret = (t_matrix_2x2){
		.m[0][0] = 900000000, .m[0][1] = 9000000000,
		.m[1][0] = 900000000, .m[1][1] = 9000000000,
	};
	rows = 0;
	iidx = 0;
	while (rows < 3)
	{
		cols = 0;
		jidx = 0;
		while (cols < 3 && rows != row)
		{
			if (cols != col)
			{
				ret.m[(int)iidx][jidx] = mat.m[rows][cols];
				printf("%d %d\n", (int)iidx, jidx);
				jidx++;
			}
			iidx += 0.3;
			cols++;
		}
		rows++;
	}
	print_matr2x2(ret);
	return (ret);
}