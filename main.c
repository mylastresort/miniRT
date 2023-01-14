/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2023/01/14 20:17:42 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/enums.h"
#include "include/declarations.h"
#include "include/macros.h"
#include "include/types.h"
#include "include/linear_algebra.h"
#include "mlx.h"
#include <i386/types.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

// t_my_ray	generate_ray(t_camera cam, uint32_t x, uint32_t y)
t_my_ray	generate_ray(t_camera cam, int x, int y)
{
	t_my_ray	ray;

	ray.x_offset = (x + 0.5) * cam.pixel_size;
	ray.y_offset = (y + 0.5) * cam.pixel_size;
	ray.world_x = cam.half_width - ray.x_offset;
	ray.world_y = cam.half_height - ray.y_offset;
	ray.pixel = matr4x4_multi_vec(invers_matr4x4(cam.transform),
			(t_vec){.x = ray.world_x, .y = ray.world_y, .z = 1, .w = 1});
	ray.origin = matr4x4_multi_vec(invers_matr4x4(cam.transform),
			(t_vec){.x = 0, .y = 0, .z = 0, .w = 1});
	ray.direction = vec_normalize(vec_sub_vec(ray.pixel, ray.origin));
	return (ray);
}

static void	sample(uint32_t (*const buf)[H][W])
{
	// volatile uint32_t	indx[2];
	int					indx[2];
	t_color				colr;
	t_my_ray			ray;
	t_camera			cam;
	t_vec				pnt;
	t_vec				norm;
	t_sol				sol;
	int					n;

	cam.cam_ori = (t_vec){.x = 0, .y = 0, .z = 0, .w = 1};
	cam.cam_dir = (t_vec){.x = 0, .y = 0, .z = -1, .w = 0};
	cam.filed_of_view = M_PI / 2;
	cam.hsize = H;
	cam.vsize = W;
	cam.transform = matr4x4_translation(cam.cam_ori.x, cam.cam_ori.y,
		cam.cam_ori.z);
	cam.aspect = cam.hsize / cam.vsize;
	cam.half_view = tanf(cam.filed_of_view / 2);
	cam.half_width = half_width(cam.aspect, cam.half_view);
	cam.half_height = half_height(cam.aspect, cam.half_view);
	cam.pixel_size = (cam.half_width * 2) / cam.hsize;
	((void)cam, (void)colr, (void)norm, (void)pnt, (void)ray, (void)sol);
	indx[0] = 0;
	puts("loops start");
	while (indx[0] < H)
	{
		indx[1] = 0;
		while (indx[1] < W)
		{
			ray = ray_for_pixel(cam, indx[0], indx[1]);
			// (*buf)[indx[0]][indx[1]] = coloring(ray, 0);
			n = coloring(ray, 0);
			if (n != 0)
				(*buf)[indx[0]][indx[1]] = n;
			indx[1] += 1;
		}
		indx[0] += 1;
	}
	indx[0] = 0;
	puts("loops start");
	while (indx[0] < H)
	{
		indx[1] = 0;
		while (indx[1] < W)
		{
			ray = ray_for_pixel(cam, indx[0], indx[1]);
			// (*buf)[indx[0]][indx[1]] = coloring(ray);
			n = coloring(ray, 1);
			if (n != 0)
				(*buf)[indx[0]][indx[1]] = n;
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
