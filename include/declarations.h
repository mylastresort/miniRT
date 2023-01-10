/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declarations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:12:53 by stamim            #+#    #+#             */
/*   Updated: 2023/01/10 18:38:55 by hjabbour         ###   ########.fr       */
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
void			print_pnt(t_point pnt);
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
void			print_matr2x2(t_matrix_2x2 mat);
t_matrix_3x3	sub_matr4x4(t_matrix_4x4 mat, int row, int col);
t_matrix_2x2	sub_matr3x3(t_matrix_3x3 mat, int row, int col);
bool			is_equal_matri2x2(t_matrix_2x2 mat1, t_matrix_2x2 mat2);
bool			is_equal_matri3x3(t_matrix_3x3 mat1, t_matrix_3x3 mat2);
bool			is_equal_matri4x4(t_matrix_4x4 mat1, t_matrix_4x4 mat2);
float			determ_matr2x2(t_matrix_2x2 mat);
float			determ_matr3x3(t_matrix_3x3 mat);
float			determ_matr4x4(t_matrix_4x4 mat);
float			cofactor_matr3x3(t_matrix_3x3 mat, int row, int col);
t_matrix_4x4	invers_matr4x4(t_matrix_4x4 mat);
t_matrix_4x4	matr4x4_multi_matr4x4(t_matrix_4x4 mat1, t_matrix_4x4 mat2);
char			*ft_itoa(int n);
float			vec_dot_product(t_vec vec);
t_vec			vec_cross_product(t_vec first, t_vec second);
t_matrix_4x4	matr4x4_translation(float x, float y,
					float z);
t_matrix_4x4	matr4x4_scaling(float x, float y, float z);
t_matrix_4x4	matr4x4_rotation(float x, float y, float z);
t_matrix_4x4	matr4x4_rotation_x(t_rad rad);
t_rad			deg_to_rad(t_deg deg);
t_deg			rad_to_deg(t_rad rad);
t_tuple			matr4x4_multi_tuple(t_matrix_4x4 mat, t_tuple tup);
t_vec			matr4x4_multi_vec(t_matrix_4x4 mat, t_vec vec);
t_point			matr4x4_multi_point(t_matrix_4x4 mat, t_point pnt);
// t_matrix_4x4	matr4x4_shearing(float x[2], float y[2], float z[2]);
t_matrix_4x4	matr4x4_shearing(const float x[2],
					const float y[2], const float z[2]);
float			vec_length(t_vec vec);
t_vec			vec_normalize(t_vec vec);
float			half_width(const float aspect, const float half_view);
float			half_height(const float aspect, const float half_view);
t_my_ray		ray_for_pixel(t_camera cam, uint32_t x, uint32_t y);
t_color			coloring(t_my_ray ray);

#endif