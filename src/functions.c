/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:11:45 by stamim            #+#    #+#             */
/*   Updated: 2022/10/28 18:12:23 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	is_rt_arg(const char *arg)
{
	const size_t	sze = strlen(arg);

	return (sze >= 3
		&& arg[sze - 1] == 't' && arg[sze - 2] == 'r' && arg[sze - 3] == '.');
}

bool	fill(t_spc *obj)
{
	obj = NULL;
	if (close(obj->file) == -1)
		return (false);
	return (true);
}

int	destroy(void *param)
{
	t_spc *const	spc = param;

	mlx_destroy_image(spc->vars, spc->img);
	mlx_destroy_window(spc->vars, spc->img);
	free(spc->vars);
	return (1);
}

static int	on_keydown(int keycode, void *param)
{
	if (keycode == ESC)
		destroy(param);
	return (1);
}

void	run(t_spc spc)
{
	mlx_hook(spc.vars->win_list, ON_DESTROY, 0, destroy, &spc);
	mlx_hook(spc.vars->win_list, ON_KEYDOWN, 0, on_keydown, &spc);
	mlx_put_image_to_window(spc.vars, spc.vars->win_list, spc.img, 0, 0);
	mlx_loop(spc.vars);
}
