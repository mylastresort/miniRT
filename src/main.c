/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/10/27 12:55:37 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#include <errno.h>
#include <fcntl.h>
#include <gsl/gsl_errno.h>
#include <string.h>
#include <unistd.h>

int	main(const int argc, const char **argv)
{
	int	scene;

	if (argc != 2)
		GSL_ERROR(INVLD_ARG, GSL_FAILURE);
	scene = open(argv[1], O_CLOEXEC, S_IRUSR);
	if (scene == -1)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	if (close(scene) == -1)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
}
