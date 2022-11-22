/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:30:18 by stamim            #+#    #+#             */
/*   Updated: 2022/11/22 16:59:25 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

enum {
	WIDTH = 1920,
	HEIGHT = 1080,
};

enum e_TYPE {
	A = 1,
	C = 2,
	L = 3,
	pl = 4,
	sp = 5,
	cy = 6
};

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	ESC = 53
};

enum {
	RED = 0x00FF0000
};

typedef struct s_obj
{
	struct s_obj	*nxt;
}	t_obj;

typedef struct s_spc
{
	int		(*frm)[HEIGHT][WIDTH];
	int		arg;
	int		bpp;
	int		end;
	int		lnsz;
	t_obj	*objs;
	void	*img;
	void	*mlx;
	void	*win;
}	t_spc;

# define TITLE "miniRT"
# define INVLD_ARG "Invalid arguments"
# define INVLD_SCN "Invalid scene"
# define INVLD_FILE "Invalid .rt file"
# define TOO_ARG "Too many argumetns"
#endif