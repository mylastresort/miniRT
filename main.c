/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/12/28 18:14:21 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/enums.h"
#include "include/declarations.h"
#include "include/macros.h"
#include "include/types.h"
#include "include/linear_algebra.h"
#include <math.h>

// void	test(uint32_t (*const buf)[H][W])
// {
// 	int				rows;
// 	t_projectile	proj;
// 	t_environment	env;
// 	t_tuple			tup;
// 	tup = (t_tuple){.x = 1, .y = 1.8, .z = 0, .w = 0};
// 	proj.pnt_position = (t_tuple){.x = 0, .y = 1, .z = 0, .w = 1};
// 	proj.vec_velocity = tup_multi_value(tup_normalize(tup), 11.25);
// 	env.vec_gravity = (t_tuple){.x = 0, .y = -0.1, .z = 0, .w = 0};
// 	env.vec_wind = (t_tuple){.x = -0.01, .y = 0, .z = 0, .w = 0};
// 	rows = 0;
// 	while (true)
// 	{
// 		proj = tick(env, proj);
// 		printf("i: %d | x: %f | y: %f | z: %f\n", rows, proj.pnt_position.x,
// 			proj.pnt_position.y, proj.pnt_position.z);
// 		if (proj.pnt_position.y <= 0)
// 		{
// 			break ;
// 		}
// 		if ((int)(proj.pnt_position.x) < H && (int)(proj.pnt_position.y) < W){
// 			printf("%d | %d\n", (int)proj.pnt_position.x, (int)proj.pnt_position.y);
// 			// (*buf)[(int)(proj.pnt_position.x)][(int)(proj.pnt_position.y)] = BLU;
// 			(*buf)[H - (int)(proj.pnt_position.y)][W - (int)(proj.pnt_position.x)] = BLU;
// 		}
// 		rows++;
// 	}
// }

// TODO: (H-J) build the assert function for the subMatrix
void	test(void)
{
	// t_matrix_3x3	mat = {
	// 	.m[0][0] = 1 , .m[0][1] = 2 , .m[0][2] = 6 ,
	// 	.m[1][0] = -5, .m[1][1] = 8 , .m[1][2] = -4,
	// 	.m[2][0] = 2 , .m[2][1] = 6 , .m[2][2] = 4 ,
	// };
	// printf("%f\n", determ_matr3x3(mat));
	// printf("%s\n", (determ_matr3x3(mat) == -196 ? "true" : "false"));
	t_matrix_4x4	a = {
		.m[0][0] = -5, .m[0][1] = 2 , .m[0][2] = 6 , .m[0][3] = -8,
		.m[1][0] = 1 , .m[1][1] = -5, .m[1][2] = 1 , .m[1][3] = 8 ,
		.m[2][0] = 7 , .m[2][1] = 7 , .m[2][2] = -6, .m[2][3] = -7,
		.m[3][0] = 1 , .m[3][1] = -3, .m[3][2] = 7 , .m[3][3] = 4 ,
	};
	t_matrix_4x4	b = {
		.m[0][0] = 9 , .m[0][1] = 3 , .m[0][2] = 0 , .m[0][3] = 9 ,
		.m[1][0] = -5, .m[1][1] = -2, .m[1][2] = -6, .m[1][3] = -3,
		.m[2][0] = -4, .m[2][1] = 9 , .m[2][2] = 6 , .m[2][3] = 4 ,
		.m[3][0] = -7, .m[3][1] = 6 , .m[3][2] = 6 , .m[3][3] = 2 ,
	};
	t_matrix_4x4	c = matr4x4_multi_matr4x4(a, b);

	print_matr4x4(a);
	puts("---------------------------------------");
	print_matr4x4(b);
	puts("---------------------------------------");
	print_matr4x4(c);
	puts("---------------------------------------");
	printf("%d\n", is_equal_matri4x4(a, matr4x4_multi_matr4x4(c, invers_matr4x4(b))));
}

static void	sample(uint32_t (*const buf)[H][W])
{
	volatile uint32_t	cols;
	volatile uint32_t	rows;

	rows = 0;
	while (rows < H)
	{
		cols = 0;
		while (cols < W)
		{
			// (*buf)[rows][cols] = ALPHA_3 | RED;
			(*buf)[rows][cols] = 0xFFFFFF;
			cols += 1;
		}
		rows += 1;
	}
	test();
	exit(0);
}

static void	init(t_scene *const scn, const int file)
{
	scn->mlx = mlx_init();
	if (!scn->mlx)
	{
		close(file);
		exit(EXIT_FAILURE);
	}
	scn->win = mlx_new_window(scn->mlx, W, H, TITLE);
	if (!scn->win)
	{
		close(file);
		free(scn->mlx);
		exit(EXIT_FAILURE);
	}
	scn->img = mlx_new_image(scn->mlx, W, H);
	if (!scn->img)
	{
		close(file);
		mlx_destroy_window(scn->mlx, scn->win);
		free(scn->mlx);
		exit(EXIT_FAILURE);
	}
	parse(file, scn);
}

int	destroy(t_scene *scn)
{
	mlx_destroy_image(scn->mlx, scn->img);
	mlx_destroy_window(scn->mlx, scn->win);
	free(scn->mlx);
	exit(EXIT_SUCCESS);
}

static int	on_keydown(t_keycode key, void *arg)
{
	if (key == ESC || key == Q)
	{
		destroy(arg);
	}
	return (1);
}

int	main(const int argc, const char *argv[])
{
	int		arg;
	t_scene	scn;

	if (argc != 2)
	{
		write_error(INVLD_ARG);
		exit(EXIT_FAILURE);
	}
	else
	{
		arg = open(argv[1], O_CLOEXEC, S_IRUSR);
		if (arg == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
	}
	init(&scn, arg);
	mlx_hook(scn.win, ON_DESTROY, 0, destroy, &scn);
	mlx_hook(scn.win, ON_KEYDOWN, 0, on_keydown, &scn);
	sample((uint32_t (*)[H][W])
		mlx_get_data_addr(scn.img, &arg, &arg, &arg));
	mlx_put_image_to_window(scn.mlx, scn.win, scn.img, 0, 0);
	mlx_loop(scn.mlx);
}
