/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declarations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:12:53 by stamim            #+#    #+#             */
/*   Updated: 2023/01/16 11:05:34 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATIONS_H
# define DECLARATIONS_H

# include "types.h"
# include <stdbool.h>
# include <stdint.h>

# define EPSILON 0.00001

// TODO(stamim): mimic static_assert and assert

bool			is_equal_matri2x2(t_matrix_2x2 mat1, t_matrix_2x2 mat2);
bool			is_equal_matri3x3(t_matrix_3x3 mat1, t_matrix_3x3 mat2);
bool			is_equal_matri4x4(t_matrix_4x4 mat1, t_matrix_4x4 mat2);
bool			is_equal(float val1, float val2);
char			*ft_itoa(int n);
float			cofactor_matr3x3(t_matrix_3x3 mat, int row, int col);
float			determ_matr2x2(t_matrix_2x2 mat);
float			determ_matr3x3(t_matrix_3x3 mat);
float			determ_matr4x4(t_matrix_4x4 mat);
float			half_height(float aspect, float half_view);
float			half_width(float aspect, float half_view);
float			tup_length(t_vec *vec);
float			vec_dot_product_vec(t_vec vec1, t_vec vec2);
float			vec_dot_product(t_vec vec);
float			vec_length(t_vec vec);
int				destroy(t_scene *scn);
int				generate_color(t_color clr);
int				light_coloring(const t_ray ray, t_sol sol);
size_t			ft_strlen(char *str);
t_deg			rad_to_deg(t_rad rad);
t_matrix_2x2	sub_matr3x3(t_matrix_3x3 mat, int row, int col);
t_matrix_3x3	sub_matr4x4(t_matrix_4x4 mat, int row, int col);
t_matrix_4x4	invers_matr4x4(t_matrix_4x4 mat);
t_matrix_4x4	matr4x4_multi_matr4x4(t_matrix_4x4 mat1, t_matrix_4x4 mat2);
t_matrix_4x4	matr4x4_rotation_x(t_rad rad);
t_matrix_4x4	matr4x4_rotation(float x, float y, float z);
t_matrix_4x4	matr4x4_scaling(float x, float y, float z);
t_matrix_4x4	matr4x4_shearing(float x[2], float y[2], float z[2]);
t_matrix_4x4	matr4x4_translation(float x, float y, float z);
t_matrix_4x4	matr4x4_transpos(t_matrix_4x4 mat);
t_point			matr4x4_multi_point(t_matrix_4x4 mat, t_point pnt);
t_point			ray_position(t_ray ray, float t);
t_rad			deg_to_rad(t_deg deg);
t_ray			ray_for_pixel(t_camera cam, int x, int y);
t_sol			pl_get_intersections(t_pl pl, t_ray r);
t_sol			sp_get_intersections(t_ray r, t_sp sp);
t_sol			objects_coloring(const t_ray ray);
t_tuple			matr4x4_multi_tuple(t_matrix_4x4 mat, t_tuple tup);
t_tuple			tup_div_value(t_tuple vec, float val);
t_tuple			tup_div_vec(t_tuple vec, t_tuple val);
t_tuple			tup_multi_value(t_tuple vec, float val);
t_tuple			tup_multi_vec(t_tuple vec, t_tuple val);
t_tuple			tup_normalize(t_tuple vec);
t_tuple			tuple_add_value(t_tuple vec, float val);
t_tuple			tuple_add_vec(t_tuple vec, t_tuple val);
t_tuple			tuple_sub_value(t_tuple vec, float val);
t_tuple			tuple_sub_vec(t_tuple vec, t_tuple val);
t_vec			matr4x4_multi_vec(t_matrix_4x4 mat, t_vec vec);
t_vec			normal_at(t_point obj_ori, t_point pnt);
t_vec			reflect(t_vec in, t_vec normal);
t_vec			vec_add_value(t_vec vec, float val);
t_vec			vec_add_vec(t_vec vec, t_vec val);
t_vec			vec_cross_product(t_vec first, t_vec second);
t_vec			vec_div_value(t_vec vec, float val);
t_vec			vec_div_vec(t_vec vec, t_vec val);
t_vec			vec_multi_value(t_vec vec, float val);
t_vec			vec_multi_vec(t_vec vec, t_vec val);
t_vec			vec_normalize(t_vec vec);
t_vec			vec_sub_value(t_vec vec, float val);
t_vec			vec_sub_vec(t_vec vec, t_vec val);
void			debug_camera(t_camera cam);
void			debug_ray(t_ray ray);
void			parse(int file, t_scene *scn);
void			pl_get_coefficients(t_pl *const pl);
void			print_matr2x2(t_matrix_2x2 mat);
void			print_matr3x3(t_matrix_3x3 mat);
void			print_matr4x4(t_matrix_4x4 mat);
void			print_pnt(t_point pnt);
void			print_vec(t_vec vec);
void			sp_translate(t_sp *const sp, const t_vec fac);
void			write_error(const char *str);

#endif