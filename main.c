/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2023/01/17 10:39:42 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/enums.h"
#include "include/declarations.h"
#include "include/macros.h"
#include "include/types.h"
#include "mlx.h"
#include <i386/types.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

static void	sample(const t_scene scn, t_buf *const buf)
{
	volatile uint32_t	indx[2];
	t_ray				ray;
	t_camera			cam;
	int					clr;
	t_sol				sol;

	cam.cam_ori = (t_vec){.x = 0, .y = 0, .z = 0, .w = 1};
	cam.cam_dir = (t_vec){.x = 0, .y = 0, .z = -1, .w = 0};
	cam.filed_of_view = M_PI / 2;
	cam.hsize = height;
	cam.vsize = width;
	cam.transform = matr4x4_translation(cam.cam_ori.x, cam.cam_ori.y,
			cam.cam_ori.z);
	cam.aspect = cam.hsize / cam.vsize;
	cam.half_view = tanf(cam.filed_of_view / 2);
	cam.half_width = half_width(cam.aspect, cam.half_view);
	cam.half_height = half_height(cam.aspect, cam.half_view);
	cam.pixel_size = (cam.half_width * 2) / cam.hsize;
	((void)cam, (void)ray, (void)scn);
	indx[0] = 0;
	puts("loops start");
	while (indx[0] < height)
	{
		indx[1] = 0;
		while (indx[1] < width)
		{
			ray = ray_for_pixel(cam, indx[0], indx[1]);
			sol = objects_coloring(ray);
			clr = light_coloring(ray, sol);
			if (clr != 0)
				(*buf)[indx[0]][indx[1]] = clr;
			indx[1] += 1;
		}
		indx[0] += 1;
	}
}

static void	rt_init(t_scene *const scn, const int file)
{
	rt_parse(scn, file);
	scn->mlx = mlx_init();
	if (!scn->mlx)
	{
		close(file);
		exit(EXIT_FAILURE);
	}
	scn->win = mlx_new_window(scn->mlx, width, height, TITLE);
	if (!scn->win)
	{
		close(file);
		free(scn->mlx);
		exit(EXIT_FAILURE);
	}
	scn->img = mlx_new_image(scn->mlx, width, height);
	if (!scn->img)
	{
		close(file);
		mlx_destroy_window(scn->mlx, scn->win);
		free(scn->mlx);
		exit(EXIT_FAILURE);
	}
}

int	main(const int argc, const char *argv[])
{
	t_scene	scn;

	scn.objs = NULL;
	rt_init(&scn, rt_open(argc, argv[1]));
	mlx_hook(scn.win, ON_DESTROY, 0, rt_destroy, (void *)&scn);
	mlx_hook(scn.win, ON_KEYDOWN, 0, event_on_keydown, (void *)&scn);
	sample(scn, (t_buf *)mlx_get_data_addr(scn.img, NUL, NUL, NUL));
	mlx_put_image_to_window(scn.mlx, scn.win, scn.img, 0, 0);
	mlx_loop(scn.mlx);
}
