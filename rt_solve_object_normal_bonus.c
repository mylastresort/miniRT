/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object_normal_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:57:34 by stamim            #+#    #+#             */
/*   Updated: 2023/02/01 18:31:32 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"

t_vec	rt_con_normal_at(const t_con con, const t_hit hit, const t_ray ray)
{
	return (vec_normalize(vec_sub_vec(vec_add_vec(
					vec_multi_value(ray.d, hit.dis),
					vec_sub_vec(ray.o, con.cnt)),
				vec_multi_value(con.nrm, hit.prm * con.fac))));
}
