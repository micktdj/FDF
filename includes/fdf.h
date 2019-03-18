/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:54:19 by mtordjma          #+#    #+#             */
/*   Updated: 2019/03/12 17:53:13 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MALLOC_ERROR -2
# define READ_ERROR -3
# define MAP_ERROR -4
# define USAGE_ERROR -5
# define E 53
# define DZ 78
# define UZ 69
# define UR 92
# define DR 88
# define U 126
# define D 125
# define L 123
# define R 124
# define I 34
# define P 35
# define WHITE 16777215
# define BLACK 00000000
# define RED 15075850
# define ORANGE 16744960
# define BLUE 1316090
# define YELLOW 16448000

# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_line
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;
}				t_line;

typedef struct	s_env
{
	int		inc_x;
	int		inc_y;
	int		len_y;
	int		len_x;
	int		map_x;
	int		map_y;
	int		zoom_x;
	int		zoom_y;
	int		space_x;
	int		space_y;
	int		destroy;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*ip;
	int		*img;
	int		b;
	int		s;
	int		e;
	int		range;
	int		swt;
	t_dlist *p_list;
}				t_env;

typedef struct	s_read
{
	int		i;
	int		j;
	int		e;
	int		ret;
	char	*line;
	char	**tab;
}				t_rd;

typedef struct	s_trace
{
	int xi;
	int yi;
	int xf;
	int yf;
}				t_trace;

int				ft_print_error(int error);
int				ft_checkmap(int fd, int *len);
int				ft_stock(int fd, int *len, t_dlist **p_listmap);
int				ft_draw(t_dlist **p_list, t_env env);
void			ft_line(t_trace pos, t_env env, int color);
void			ft_altitude_i(int *x, int *y, int z, t_env env);
void			ft_altitude_p(int *x, int *y, int z, t_env env);
int				ft_trace(t_dlist **p_list, t_env env);
void			ft_setui(t_env *env);
int				ft_dlistdel(t_dlist **p_list);
void			ft_altitude_c(t_dnode **map, t_rd *rd);

#endif
