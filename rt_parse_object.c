/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:46:36 by stamim            #+#    #+#             */
/*   Updated: 2023/01/28 16:00:17 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "enums.h"
#include "types.h"
#include <stdbool.h>
#include <stdlib.h>

static t_obj	*rt_new_obj(t_scene *scn, const int type)
{
	t_obj	*obj;
	t_obj	*head;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (!obj)
	{
		rt_destroy_objs(scn);
		exit(EXIT_FAILURE);
	}
	obj->type = type;
	head = scn->objs;
	obj->next = head;
	scn->objs = obj;
	return (obj);
}

static void	rt_parse_sph(t_scene *scn, char **args)
{
	bool	err;

	err = false;
	scn->objs->sph.c = rt_get_coordinates(args[2], &err, POINT);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the sphere coordinates");
	}
	scn->objs->sph.d = rt_get_val(args[3], &err);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the sphere diameter");
	}
	scn->objs->sph.rgb = rt_get_color(args[4], &err);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the sphere coordinates");
	}
}

static void	rt_parse_pln(t_scene *scn, char **args)
{
	bool	err;

	err = false;
	scn->objs->pln.p = rt_get_coordinates(args[2], &err, POINT);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the plane point coordinates");
	}
	scn->objs->pln.n = rt_get_coordinates(args[3], &err, NORM);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the plane normal coordinates");
	}
	scn->objs->pln.rgb = rt_get_color(args[4], &err);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the plane color coordinates");
	}
	scn->objs->pln.d = -(scn->objs->pln.p.x * scn->objs->pln.n.x + scn->objs
			->pln.p.y * scn->objs->pln.n.y + scn->objs->pln.p.z * scn->objs
			->pln.n.z);
}

static void	rt_parse_cyl(t_scene *scn, char **args)
{
	bool	err;

	err = false;
	scn->objs->cyl.c = rt_get_coordinates(args[2], &err, POINT);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse the cylinder coordinates"));
	scn->objs->cyl.n = rt_get_coordinates(args[3], &err, NORM);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse the cylinder normal coordinates"));
	scn->objs->cyl.d = rt_get_val(args[4], &err);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse the cylinder diameter"));
	scn->objs->cyl.h = rt_get_val(args[5], &err);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse the cylinder height"));
	scn->objs->cyl.rgb = rt_get_color(args[6], &err);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse the cylinder color coordinates"));
}

void	rt_parse_obj(t_scene *scn, char **args)
{
	if (!ft_strcmp(args[1], "sp"))
	{
		rt_new_obj(scn, SPHERE);
		rt_parse_sph(scn, args);
	}
	else if (!ft_strcmp(args[1], "pl"))
	{
		rt_new_obj(scn, PLANE);
		rt_parse_pln(scn, args);
	}
	else if (!ft_strcmp(args[1], "cy"))
	{
		rt_new_obj(scn, CYLINDER);
		rt_parse_cyl(scn, args);
	}
	else
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse a line\n");
	}
	free(args[0]);
	free(args);
}
