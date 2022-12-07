/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 08:04:00 by stamim            #+#    #+#             */
/*   Updated: 2022/12/07 11:16:44 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# include <stdint.h>

enum e_keycode : int {
	ESC = 53,
};

enum e_window : int {
	H = 1080,
	W = 1920
};

enum e_mask : uint32_t {
	ALPHA_1 = 0x00000000,
	ALPHA_2 = 0x99000000,
	ALPHA_3 = 0xFF000000,
	BLU = 0xFF,
	GRN = 0xFF00,
	RED = 0xFF0000,
};

enum e_instruction : uint8_t {
	A = 1,
	C = 2,
	cy = 3,
	L = 4,
	pl = 5,
	sp = 6,
};

enum e_event : int {
	ON_DESTROY = 17,
	ON_EXPOSE = 12,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEMOVE = 6,
	ON_MOUSEUP = 5,
};

#endif