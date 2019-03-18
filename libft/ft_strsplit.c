/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:45:30 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/18 17:27:41 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_cw(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (ft_strlen(s) == 0)
		return (0);
	if (s[0] != c)
		count++;
	while (s[i++])
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
	return (count);
}

static	int		ft_cl(char const *s, char c, int index)
{
	int i;

	i = 0;
	while (s[index] != c && s[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		l;
	int		j;
	int		i;

	if (s == 0 || c == 0)
		return (NULL);
	i = 0;
	l = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_cw(s, c) + 1))))
		return (NULL);
	tab[ft_cw(s, c)] = 0;
	while (j < ft_cw(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(tab[j] = (char *)malloc(sizeof(char) * (ft_cl(s, c, i) + 1))))
			return (NULL);
		while (s[i] != c && s[i])
			tab[j][l++] = s[i++];
		tab[j++][l] = '\0';
		l = 0;
	}
	return (tab);
}
