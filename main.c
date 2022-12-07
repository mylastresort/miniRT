/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/12/07 08:58:32 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.h"
#include "enums.h"
#include "prototypes.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	raytrace(uint32_t (*const buf)[H][W])
{
	volatile uint32_t	cols;
	volatile uint32_t	rows;

	rows = 0;
	while (rows < H)
	{
		cols = 0;
		while (cols < W)
		{
			(*buf)[rows][cols] = ALPHA_3 | RED;
			cols += 1;
		}
		rows += 1;
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
	if (key == ESC)
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
		printf("%s\n", INVLD_ARG);
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
	raytrace((uint32_t (*)[H][W]) mlx_get_data_addr(scn.img, &arg, &arg, &arg));
	mlx_put_image_to_window(scn.mlx, scn.win, scn.img, 0, 0);
	mlx_loop(scn.mlx);
}
