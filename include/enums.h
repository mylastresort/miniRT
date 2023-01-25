/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 08:04:00 by stamim            #+#    #+#             */
/*   Updated: 2023/01/24 17:59:37 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# include <stdint.h>

enum e_keycode : int
{
	ESC = 53,
};

enum e_window : int
{
	height = 500,
	width = 900
};

enum e_type : uint8_t
{
	PLANE = 1,
	SPHERE = 2,
	CYLINDER = 3,
	POINT = 0,
	VECTOR = 1,
	NORM = 2,
};

enum e_mask : uint32_t
{
	ALPHA_1 = 0x00000000,
	ALPHA_2 = 0x99000000,
	ALPHA_3 = 0xFF000000,
	BLU = 0xFF,
	GRN = 0xFF00,
	RED = 0xFF0000,
	CYN = 0x00BCFF,
};

enum e_event : int
{
	ON_DESTROY = 17,
	ON_EXPOSE = 12,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEMOVE = 6,
	ON_MOUSEUP = 5,
};

#endif