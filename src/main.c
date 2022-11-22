/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/11/22 17:22:20 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

static int	destroy(void *param)
{
	t_spc *const	spc = param;

	mlx_destroy_image(spc->mlx, spc->img);
	mlx_destroy_window(spc->mlx, spc->win);
	free(spc->mlx);
	exit(EXIT_SUCCESS);
}

static int	on_keydown(int keycode, void *param)
{
	if (keycode == ESC)
	{
		destroy(param);
	}
	return (1);
}

static void	fill(int (*buf)[HEIGHT][WIDTH])
{
	*buf[0][0] = RED;
}

static void	init(t_spc *const space)
{
	space->mlx = mlx_init();
	if (!space->mlx)
	{
		exit(EXIT_FAILURE);
	}
	space->win = mlx_new_window(space->mlx, WIDTH, HEIGHT, TITLE);
	if (!space->win)
	{
		free(space->mlx);
		exit(EXIT_FAILURE);
	}
	space->img = mlx_new_image(space->mlx, WIDTH, HEIGHT);
	if (!space->img)
	{
		mlx_destroy_window(space->mlx, space->win);
		free(space->mlx);
		exit(EXIT_FAILURE);
	}
}

int	main(const int argc, const char **argv)
{
	t_spc	space;

	if (argc == 2)
	{
		space.arg = open(argv[1], O_CLOEXEC, S_IRUSR);
		if (space.arg == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
	}
	else if (argc > 2)
	{
		printf("%s\n", TOO_ARG);
		exit(EXIT_FAILURE);
	}
	init(&space);
	space.frm = (int (*)[HEIGHT][WIDTH])
		mlx_get_data_addr(space.img, &space.bpp, &space.lnsz, &space.end);
	fill(space.frm);
	mlx_hook(space.win, ON_DESTROY, 0, destroy, &space);
	mlx_hook(space.win, ON_KEYDOWN, 0, on_keydown, &space);
	mlx_put_image_to_window(space.mlx, space.win, space.img, 0, 0);
	mlx_loop(space.mlx);
}
