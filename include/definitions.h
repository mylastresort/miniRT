/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:30:18 by stamim            #+#    #+#             */
/*   Updated: 2022/10/28 18:14:55 by stamim           ###   ########.fr       */
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
	ESC = 1
};

typedef struct s_obj
{
	struct s_obj	*next;
}	t_obj;

// NOLINTNEXTLINE
typedef struct s_spc
{
	int		file;
	t_xvar	*vars;
	t_img	*img;
	t_obj	*objs;
}	t_spc;

# define TITLE "miniRT"

# define INVLD_ARG "Invalid arguments"
# define INVLD_SCN "Invalid scene"
# define INVLD_FILE "Invalid .rt file"
#endif