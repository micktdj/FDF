/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:46:47 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/16 16:03:21 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t len;

	len = ft_strlen(s2);
	if (s2[0] == '\0')
		return (char *)s1;
	while (*s1)
	{
		if (ft_memcmp((void *)s1, (void *)s2, len) == 0)
			return (char *)s1;
		s1++;
	}
	return (NULL);
}
