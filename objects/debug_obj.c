/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:12:27 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/18 15:16:03 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
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

// TODO: (hi-jack) add the alpha transparency 24 bits shifting
int	generate_color(t_color clr)
{
	return ((clr.r << 16) | (clr.g << 8) | clr.b);
}
