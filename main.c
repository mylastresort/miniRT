/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2023/01/10 18:22:56 by hjabbour         ###   ########.fr       */
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
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

// void	test(void)
// {
// 	;
// }

// int	generate_rgb(int r, int g, int b)
int	generate_rgb(t_color colr)
{
	return (((int)colr.x << 16) | ((int)colr.y << 8) | (int)colr.y);
}

// t_tuple	at(const float t, const t_tuple orig, const t_tuple dir)
// {
// 	return (tup_multi_vec(orig, tup_multi_value(dir, t)));
// }

// int	shade_point(t_vec pnt, t_vec norm)
// {
// 	;
// 	return (0);
}

// t_vec	closest_intersection(t_sol *sol, int count_list)
// {
// 	t_vec	min;
// 	while(count_list > -1)
// 	{
// 		sol[count_list - 1];
// 		count_list--;
// 	}
// 	return (min);
// }

static void	sample(uint32_t (*const buf)[H][W])
{
	volatile uint32_t	indx[2];
	t_color				colr;
	t_vec				pnt;
	t_vec				norm;
	t_my_ray			ray;
	const t_camera		cam = (t_camera){
		.cam_ori = {.x = -50, .y = 0, .z = 20, .w = 1},
		.cam_dir = {.x = 0, .y = 0, .z = 0, .w = 0},
		.filed_of_view = 70,
		.hsize = W,
		.vsize = H,
		.transform = matr4x4_translation(cam.cam_ori.x, cam.cam_ori.y,
			cam.cam_ori.z),
		.aspect = cam.hsize / cam.vsize,
		.half_view = tanf(cam.filed_of_view / 2),
		.half_width = half_width(cam.aspect, cam.half_view),
		.half_height = half_height(cam.aspect, cam.half_view),
		.pixel_size = (cam.half_width * 2) / cam.hsize,
	};

	(void)cam;
	(void)colr;
	(void)norm;
	(void)pnt;
	(void)ray;
	indx[0] = 0;
	while (indx[0] < H)
	{
		indx[1] = 0;
		while (indx[1] < W)
		{
			ray = ray_for_pixel(cam, indx[0], indx[1]);
			colr = coloring(ray);
			(*buf)[indx[0]][indx[1]] = generate_rgb(colr);
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
