/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/10/28 18:41:09 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include <gsl/gsl_errno.h>
#include <mlx.h>

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
	spc.vars = mlx_init();
	if (!spc.vars)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	if (!mlx_new_window(spc.vars, WIDTH, HEIGHT, TITLE))
	{
		free(spc.vars);
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	}
	spc.img = mlx_new_image(spc.vars, WIDTH, HEIGHT);
	if (!spc.img)
	{
		mlx_destroy_window(spc.vars, spc.vars->win_list);
		free(spc.vars);
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	}
	play(spc);
}
