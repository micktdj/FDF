/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:01:08 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/23 17:40:30 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_next(char const *src, int index)
{
	while (src[index] && ft_isspace(src[index]) == 1)
	{
		index++;
		if (src[index] == '\0')
			return (1);
	}
	return (0);
}

static	int		ft_lenght(char const *s)
{
	int i;
	int j;

	j = 1;
	i = 0;
	while (ft_isspace(s[i]) == 1)
		i++;
	while (s[i] && ft_next(s, i) == 0)
	{
		j++;
		i++;
	}
	return (j);
}

char			*ft_strtrim(char const *s)
{
	char	*dest;
	int		lenght;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s == 0)
		return (NULL);
	lenght = ft_lenght(s);
	if (!(dest = (char *)malloc(sizeof(char) * (lenght))))
		return (NULL);
	while (ft_isspace(s[i]) == 1)
		i++;
	while (s[i] && ft_next(s, i) == 0)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
