/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:42:26 by stamim            #+#    #+#             */
/*   Updated: 2023/01/17 10:48:00 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include <math.h>

void	rt_parse_ambient(t_scene *scn, const char **args)
{
	static bool	full = false;

	if (full)
	{
		rt_exit("ambient light cannot be present twice\n");
	}
	full = true;
	scn->amb.ka = 1;
	(void)args;
}

void	rt_parse_camera(t_scene *scn, const char **args)
{
	static bool	full = false;

	if (full)
	{
		rt_exit("camera cannot be present twice\n");
	}
	full = true;
	scn->cam.cam_ori = (t_vec){.x = 0, .y = 0, .z = 0, .w = 1};
	scn->cam.cam_dir = (t_vec){.x = 0, .y = 0, .z = -1, .w = 0};
	scn->cam.filed_of_view = M_PI / 2;
	scn->cam.hsize = height;
	scn->cam.vsize = width;
	scn->cam.transform = matr4x4_translation(scn->cam.cam_ori.x, scn->cam
			.cam_ori.y, scn->cam.cam_ori.z);
	scn->cam.aspect = scn->cam.hsize / scn->cam.vsize;
	scn->cam.half_view = tanf(scn->cam.filed_of_view / 2);
	scn->cam.half_width = half_width(scn->cam.aspect, scn->cam.half_view);
	scn->cam.half_height = half_height(scn->cam.aspect, scn->cam.half_view);
	scn->cam.pixel_size = (scn->cam.half_width * 2) / scn->cam.hsize;
	scn->cam.aspect = 1;
	(void)args;
}

void	rt_parse_light(t_scene *scn, const char **args)
{
	static bool	full = false;

	if (full)
	{
		rt_exit("light point cannot be present twice\n");
	}
	full = true;
	(void)scn;
	(void)args;
}
