/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:21:26 by stamim            #+#    #+#             */
/*   Updated: 2022/12/24 19:19:43 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include <unistd.h>

void	parse(const int file, t_scene *scn)
{
	if (file == -1)
	{
		destroy(scn);
	}
	close(file);
}
