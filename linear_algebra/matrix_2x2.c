/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2x2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:00:14 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/25 20:02:09 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// print matric add 2 matrice multiple 2matri sub2matr divid 2mat

#include "../include/linear_algebra.h"
#include <math.h>

void	print_matr2x2(t_matrix_2x2 mat)
{
	int	rows;

	rows = 0;
	while (rows < 2)
	{
		printf("| %f | %f |\n", mat.m[rows][0], mat.m[rows][1]);
		rows++;
	}
}

float	determ_matr2x2(t_matrix_2x2 mat)
{
	return ((mat.m[0][0] * mat.m[1][1]) - (mat.m[0][1] * mat.m[1][0]));
}
