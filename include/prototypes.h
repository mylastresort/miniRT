/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:12:53 by stamim            #+#    #+#             */
/*   Updated: 2022/10/29 20:58:52 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "definitions.h"
# include <stdbool.h>

bool	fill(t_spc *obj);
bool	is_rt_arg(const char *arg);
void	raytrace(t_spc spc);
void	play(t_spc spc);

#endif