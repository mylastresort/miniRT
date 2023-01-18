/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_arithmetic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:06:51 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/18 17:00:57 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_color	clr_add_value(t_color vec, float val)
{
	vec.r += val;
	vec.g += val;
	vec.b += val;
	// if (vec.r > 255)
	// 	vec.r = 255;
	// if (vec.r < 0)
	// 	vec.r = 0;
	// if (vec.g > 255)
	// 	vec.g = 255;
	// if (vec.g < 0)
	// 	vec.g = 0;
	// if (vec.b > 255)
	// 	vec.b = 255;
	// if (vec.b < 0)
	// 	vec.b = 0;
	return (vec);
}

t_color	clr_add_clr(t_color vec, t_color val)
{
	vec.r += val.r;
	vec.g += val.g;
	vec.b += val.b;
	// if (vec.r > 255)
	// 	vec.r = 255;
	// if (vec.r < 0)
	// 	vec.r = 0;
	// if (vec.g > 255)
	// 	vec.g = 255;
	// if (vec.g < 0)
	// 	vec.g = 0;
	// if (vec.b > 255)
	// 	vec.b = 255;
	// if (vec.b < 0)
	// 	vec.b = 0;
	return (vec);
}

t_color	clr_multi_value(t_color vec, float val)
{
	vec.r *= val;
	vec.g *= val;
	vec.b *= val;
	// if (vec.r > 255)
	// 	vec.r = 255;
	// if (vec.r < 0)
	// 	vec.r = 0;
	// if (vec.g > 255)
	// 	vec.g = 255;
	// if (vec.g < 0)
	// 	vec.g = 0;
	// if (vec.b > 255)
	// 	vec.b = 255;
	// if (vec.b < 0)
	// 	vec.b = 0;
	return (vec);
}

t_color	clr_multi_clr(t_color vec, t_color val)
{
	vec.r *= val.r;
	vec.g *= val.g;
	vec.b *= val.b;
	// if (vec.r > 255)
	// 	vec.r = 255;
	// if (vec.r < 0)
	// 	vec.r = 0;
	// if (vec.g > 255)
	// 	vec.g = 255;
	// if (vec.g < 0)
	// 	vec.g = 0;
	// if (vec.b > 255)
	// 	vec.b = 255;
	// if (vec.b < 0)
	// 	vec.b = 0;
	return (vec);
}
