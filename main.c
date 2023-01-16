/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2023/01/16 11:04:54 by hjabbour         ###   ########.fr       */
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

static void	init(t_scene *const scn, const int file)
{
	scn->mlx = mlx_init();
	if (!scn->mlx)
	{
		close(file);
		exit(EXIT_FAILURE);
	}
	scn->win = mlx_new_window(scn->mlx, W, H, TITLE);
	if (!scn->win)
	{
		close(file);
		free(scn->mlx);
		exit(EXIT_FAILURE);
	}
	scn->img = mlx_new_image(scn->mlx, W, H);
	if (!scn->img)
	{
		close(file);
		mlx_destroy_window(scn->mlx, scn->win);
		free(scn->mlx);
		exit(EXIT_FAILURE);
	}
	parse(file, scn);
}

int	destroy(t_scene *scn)
{
	mlx_destroy_image(scn->mlx, scn->img);
	mlx_destroy_window(scn->mlx, scn->win);
	free(scn->mlx);
	exit(EXIT_SUCCESS);
}

static int	on_keydown(t_keycode key, void *arg)
{
	if (key == ESC || key == Q)
	{
		destroy(arg);
	}
	return (1);
}

int	main(const int argc, const char *argv[])
{
	int		arg;
	t_scene	scn;

	if (argc != 2)
	{
		write_error(INVLD_ARG);
		exit(EXIT_FAILURE);
	}
	else
	{
		arg = open(argv[1], O_CLOEXEC, S_IRUSR);
		if (arg == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
	}
	init(&scn, arg);
	mlx_hook(scn.win, ON_DESTROY, 0, destroy, &scn);
	mlx_hook(scn.win, ON_KEYDOWN, 0, on_keydown, &scn);
	sample((uint32_t (*)[H][W])
		mlx_get_data_addr(scn.img, &arg, &arg, &arg));
	mlx_put_image_to_window(scn.mlx, scn.win, scn.img, 0, 0);
	mlx_loop(scn.mlx);
}
