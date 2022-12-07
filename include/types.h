/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:30:18 by stamim            #+#    #+#             */
/*   Updated: 2022/12/07 11:18:27 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

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

// NOLINTNEXTLINE
typedef struct scene
{
	t_cam	*cam;
	t_amb	*amb;
	void	*img;
	void	*win;
	void	*mlx;
}	t_scene;
#endif