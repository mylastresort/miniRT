/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2023/02/05 13:08:30 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/enums.h"
#include "include/declarations.h"
#include "include/macros.h"
#include "include/types.h"
#include "mlx.h"
#include <i386/types.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

static void	sample(const t_scene scn, t_buf *const buf)
{
	volatile uint32_t	rows;
	volatile uint32_t	cols;
	t_ray				ray;
	t_color				clr;

	rows = 0;
	while (rows < height)
	{
		cols = 0;
		while (cols < width)
		{
			ray = ray_for_pixel(scn.cam, rows, cols);
			clr = objects_coloring(ray, &scn);
			(*buf)[rows][cols] = generate_color(clr);
			cols += 1;
		}
		rows += 1;
	}
}

static void	init(t_scene *const scn, const int file)
{
	rt_parse(scn, file, "");
	if (!scn->is_amb || !scn->is_cam || !scn->is_light || !accepted_values(scn))
		rt_exit(INVLD_SCN);
#ifndef PPM
	scn->mlx = mlx_init();
	if (!scn->mlx)
	{
		(rt_destroy_objs(scn), close(file), exit(EXIT_FAILURE));
	}
	scn->win = mlx_new_window(scn->mlx, width, height, TITLE);
	if (!scn->win)
	{
		rt_destroy_objs(scn);
		close(file);
		free(scn->mlx);
		exit(EXIT_FAILURE);
	}
	scn->img = mlx_new_image(scn->mlx, width, height);
	if (!scn->img)
	{
		rt_destroy_objs(scn);
		close(file);
		mlx_destroy_window(scn->mlx, scn->win);
		free(scn->mlx);
		exit(EXIT_FAILURE);
	}
#endif
}

int	destroy(t_scene *scn)
{
	rt_destroy_objs(scn);
	mlx_destroy_image(scn->mlx, scn->img);
	mlx_destroy_window(scn->mlx, scn->win);
	free(scn->mlx);
	exit(EXIT_SUCCESS);
}

static int	on_keydown(t_keycode key, void *arg)
{
	if (key == ESC)
	{
		destroy(arg);
	}
	return (1);
}

int	main(const int argc, const char *argv[])
{
	const int	arg = rt_open(argc, argv[1]);
	t_scene		scn;

	scn.objs = NULL;
	scn.is_amb = false;
	scn.is_cam = false;
	scn.is_light = false;
	init(&scn, arg);
#ifndef PPM
	mlx_hook(scn.win, ON_DESTROY, 0, destroy, &scn);
	mlx_hook(scn.win, ON_KEYDOWN, 0, on_keydown, &scn);
	sample(scn,
		(t_buf *)mlx_get_data_addr(scn.img, &scn.bpp, &scn.szl, &scn.end));
	mlx_put_image_to_window(scn.mlx, scn.win, scn.img, 0, 0);
	mlx_loop(scn.mlx);
#else
	(void)on_keydown;
	FILE	*const file = fopen("image.ppm", "w");
	if (!file)
	{
		perror("Error opening file.");
		rt_destroy_objs(&scn);
		close(arg);
		exit(EXIT_FAILURE);
	}
	t_buf	*const buf = malloc(sizeof(t_buf));
	if (!buf)
	{
		rt_destroy_objs(&scn);
		close(arg);
		exit(EXIT_FAILURE);
	}
	sample(scn, buf);
	fprintf(file, "P6\n%d %d\n255\n", width, height);
	for (volatile uint32_t	rows = 0; rows < height; rows++)
		for (volatile uint32_t	cols = 0; cols < width; cols++)
		{
			volatile uint32_t	color = (*buf)[rows][cols];
			volatile char		rgb[3] = {color >> 16, color >> 8, color};
			fwrite((void *)&rgb[0], sizeof(char), 1, file);
			fwrite((void *)&rgb[1], sizeof(char), 1, file);
			fwrite((void *)&rgb[2], sizeof(char), 1, file);
		}
	fclose(file);
#endif
}
