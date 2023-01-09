/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2023/01/09 11:14:11 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/enums.h"
#include "include/declarations.h"
#include "include/macros.h"
#include "include/types.h"
#include "include/linear_algebra.h"
#include "mlx.h"
#include <i386/types.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

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
	// t_matrix_4x4	a = {
	// 	.m[0][0] = -5, .m[0][1] = 2 , .m[0][2] = 6 , .m[0][3] = -8,
	// 	.m[1][0] = 1 , .m[1][1] = -5, .m[1][2] = 1 , .m[1][3] = 8 ,
	// 	.m[2][0] = 7 , .m[2][1] = 7 , .m[2][2] = -6, .m[2][3] = -7,
	// 	.m[3][0] = 1 , .m[3][1] = -3, .m[3][2] = 7 , .m[3][3] = 4 ,
	// };
	// t_matrix_4x4	b = {
	// 	.m[0][0] = 9 , .m[0][1] = 3 , .m[0][2] = 0 , .m[0][3] = 9 ,
	// 	.m[1][0] = -5, .m[1][1] = -2, .m[1][2] = -6, .m[1][3] = -3,
	// 	.m[2][0] = -4, .m[2][1] = 9 , .m[2][2] = 6 , .m[2][3] = 4 ,
	// 	.m[3][0] = -7, .m[3][1] = 6 , .m[3][2] = 6 , .m[3][3] = 2 ,
	// };
	// t_matrix_4x4	c = matr4x4_multi_matr4x4(a, b);

	// print_matr4x4(a);
	// puts("---------------------------------------");
	// print_matr4x4(b);
	// puts("---------------------------------------");
	// print_matr4x4(c);
	// puts("---------------------------------------");
	// printf("%d\n", is_equal_matri4x4(a, matr4x4_multi_matr4x4(c, invers_matr4x4(b))));
	t_point	pt = (t_point){.x = 0, .y = 1, .z = 0, .w = 1};
	t_matrix_4x4	mat = matr4x4_rotation_x(deg_to_rad(90));
	print_pnt(matr4x4_multi_point(mat, pt));
	print_pnt(matr4x4_multi_point(invers_matr4x4(mat), pt));
	exit(EXIT_FAILURE);
}

int	generate_rgb(int r, int g, int b)
{
	// return (((r & 0xff) << 16) + ((g & 0xff) << 8) && (b & 0xff));
	return ((r << 16) | (g << 8) | b);
}

t_tuple	at(const float t, const t_tuple orig, const t_tuple dir)
{
	return (tup_multi_vec(orig, tup_multi_value(dir, t)));
}

static void	sample(uint32_t (*const buf)[H][W])
{
	volatile uint32_t	cols;
	volatile uint32_t	rows;

	// rows = 0;
	// while (rows < H)
	// {
	// 	cols = 0;
	// 	while (cols < W)
	// 	{
	// 		// (*buf)[rows][cols] = ALPHA_3 | RED;
	// 		(*buf)[rows][cols] = 0xFFFFFF;
	// 		// (*buf)[rows][cols] = generate_rgb(r, g, b);
	// 		cols += 1;
	// 	}
	// 	rows += 1;
	// }
	// /* color gradiant */
	// int fd = open("file1.ppm", O_CREAT | O_WRONLY, 0644);
	// if (fd == -1)
	// 	exit(EXIT_FAILURE);
	// write(fd, "P3\n1920 1080\n255\n", 18);
	// rows = 0;
	// while (rows < H)
	// {
	// 	cols = 0;
	// 	while (cols < W)
	// 	{
	// 		float fg = (float)((float)rows / (float)1080);
	// 		float fr = (float)((float)cols / (float)1920);
	// 		float fb = 0.2;
	// 		int r = (int)(255.99 * fr);
	// 		int g = (int)(255.99 * fg);
	// 		int b = (int)(255.99 * fb);
	// 		(*buf)[rows][cols] = generate_rgb(r, g, b);
	// 		write(fd, ft_itoa(r), ft_strlen(ft_itoa(r)));
	// 		write(fd, " ", 1);
	// 		write(fd, ft_itoa(g), ft_strlen(ft_itoa(g)));
	// 		write(fd, " ", 1);
	// 		write(fd, ft_itoa(b), ft_strlen(ft_itoa(b)));
	// 		write(fd, " ", 1);
	// 		cols += 1;
	// 	}
	// 	rows += 1;
	// }
	test();
	int fd = open("file1.ppm", O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		exit(EXIT_FAILURE);
	write(fd, "P3\n1920 1080\n255\n", 18);
	rows = 0;
	while (rows < H)
	{
		cols = 0;
		while (cols < W)
		{
			float fg = (float)((float)rows / (float)1080);
			float fr = (float)((float)cols / (float)1920);
			float fb = 0.2;
			int r = (int)(255.99 * fr);
			int g = (int)(255.99 * fg);
			int b = (int)(255.99 * fb);
			(*buf)[rows][cols] = generate_rgb(r, g, b);
			write(fd, ft_itoa(r), ft_strlen(ft_itoa(r)));
			write(fd, " ", 1);
			write(fd, ft_itoa(g), ft_strlen(ft_itoa(g)));
			write(fd, " ", 1);
			write(fd, ft_itoa(b), ft_strlen(ft_itoa(b)));
			write(fd, " ", 1);
			cols += 1;
		}
		rows += 1;
	}
	(void)buf;
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
