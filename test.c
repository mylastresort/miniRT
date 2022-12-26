/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:33:11 by hjabbour          #+#    #+#             */
/*   Updated: 2022/12/25 14:13:55 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/enums.h"
#include "include/declarations.h"
#include "include/macros.h"
#include "include/types.h"

t_projectile	tick(t_environment env, t_projectile prj)
{
	t_projectile	ret;

	(void)env;
	ret.pnt_position = tuple_add_vec(prj.pnt_position, prj.vec_velocity);
	ret.vec_velocity = tuple_add_vec(prj.vec_velocity,
			tuple_add_vec(env.vec_gravity, env.vec_wind));
	return (ret);
}
