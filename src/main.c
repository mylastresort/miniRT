/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/11/30 08:40:02 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#include "prototypes.h"
#include <fcntl.h>
#include <mlx.h>
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

static void	fill(unsigned int (*buf)[HEIGHT][WIDTH])
{
	(*buf)[0][0] = RED | BLU;
}

static void	init(t_space *const euc)
{
	euc->mlx = mlx_init();
	if (!euc->mlx)
	{
		exit(EXIT_FAILURE);
	}
	euc->win = mlx_new_window(euc->mlx, WIDTH, HEIGHT, TITLE);
	if (!euc->win)
	{
		free(euc->mlx);
		exit(EXIT_FAILURE);
	}
	euc->img = mlx_new_image(euc->mlx, WIDTH, HEIGHT);
	if (!euc->img)
	{
		mlx_destroy_window(euc->mlx, euc->win);
		free(euc->mlx);
		exit(EXIT_FAILURE);
	}
	parse(euc);
	close(euc->arg);
}

int	main(const int argc, const char **argv)
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
	fill(euc.frm = (unsigned int (*)[HEIGHT][WIDTH])
		mlx_get_data_addr(euc.img, &euc.arg, &euc.arg, &euc.arg));
	mlx_put_image_to_window(euc.mlx, euc.win, euc.img, 0, 0);
	mlx_loop(euc.mlx);
}
