/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:36:11 by mtordjma          #+#    #+#             */
/*   Updated: 2019/03/12 18:13:13 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_range(int keycode, t_env *env)
{
	if (keycode == UR && (*env).range > -30)
		(*env).range -= 1;
	if (keycode == DR && (*env).range < 30)
		(*env).range += 1;
	if (keycode == U)
		(*env).inc_y -= 10;
	if (keycode == D)
		(*env).inc_y += 10;
	if (keycode == L)
		(*env).inc_x -= 10;
	if (keycode == R)
		(*env).inc_x += 10;
}

static void		ft_set_zoom(int keycode, t_env *env)
{
	if (keycode == UZ && ((*env).zoom_x < 300))
	{
		(*env).zoom_x += 2;
		(*env).zoom_y += 2;
	}
	if (keycode == DZ && ((*env).zoom_x > 2))
	{
		(*env).zoom_x -= 2;
		(*env).zoom_y -= 2;
	}
}

static int		ft_slide_hook(int keycode, t_env *env)
{
	if (keycode == DZ || keycode == UZ || keycode == UR || keycode == DR
			|| keycode == U || keycode == D || keycode == L || keycode == R)
		mlx_clear_window(env->mlx_ptr, env->win_ptr);
	ft_set_zoom(keycode, env);
	ft_range(keycode, env);
	if (keycode == E)
	{
		mlx_destroy_image(env->mlx_ptr, env->ip);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		ft_dlistdel(&env->p_list);
		exit(0);
	}
	if (keycode == P || keycode == I)
		(*env).swt = keycode == P ? 2 : 1;
	if ((ft_draw(&(*env).p_list, (*env))) < 0)
	{
		mlx_destroy_image(env->mlx_ptr, env->ip);
		ft_dlistdel(&env->p_list);
		exit(0);
	}
	return (0);
}

static void		ft_calcx(t_env env, t_dnode **map)
{
	int tmp_x;
	int tmp_y;

	tmp_x = 0;
	tmp_y = 0;
	while (env.map_x < env.len_x)
	{
		tmp_x = env.space_x;
		tmp_y = env.space_y;
		if (env.swt == 1)
			ft_altitude_i(&tmp_x, &tmp_y, (*map)->xtab[env.map_x], env);
		if (env.swt == 2)
			ft_altitude_p(&tmp_x, &tmp_y, (*map)->xtab[env.map_x], env);
		(*map)->xctab[env.map_x] = tmp_x;
		(*map)->ytab[env.map_x] = tmp_y;
		env.space_x += env.zoom_x;
		env.map_x++;
	}
}

int				ft_draw(t_dlist **p_list, t_env env)
{
	t_dnode	*map;

	map = (*p_list)->p_head;
	env.space_x = 500 + env.inc_x;
	env.space_y = 200 + env.inc_y;
	env.map_x = 0;
	env.map_y = 0;
	if (env.destroy < 0)
		mlx_destroy_image(env.mlx_ptr, env.img);
	env.ip = mlx_new_image(env.mlx_ptr, 1920, 1080);
	env.img = (int *)mlx_get_data_addr(env.ip, &(env.b), &(env.s), &(env.e));
	while (env.map_y < env.len_y && env.ip != NULL)
	{
		ft_calcx(env, &map);
		env.space_y += env.zoom_y;
		env.space_x = 500 + env.inc_x;
		env.map_x = 0;
		map = map->p_next;
		env.map_y++;
	}
	ft_trace(p_list, env);
	mlx_key_hook(env.win_ptr, ft_slide_hook, &env);
	env.destroy = -42;
	mlx_loop(env.mlx_ptr);
	return (env.ip == NULL ? MALLOC_ERROR : 0);
}
