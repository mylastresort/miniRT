/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2023/01/22 14:21:35 by stamim           ###   ########.fr       */
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

t_matrix_4x4	view_transform(t_point from, t_point to, t_point up)
{
	t_matrix_4x4	mat;
	t_vec			forward;
	t_vec			upn;
	t_vec			left;
	t_vec			true_up;

	forward = vec_normalize(vec_sub_vec(to, from));
	upn = vec_normalize(up);
	left = vec_cross_product(forward, upn);
	true_up = vec_cross_product(left, forward);
	mat = (t_matrix_4x4){
		.m[0][0] = left.x, .m[0][1] = left.y, .m[0][2] = left.z, .m[0][3] = 0,
		.m[1][0] = true_up.x, .m[1][1] = true_up.y,
		.m[1][2] = true_up.z, .m[1][3] = 0,
		.m[2][0] = -forward.x, .m[2][1] = -forward.y,
		.m[2][2] = -forward.z, .m[2][3] = 0,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = 0, .m[3][3] = 1,
	};
	return (matr4x4_multi_matr4x4(mat,
			matr4x4_translation(-from.x, -from.y, -from.z)));
}

// static void	test(void)
// {
// 	t_matrix_4x4	mat;
// 	const t_point	from = (t_point){1, 3, 2, 1};
// 	const t_point	to = (t_point){4, -2, 8, 1};
// 	const t_vec		up = (t_vec){1, 1, 0, 0};

// 	mat = view_transform(from, to, up);
// 	print_matr4x4(mat);
// 	exit(EXIT_FAILURE);
// }

static void	sample(const t_scene scn, t_buf *const buf)
{
	volatile uint32_t	indx[2];
	t_ray				ray;
	t_color				clr;

	puts("loops start");
	indx[0] = 0;
	while (indx[0] < height)
	{
		indx[1] = 0;
		while (indx[1] < width)
		{
			ray = ray_for_pixel(scn.cam, indx[0], indx[1]);
			clr = objects_coloring(ray, &scn);
			(*buf)[indx[0]][indx[1]] = generate_color(clr);
			indx[1] += 1;
		}
		indx[0] += 1;
	}
}

static void	init(t_scene *const scn, const int file)
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
	scn.objs = NULL;
	init(&scn, arg);
	mlx_hook(scn.win, ON_DESTROY, 0, destroy, &scn);
	mlx_hook(scn.win, ON_KEYDOWN, 0, on_keydown, &scn);
	sample(scn, (uint32_t (*)[height][width])
		mlx_get_data_addr(scn.img, &arg, &arg, &arg));
	mlx_put_image_to_window(scn.mlx, scn.win, scn.img, 0, 0);
	mlx_loop(scn.mlx);
}
