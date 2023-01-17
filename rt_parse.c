/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:21:26 by stamim            #+#    #+#             */
/*   Updated: 2023/01/17 10:39:44 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

inline static bool	rt_is_space(const char chr)
{
	return (chr == ' ' || (chr >= '\t' && chr <= '\r'));
}

inline static size_t	rt_arg_cnt(const char *line)
{
	size_t	count;

	count = 0;
	while (*line)
	{
		if (rt_is_space(*line))
		{
			line++;
			while (rt_is_space(*line))
			{
				line++;
			}
		}
		else
		{
			count++;
			line++;
			while (!rt_is_space(*line))
			{
				line++;
			}
		}
	}
	return (count);
}

inline static const char	**rt_split(char *line)
{
	size_t		idx;
	size_t		len;
	const char	**args = (const char **)malloc(sizeof(char *) * (len
				= rt_arg_cnt(line) + 2));

	args[0] = line;
	idx = 1;
	while (idx < len)
	{
		args[idx] = line;
		while (!rt_is_space(*line))
		{
			line++;
		}
		*line = '\0';
		line++;
		while (rt_is_space(*line))
		{
			line++;
		}
		idx++;
	}
	args[idx] = NULL;
	return (args);
}

static bool	rt_getline(char **const line, const int file, t_scene *const scn)
{
	char	*tmp;
	size_t	len;

	*line = (char *)malloc(sizeof(char));
	if (!*line || read(file, *line, sizeof(char)) <= 0)
	{
		return (rt_destroy_objs(scn), false);
	}
	len = 0;
	while ((*line)[len] != '\n')
	{
		tmp = *line;
		*line = (char *)malloc((++len + 1) * sizeof(char));
		if (!*line)
		{
			return (free(tmp), rt_destroy_objs(scn), false);
		}
		ft_strncpy(*line, tmp, len);
		free(tmp);
		if (read(file, *line + len, sizeof(char)) <= 0)
		{
			break ;
		}
	}
	return ((*line)[len] = '\0', true);
}

void	rt_parse(t_scene *const scn, const int file)
{
	char		*line;
	const char	**args;

	while (rt_getline(&line, file, scn))
	{
		args = rt_split(line);
		continue ;
		if (!ft_strcmp(args[0], "A"))
		{
			rt_parse_ambient(scn, args);
		}
		else if (!ft_strcmp(args[0], "C"))
		{
			rt_parse_camera(scn, args);
		}
		else if (!ft_strcmp(args[0], "L"))
		{
			rt_parse_light(scn, args);
		}
		else
		{
			rt_parse_object(scn, args);
		}
	}
}
