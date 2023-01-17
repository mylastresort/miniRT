/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:46:36 by stamim            #+#    #+#             */
/*   Updated: 2023/01/17 10:49:38 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"
#include <sys/_types/_null.h>

static t_obj	*rt_new_obj(const int type)
{
	t_obj	*obj;

	obj = NULL;
	(void)type;
	return (obj);
}

void	rt_parse_object(t_scene *scn, const char **args)
{
	void	*obj;

	if (ft_strcmp(args[0], "sp"))
	{
		rt_new_obj(SPHERE);
	}
	else if (ft_strcmp(args[0], "pl"))
	{
		rt_new_obj(PLANE);
	}
	else if (ft_strcmp(args[0], "cy"))
	{
		rt_new_obj(CYLINDER);
	}
	(void)obj;
	(void)scn;
}
