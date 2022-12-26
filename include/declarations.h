/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declarations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:12:53 by stamim            #+#    #+#             */
/*   Updated: 2022/12/26 15:39:09 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATIONS_H
# define DECLARATIONS_H

# include "types.h"
# include <stdbool.h>

# define EPSILON 0.00001

// TODO(stamim): mimic static_assert and assert

int				destroy(t_scene *scn);
void			parse(int file, t_scene *scn);
size_t			ft_strlen(const char *str);
void			write_error(const char *str);
bool			is_equal(float val1, float val2);
void			print_pnt(t_vec vec);
void			print_vec(t_vec vec);
t_projectile	tick(t_environment env, t_projectile prj);
t_vec			vec_div_value(t_vec vec, float val);
t_vec			vec_div_vec(t_vec vec, t_vec val);
t_vec			vec_multi_value(t_vec vec, float val);
t_vec			vec_multi_vec(t_vec vec, t_vec val);
t_vec			vec_add_value(t_vec vec, float val);
t_vec			vec_add_vec(t_vec vec, t_vec val);
t_vec			vec_sub_value(t_vec vec, float val);
t_vec			vec_sub_vec(t_vec vec, t_vec val);
t_tuple			tuple_add_value(t_tuple vec, float val);
t_tuple			tuple_add_vec(t_tuple vec, t_tuple val);
t_tuple			tuple_sub_value(t_tuple vec, float val);
t_tuple			tuple_sub_vec(t_tuple vec, t_tuple val);
t_tuple			tup_div_value(t_tuple vec, float val);
t_tuple			tup_div_vec(t_tuple vec, t_tuple val);
t_tuple			tup_multi_value(t_tuple vec, float val);
t_tuple			tup_multi_vec(t_tuple vec, t_tuple val);
t_tuple			tup_normalize(t_tuple vec);
float			tup_length(const t_vec *vec);
void			print_matr4x4(t_matrix_4x4 mat);
t_matrix_4x4	matr4x4_transpos(t_matrix_4x4 mat);
void			print_matr3x3(t_matrix_3x3 mat);
t_matrix_3x3	sub_matr4x4(t_matrix_4x4 mat, int row, int col);

#endif