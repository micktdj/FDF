/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:21:13 by piabdo            #+#    #+#             */
/*   Updated: 2019/03/04 15:30:12 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_errors(char **str, char **line, int fd)
{
	char tab[1];

	if (fd < 0 || read(fd, tab, 0) < 0 || line == NULL)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strdup("");
	return (0);
}

static int		ft_last_l(char *str)
{
	int i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

static int		ft_give_the_line(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	*line = ft_strsub(*str, 0, i);
	tmp = ft_strsub(*str, i + 1, ft_strlen(*str + i));
	free(*str);
	*str = tmp;
	if (str[0] == '\0')
	{
		free(str);
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char *str[OPEN_MAX];

	if (ft_check_errors(str, line, fd))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n') != 0)
			break ;
	}
	if (ft_strchr(str[fd], '\n') != 0)
		return (ft_give_the_line(&(str[fd]), line));
	if (ft_last_l(str[fd]))
		return (ft_give_the_line(&(str[fd]), line));
	return (0);
}
