/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:44:03 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/19 21:29:32 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	c2;

	c2 = c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == c2)
			return ((unsigned char *)&s[i]);
		i++;
	}
	return (NULL);
}
