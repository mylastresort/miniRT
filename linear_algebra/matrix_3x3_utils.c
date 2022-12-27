/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3x3_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:20:02 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/27 19:20:34 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linear_algebra.h"
#include "../include/declarations.h"
#include <stdbool.h>

bool	is_invertible3x3(t_matrix_3x3 mat)
{
	return (determ_matr3x3(mat) != 0);
}
