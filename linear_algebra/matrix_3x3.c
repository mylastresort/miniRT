/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3x3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:00:52 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/25 19:24:12 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// print matric add 2 matrice multiple 2matri sub2matr divid 2mat

#include "../include/linear_algebra.h"

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
