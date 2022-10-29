/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/10/29 22:18:09 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include <errno.h>
#include <fcntl.h>
#include <gsl/gsl_errno.h>
#include <mlx.h>
#include <stdlib.h>
#include <string.h>

int	main(const int argc, const char **argv)
{
	t_spc	spc;

	if (argc != 2 || !is_rt_arg(argv[1]))
		GSL_ERROR(INVLD_ARG, GSL_FAILURE);
	spc.file = open(argv[1], O_CLOEXEC, S_IRUSR);
	if (spc.file == -1)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	if (!fill(&spc))
		GSL_ERROR(INVLD_SCN, GSL_FAILURE);
	spc.mlx = mlx_init();
	if (!spc.mlx)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	if (!mlx_new_window(spc.mlx, WIDTH, HEIGHT, TITLE))
	{
		free(spc.mlx);
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	}
	spc.img = mlx_new_image(spc.mlx, WIDTH, HEIGHT);
	if (!spc.img)
	{
		mlx_destroy_window(spc.mlx, spc.win);
		free(spc.mlx);
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	}
	play(spc);
}
