/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:31:00 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/08 16:22:34 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/types.h"
#include <math.h>

t_rad	deg_to_rad(t_deg deg)
{
	return (deg * M_PI / 180);
}

t_deg	rad_to_deg(t_rad rad)
{
	return (rad * 180 / M_PI);
}
