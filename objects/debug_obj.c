/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:12:27 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/14 21:21:17 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/linear_algebra.h"
#include "../include/types.h"
#include "enums.h"
#include <math.h>
#include <stdint.h>

void	debug_camera(t_camera cam)
{
	print_vec(cam.cam_ori);
	print_vec(cam.cam_dir);
	printf("file_view: %.2f\n", cam.filed_of_view);
	printf("hsize %.2f\n", cam.hsize);
	printf("vsize %.2f\n", cam.vsize);
	print_matr4x4(cam.transform);
	printf("aspect %.2f\n", cam.aspect);
	printf("half_view %.2f\n", cam.half_view);
	printf("half_width %.2f\n", cam.half_width);
	printf("half_height %.2f\n", cam.half_height);
	printf("pixel_size %.2f\n", cam.pixel_size);
}

int	generate_color(t_color clr)
{
	return (((int)clr.x << 16) | ((int)clr.y << 8) | ((int)clr.z << 4));
}

int	get_color(t_my_ray ray, t_sp sp, t_amb amb)
{
	int	clr;

	(void)ray;
	(void)sp;
	(void)amb;
	clr = sp.rgb;
	return (clr);
}
