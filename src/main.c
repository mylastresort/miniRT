/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/10/30 12:13:20 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include <errno.h>
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(const int argc, const char **argv)
{
	t_spc	spc;

	if (argc != 2 || !is_rt_arg(argv[1]))
		return (printf("%s\n", INVLD_ARG), EXIT_FAILURE);
	spc.file = open(argv[1], O_CLOEXEC, S_IRUSR);
	if (spc.file == -1)
		return (printf("%s\n", strerror(errno)), EXIT_FAILURE);
	if (!fill(&spc))
		return (printf("%s\n", INVLD_SCN), EXIT_FAILURE);
	spc.mlx = mlx_init();
	if (!spc.mlx)
		return (printf("%s\n", strerror(errno)), EXIT_FAILURE);
	spc.win = mlx_new_window(spc.mlx, WIDTH, HEIGHT, TITLE);
	if (!spc.win)
		return (free(spc.mlx), printf("%s\n", strerror(errno)), EXIT_FAILURE);
	spc.img = mlx_new_image(spc.mlx, WIDTH, HEIGHT);
	if (!spc.img)
	{
		mlx_destroy_window(spc.mlx, spc.win);
		free(spc.mlx);
		return (printf("%s\n", strerror(errno)), EXIT_FAILURE);
	}
	play(spc);
}
