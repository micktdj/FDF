/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piabdo <piabdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:25:42 by mtordjma          #+#    #+#             */
/*   Updated: 2019/03/11 18:51:51 by piabdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_setui(t_env *env)
{
	mlx_string_put((*env).mlx_ptr, (*env).win_ptr,
		1650, 900, WHITE, "MOVE : ARROW KEY");
	mlx_string_put((*env).mlx_ptr, (*env).win_ptr,
		1650, 930, WHITE, "ZOOM : + -");
	mlx_string_put((*env).mlx_ptr, (*env).win_ptr,
		1650, 960, WHITE, "RANGE : 6 9");
	mlx_string_put((*env).mlx_ptr, (*env).win_ptr,
		1650, 990, WHITE, "PROJECTION ISOMETRIC : I");
	mlx_string_put((*env).mlx_ptr, (*env).win_ptr,
		1650, 1020, WHITE, "PROJECTION PARALLEL : P");
	mlx_string_put((*env).mlx_ptr, (*env).win_ptr,
		1650, 1050, WHITE, "QUIT : ESC");
}
