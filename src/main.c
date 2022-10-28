/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/10/28 17:06:54 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#include <errno.h>
#include <fcntl.h>
#include <gsl/gsl_errno.h>
#include <mlx.h>
#include <mlx_int.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

// static void	fill(void *scn, int file)
// {
// 	(void)file;
// 	scn = NULL;
// 	(void)scn;
// }

// static void	run(void *scn)
// {
// 	scn = NULL;
// 	(void)scn;
// }

static bool	is_rt_file(const char *arg)
{
	const size_t	sze = strlen(arg);

	return (sze >= 3
		&& arg[sze - 1] == 't' && arg[sze - 2] == 'r' && arg[sze - 3] == '.');
}

int	main(const int argc, const char **argv)
{
	int		file;
	t_xvar	*win;
	t_img	*img;

	if (argc != 2)
		GSL_ERROR(INVLD_ARG, GSL_FAILURE);
	if (!is_rt_file(argv[1]))
		GSL_ERROR(INVLD_FILE, GSL_FAILURE);
	file = open(argv[1], O_CLOEXEC, S_IRUSR);
	if (file == -1)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	win = mlx_init();
	if (!win)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	mlx_new_window(win, WIDTH, HEIGHT, TITLE);
	if (!win->win_list)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	img = mlx_new_image(win, WIDTH, HEIGHT);
	if (!img)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	mlx_put_image_to_window(win, win->win_list, img, 0, 0);
	mlx_destroy_image(win, img);
	mlx_destroy_window(win, img);
	if (close(file) == -1)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
}
