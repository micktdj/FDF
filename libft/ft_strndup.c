/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:39:21 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/25 18:45:42 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = ft_memalloc(n + 1)))
		return (NULL);
	while (n)
	{
		dest[i] = s1[i];
		i++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}
