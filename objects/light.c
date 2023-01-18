/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:19:17 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/18 15:15:00 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/types.h"
#include "enums.h"
#include <math.h>
#include <stdint.h>

t_color	clamp(t_color clr)
{
	if (clr.r > 255)
		clr.r = 255;
	if (clr.r < 0)
		clr.r = 0;
	if (clr.g > 255)
		clr.g = 255;
	if (clr.g < 0)
		clr.g = 0;
	if (clr.b > 255)
		clr.b = 255;
	if (clr.b < 0)
		clr.b = 0;
	return (clr);
}

static t_color	diffuse(t_vec normal, t_vec light_direcion, t_color light_color)
{
	float	diffuse_coefficient;
	t_color	diffuse_color;

	diffuse_coefficient = vec_dot_product_vec(normal, light_direcion);
	if (diffuse_coefficient < 0.0F)
	{
		diffuse_coefficient = 0;
	}
	diffuse_color = clr_multi_value(light_color, diffuse_coefficient);
	return (diffuse_color);
}

t_color	light_coloring(const t_ray ray, t_sol sol, t_sp sp)
{
	const t_amb		amb = (t_amb){
		.la = (t_color){.r = 5, .g = 6, .b = 5},
		.ka = 0.2F,
	};
	const t_light	light = (t_light){
		.clr = (t_color){255, 250, 255}, .brigth = 0.6F,
		.position = (t_point){-10, 10, 10, 0}
	};
	const t_vec		light_direcion
		= vec_normalize(vec_sub_vec(light.position, sol.x1));
	t_color			final_ambient;
	t_color			diffuse_color;

	final_ambient = clr_multi_value(amb.la, amb.ka);
	diffuse_color = diffuse(normal_at_sphere(sp.c, sol.x1),
			light_direcion, light.clr);
	diffuse_color = clamp(diffuse_color);
	final_ambient = clamp(final_ambient);
	(void)ray;
	return (clr_add_clr(final_ambient, clr_multi_clr(sp.rgb, diffuse_color)));
}
