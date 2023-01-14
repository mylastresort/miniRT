/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:19:17 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/14 16:02:23 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/linear_algebra.h"
#include "../include/types.h"
#include "enums.h"
#include <math.h>
#include <stdint.h>

t_color	lighting(t_material mat, t_light light, t_point pos, t_vec eye, t_vec normal)
{
	t_color	effective_color = vec_multi_vec(mat.clr, light.intensity);
	t_vec	lightv = vec_normalize(vec_sub_vec(light.position, pos));
	t_color	ambient = vec_multi_value(effective_color, mat.ambient);
	float	light_dot_normal = vec_dot_product_vec(lightv, normal);
	t_color	diffuse;
	t_color	specular;
	t_vec	reflectv;
	float	reflect_dot_eye;
	float	factor;
	if (light_dot_normal < 0)
	{
		diffuse = (t_color){0,0,0,0};
		specular = (t_color){0,0,0,0};
	}
	else
	{
		diffuse = vec_multi_value(effective_color, (mat.diffuse * light_dot_normal));
		reflectv = reflect(vec_multi_value(lightv, -1), normal);
		reflect_dot_eye = vec_dot_product_vec(reflectv, eye);
		if (reflect_dot_eye <= 0)
		{
			specular = (t_color){0,0,0,0};
		}
		else
		{
			factor = powf(reflect_dot_eye, mat.shininess);
			specular = vec_multi_value(light.intensity, (mat.specular * factor));
		}
	}
	return (vec_add_vec(vec_add_vec(ambient, diffuse), specular));
}