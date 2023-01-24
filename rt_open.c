/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:21:01 by stamim            #+#    #+#             */
/*   Updated: 2023/01/24 11:58:41 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "macros.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	rt_exit(const char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str) * sizeof(char));
	write(STDERR_FILENO, "\n", sizeof(char));
	exit(EXIT_FAILURE);
}

int	event_on_keydown(t_keycode key, void *arg)
{
	if (key == ESC)
	{
		rt_destroy(arg);
	}
	return (1);
}

int	rt_destroy(t_scene *scn)
{
	rt_destroy_objs(scn);
	mlx_destroy_image(scn->mlx, scn->img);
	mlx_destroy_window(scn->mlx, scn->win);
	free(scn->mlx);
	exit(EXIT_SUCCESS);
}

void	rt_destroy_objs(t_scene *const scn)
{
	t_obj	*tmp;

	while (scn->objs)
	{
		tmp = scn->objs;
		scn->objs = scn->objs->next;
		free(tmp);
	}
}

int	rt_open(int argc, const char *arg)
{
	int		file;
	size_t	len;

	if (argc != 2)
	{
		exit(EXIT_FAILURE);
	}
	len = 0;
	while (arg[len])
	{
		len++;
	}
	if (len <= 3 || arg[len - 3] != '.' || arg[len - 2] != 'r'
		|| arg[len - 1] != 't')
	{
		rt_exit(INVLD_FILE);
	}
	file = open(arg, O_CLOEXEC, S_IRUSR);
	if (file == -1)
	{
		perror("open");
		rt_exit(INVLD_ARG);
	}
	return (file);
}
