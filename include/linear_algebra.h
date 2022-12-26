/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:25:17 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/25 16:11:53 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_ALGEBRA_H
# define LINEAR_ALGEBRA_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_vec {
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec;

typedef struct s_matrix_2x2 {
	float	m[2][2];
	float	r0c0;
	float	r0c1;
	float	r1c0;
	float	r1c1;
}	t_matrix_2x2;

typedef struct s_matrix_3x3 {
	float	m[3][3];
	float	r0c0;
	float	r0c1;
	float	r0c2;
	float	r1c0;
	float	r1c1;
	float	r1c2;
	float	r2c0;
	float	r2c1;
	float	r2c2;
}	t_matrix_3x3;

typedef struct s_matrix_4x4 {
	float	m[4][4];
	float	r0c0;
	float	r0c1;
	float	r0c2;
	float	r0c3;
	float	r1c0;
	float	r1c1;
	float	r1c2;
	float	r1c3;
	float	r2c0;
	float	r2c1;
	float	r2c2;
	float	r2c3;
	float	r3c0;
	float	r3c1;
	float	r3c2;
	float	r3c3;
}	t_matrix_4x4;

#endif