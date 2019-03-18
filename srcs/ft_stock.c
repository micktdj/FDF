/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:31:36 by piabdo            #+#    #+#             */
/*   Updated: 2019/03/18 21:24:14 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_checksize(t_dlist *p_list, int ret)
{
	t_dnode *p_block;

	if (ret < 0)
		return (READ_ERROR);
	p_block = p_list->p_head;
	if (p_list->length <= 1)
		return (0);
	p_block = p_block->p_next;
	while (p_block->p_next != NULL)
	{
		if (p_block->data != p_block->p_prev->data)
			return (MAP_ERROR);
		p_block = p_block->p_next;
	}
	if (p_block->p_next == NULL)
		if (p_block->data != p_block->p_prev->data)
			return (MAP_ERROR);
	return (0);
}

static int	ft_alloc(t_dnode *map, t_rd *rd)
{
	if (!(rd->tab = ft_strsplit(rd->line, ' ')))
		return (MALLOC_ERROR);
	while (rd->tab[rd->i])
		(rd->i)++;
	if (!(map->xtab = (int *)malloc(sizeof(int) * rd->i)))
		return (MALLOC_ERROR);
	if (!(map->xctab = (int *)malloc(sizeof(int) * rd->i)))
		return (MALLOC_ERROR);
	if (!(map->ytab = (int *)malloc(sizeof(int) * rd->i)))
		return (MALLOC_ERROR);
	return (0);
}

static void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_stock_pros(t_rd *rd, t_dnode **map, int *len_y, t_dlist **p_list)
{
	rd->i = 0;
	if ((ft_alloc(*map, rd)) < 0)
		return (-1);
	(*map)->data = rd->i;
	rd->i = 0;
	while (rd->tab[rd->i])
	{
		(*map)->xtab[rd->i] = ft_atoi(rd->tab[rd->i]);
		ft_altitude_c(map, rd);
		(rd->i)++;
	}
	(rd->j)++;
	if (rd->j != *len_y)
	{
		if (!((*map)->p_next = ft_dlistaddt(p_list)))
			return (ft_dlistdel(p_list) + MALLOC_ERROR);
		(*map) = (*map)->p_next;
	}
	ft_free_tab(rd->tab);
	free(rd->line);
	return (0);
}

int			ft_stock(int fd, int *len_y, t_dlist **p_list)
{
	t_rd	rd;
	t_dnode *map;

	rd = (t_rd){0, 0, 0, 0, NULL, NULL};
	if (!(map = ft_dlistaddt(p_list)))
		return (ft_dlistdel(p_list) + MALLOC_ERROR);
	while ((rd.ret = get_next_line(fd, &rd.line)) > 0)
	{
		if ((rd.e = ft_stock_pros(&rd, &map, len_y, p_list)) < 0)
			return (ft_dlistdel(p_list) + MALLOC_ERROR);
	}
	if (rd.ret < 0)
		return (ft_dlistdel(p_list) + READ_ERROR);
	if ((rd.e = ft_checksize(*p_list, rd.ret)) < 0)
		return (ft_dlistdel(p_list) + rd.e);
	return (0);
}
