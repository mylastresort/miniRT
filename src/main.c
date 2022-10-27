/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/10/27 13:28:27 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#include <errno.h>
#include <fcntl.h>
#include <gsl/gsl_errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

static void	fill(void *scn, int file)
{
	(void)file;
	scn = NULL;
	(void)scn;
}

static bool	is_rt_file(const char *arg)
{
	const size_t	sze = strlen(arg);

	return (sze >= 3
		&& arg[sze - 1] == 't' && arg[sze - 2] == 'r' && arg[sze - 3] == '.');
}

static void	run(void *scn)
{
	scn = NULL;
	(void)scn;
}

int	main(const int argc, const char **argv)
{
	char	scn;
	int		file;

	if (argc != 2)
		GSL_ERROR(INVLD_ARG, GSL_FAILURE);
	if (!is_rt_file(argv[1]))
		GSL_ERROR(INVLD_FILE, GSL_FAILURE);
	file = open(argv[1], O_CLOEXEC, S_IRUSR);
	if (file == -1)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
	fill(&scn, file);
	run(&scn);
	if (close(file) == -1)
		GSL_ERROR(strerror(errno), GSL_FAILURE);
}
