/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:30:18 by stamim            #+#    #+#             */
/*   Updated: 2022/11/30 13:55:26 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

enum {
	A = 1,
	C = 2,
	cy = 6,
	ESC = 53,
	L = 3,
	ON_DESTROY = 17,
	ON_EXPOSE = 12,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEMOVE = 6,
	ON_MOUSEUP = 5,
	pl = 4,
	sp = 5,
	INS_SZE = 2
};

# define H 1080
# define W 1920
# define OPC_1 0xFF000000U
# define OPC_0_5 0x99000000U
# define OPC_0 0x00000000U

# define RED 0xFF0000U
# define GRN 0xFF00U
# define BLU 0xFFU

typedef struct s_spc
{
	void	*img;
	void	*mlx;
	void	*win;
	int		arg;
}	t_space;

# define TITLE "miniRT"
# define INVLD_ARG "Invalid arguments"
# define INVLD_SCN "Invalid scene"
# define INVLD_FILE "Invalid .rt file"
# define TOO_ARG "Too many argumetns"
#endif