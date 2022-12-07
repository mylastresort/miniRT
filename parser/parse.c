/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:21:26 by stamim            #+#    #+#             */
/*   Updated: 2022/12/07 11:23:52 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include <unistd.h>

void	parse(const int file, t_scene *scn)
{
	if (file == -1)
	{
		destroy(scn);
	}
	close(file);
}
