/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/11/30 13:56:51 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#include "prototypes.h"
#include <fcntl.h>
#include <mlx.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	destroy(t_space *euc)
{
	mlx_destroy_image(euc->mlx, euc->img);
	mlx_destroy_window(euc->mlx, euc->win);
	free(euc->mlx);
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

static void	init(t_space *const euc)
{
	euc->mlx = mlx_init();
	if (!euc->mlx)
	{
		exit(EXIT_FAILURE);
	}
	euc->win = mlx_new_window(euc->mlx, W, H, TITLE);
	if (!euc->win)
	{
		free(euc->mlx);
		exit(EXIT_FAILURE);
	}
	euc->img = mlx_new_image(euc->mlx, W, H);
	if (!euc->img)
	{
		mlx_destroy_window(euc->mlx, euc->win);
		free(euc->mlx);
		exit(EXIT_FAILURE);
	}
	parse(euc);
	close(euc->arg);
}

static void	raytrace(unsigned int (*const buf)[H][W])
{
	volatile size_t	cols;
	volatile size_t	rows;

	rows = 0;
	while (rows < H)
	{
		cols = 0;
		while (cols < W)
		{
			(*buf)[rows][cols] = RED;
			cols += 1;
		}
		rows += 1;
	}
}

int	main(const int argc, const char *argv[])
{
	t_space	euc;

	if (argc != 2)
	{
		printf("%s\n", INVLD_ARG);
		exit(EXIT_FAILURE);
	}
	else
	{
		euc.arg = open(argv[1], O_CLOEXEC, S_IRUSR);
		if (euc.arg == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
	}
	init(&euc);
	mlx_hook(euc.win, ON_DESTROY, 0, destroy, &euc);
	mlx_hook(euc.win, ON_KEYDOWN, 0, on_keydown, &euc);
	raytrace((unsigned int (*)[H][W])
		mlx_get_data_addr(euc.img, &euc.arg, &euc.arg, &euc.arg));
	mlx_put_image_to_window(euc.mlx, euc.win, euc.img, 0, 0);
	mlx_loop(euc.mlx);
}
