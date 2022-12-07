/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:30:18 by stamim            #+#    #+#             */
/*   Updated: 2022/12/07 08:47:28 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include <stdint.h>

typedef enum e_keycode	t_keycode;

typedef struct cam
{
	uint32_t	val;
}	t_cam;

typedef struct amb
{
	uint32_t	val;
}	t_amb;

typedef struct scene
{
	void	*img;
	void	*mlx;
	void	*win;
	t_cam	*cam;
	t_amb	*amb;
}	t_scene;
#endif