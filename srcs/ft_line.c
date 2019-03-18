/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:47:56 by mtordjma          #+#    #+#             */
/*   Updated: 2019/03/12 16:07:21 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_pixx(t_line var, t_env env, int color)
{
	var.cumul = var.dx / 2;
	while (var.i <= var.dx)
	{
		var.x += var.xinc;
		var.cumul += var.dy;
		if (var.cumul >= var.dx)
		{
			var.cumul -= var.dx;
			var.y += var.yinc;
		}
		if (var.x > 0 && var.x < 1920 && var.y > 0 && var.y < 1080)
			env.img[var.y * 1920 + var.x] = color;
		var.i++;
	}
}

static void		ft_pixy(t_line var, t_env env, int color)
{
	var.cumul = var.dy / 2;
	while (var.i <= var.dy)
	{
		var.y += var.yinc;
		var.cumul += var.dx;
		if (var.cumul >= var.dy)
		{
			var.cumul -= var.dy;
			var.x += var.xinc;
		}
		if (var.x > 0 && var.x < 1920 && var.y > 0 && var.y < 1080)
			env.img[var.y * 1920 + var.x] = color;
		var.i++;
	}
}

void			ft_line(t_trace pos, t_env env, int color)
{
	t_line var;

	var = (t_line){pos.xf - pos.xi, pos.yf - pos.yi, 1, 0, 0, 0,
			pos.xi, pos.yi};
	var.xinc = (var.dx > 0) ? 1 : -1;
	var.yinc = (var.dy > 0) ? 1 : -1;
	var.dx = abs(var.dx);
	var.dy = abs(var.dy);
	if (var.x > 0 && var.x < 1920 && var.y > 0 && var.y < 1080)
		env.img[var.y * 1920 + var.x] = color;
	if (var.dx > var.dy)
	{
		ft_pixx(var, env, color);
	}
	else
	{
		ft_pixy(var, env, color);
	}
}
