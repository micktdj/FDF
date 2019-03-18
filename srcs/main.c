/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:34:03 by mtordjma          #+#    #+#             */
/*   Updated: 2019/03/12 18:04:38 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_set_env(t_env *env, t_dlist *p_listmap, int *len)
{
	if (!((*env).mlx_ptr = mlx_init()))
		return (MALLOC_ERROR);
	if (!((*env).win_ptr = mlx_new_window((*env).mlx_ptr, 1920, 1080, "FDF")))
		return (MALLOC_ERROR);
	(*env).inc_x = 0;
	(*env).inc_y = 0;
	(*env).zoom_x = 4;
	(*env).zoom_y = 4;
	(*env).swt = 1;
	(*env).range = 1;
	(*env).destroy = 42;
	(*env).p_list = p_listmap;
	(*env).len_y = *len;
	(*env).len_x = p_listmap->p_head->data;
	return (0);
}

static int	ft_checkargs(int ac, char **av)
{
	int		fd;
	char	buf[3];
	int		ret;

	ret = 0;
	if (ac != 2)
		return (USAGE_ERROR);
	fd = open(av[1], O_RDONLY);
	if ((ret = read(fd, buf, 2)) < 0)
		return (READ_ERROR);
	buf[ret] = '\0';
	close(fd);
	return (buf[0] == '\0' ? MAP_ERROR : 0);
}

int			main(int ac, char **av)
{
	int		len;
	int		fd;
	int		error;
	t_env	env;
	t_dlist	*p_listmap;

	if ((error = ft_checkargs(ac, av)) < 0)
		return (ft_print_error(error));
	fd = open(av[1], O_RDONLY);
	if ((error = ft_checkmap(fd, &len)) < 0)
	{
		close(fd);
		return (ft_print_error(error));
	}
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (!(p_listmap = ft_dlistnew()))
		return (ft_print_error(MALLOC_ERROR));
	if ((error = ft_stock(fd, &len, &p_listmap)) < 0)
		return (ft_print_error(error));
	close(fd);
	if ((ft_set_env(&env, p_listmap, &len)) < 0)
		return (ft_dlistdel(&p_listmap) + MALLOC_ERROR);
	return (ft_draw(&p_listmap, env) < 0 ? ft_dlistdel(&p_listmap)
			+ MALLOC_ERROR : 0);
}
