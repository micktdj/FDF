/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:59:48 by mtordjma          #+#    #+#             */
/*   Updated: 2019/03/12 17:15:49 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_dlistdel(t_dlist **p_list)
{
	t_dnode *p_temp;
	t_dnode *p_del;

	if (*p_list != NULL)
	{
		p_temp = (*p_list)->p_head;
		while (p_temp != NULL)
		{
			p_del = p_temp;
			ft_memdel((void **)&(p_del->xtab));
			ft_memdel((void **)&(p_del->ytab));
			ft_memdel((void **)&(p_del->xctab));
			p_temp = p_temp->p_next;
			free(p_del);
		}
		free(*p_list);
		*p_list = NULL;
	}
	return (0);
}
