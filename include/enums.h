/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 08:04:00 by stamim            #+#    #+#             */
/*   Updated: 2022/12/07 09:00:00 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum e_keycode {
	ESC = 53,
};

enum e_window {
	H = 1080,
	W = 1920
};

enum e_mask : uint32_t {
	ALPHA_1 = 0x00000000U,
	ALPHA_2 = 0x99000000U,
	ALPHA_3 = 0xFF000000U,
	BLU = 0xFFU,
	GRN = 0xFF00U,
	RED = 0xFF0000U,
};

enum e_instruction {
	A = 1,
	C = 2,
	cy = 3,
	L = 4,
	pl = 5,
	sp = 6,
};

enum e_event {
	ON_DESTROY = 17,
	ON_EXPOSE = 12,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEMOVE = 6,
	ON_MOUSEUP = 5,
};

#endif