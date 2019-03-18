/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:44:30 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/19 20:43:49 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		lenght;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	lenght = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = ft_memalloc(lenght + 1)))
		return (NULL);
	ft_strcpy(dest, s1);
	j = ft_strlen(dest);
	while (s2[i])
	{
		dest[j] = s2[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
