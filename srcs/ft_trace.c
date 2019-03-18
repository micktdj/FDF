/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:22:04 by mtordjma          #+#    #+#             */
/*   Updated: 2019/03/12 17:19:44 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_color(int z)
{
	if (z < -2)
		return (BLUE + (z * 10));
	if (z >= -2 && z <= 2)
		return (WHITE);
	if (z > 2 && z <= 12)
		return (YELLOW + (z * 10));
	if (z > 12 && z <= 60)
		return (ORANGE + (z * 10));
	if (z > 60)
		return (RED + (z * 10));
	return (WHITE);
}

static t_dnode	*ft_next_y(int *map_x, int *map_y, t_dnode *map)
{
	(*map_y)++;
	*map_x = 0;
	return (map->p_next);
}

static void		ft_vertical(int map_x, t_trace pos, t_dnode *map, t_env env)
{
	pos.xi = map->xctab[map_x];
	pos.yi = map->ytab[map_x];
	pos.xf = map->p_next->xctab[map_x];
	pos.yf = map->p_next->ytab[map_x];
	ft_line(pos, env, ft_color(map->xtab[map_x]));
}

static void		ft_horizontal(int map_x, t_trace pos, t_dnode *map, t_env env)
{
	pos.xi = map->xctab[map_x];
	pos.yi = map->ytab[map_x];
	pos.xf = map->xctab[map_x + 1];
	pos.yf = map->ytab[map_x + 1];
	ft_line(pos, env, ft_color(map->xtab[map_x]));
}

int				ft_trace(t_dlist **p_listmap, t_env env)
{
	t_dnode *map;
	t_trace pos;
	int		map_x;
	int		map_y;

	map = (*p_listmap)->p_head;
	env.len_x = map->data;
	pos = (t_trace){0, 0, 0, 0};
	map_x = 0;
	map_y = 0;
	if (env.ip == NULL)
		return (MALLOC_ERROR);
	while (map != NULL)
	{
		if (map_x < env.len_x - 1)
			ft_horizontal(map_x, pos, map, env);
		if (map_y < env.len_y - 1)
			ft_vertical(map_x, pos, map, env);
		map_x++;
		if (map_x == env.len_x)
			map = ft_next_y(&map_x, &map_y, map);
	}
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.ip, 0, 0);
	ft_setui(&env);
	return (0);
}
