/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:22:51 by mtordjma          #+#    #+#             */
/*   Updated: 2019/03/12 16:06:25 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_check(char *line, int *len, int *i)
{
	while (line[*i] != '\0')
	{
		while (ft_isspace(line[*i]) == 1 && line[*i])
			(*i)++;
		if (ft_isdigit(line[*i]) == 0 && line[*i] != '\0')
		{
			if (line[*i] == '-' && ft_isdigit(line[*i + 1]) == 1)
				break ;
			return (MAP_ERROR);
		}
		if (line[*i] != '\0')
			(*i)++;
	}
	(*len)++;
	*i = 0;
	free(line);
	return (0);
}

int			ft_checkmap(int fd, int *len)
{
	char	*line;
	int		i;
	int		ret;

	*len = 0;
	ret = 0;
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_check(line, len, &i) < 0)
			return (MAP_ERROR);
	}
	if (*len == 0)
		return (ret < 0 ? READ_ERROR : MAP_ERROR);
	return (ret < 0 ? READ_ERROR : 0);
}
