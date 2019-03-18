/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piabdo <piabdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:55:23 by mtordjma          #+#    #+#             */
/*   Updated: 2019/03/11 17:01:23 by piabdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_print_error(int error)
{
	if (error == USAGE_ERROR)
		ft_putstr_fd("Usage : ./fdf <map.fdf>\n", 2);
	if (error == MALLOC_ERROR)
		ft_putstr_fd("MALLOC ERROR", 2);
	if (error == READ_ERROR)
		ft_putstr_fd("READ ERROR", 2);
	if (error == MAP_ERROR)
		ft_putstr_fd("BAD MAP", 2);
	return (error);
}
