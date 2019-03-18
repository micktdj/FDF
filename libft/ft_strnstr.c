/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:14:15 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/25 20:49:17 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (char *)str;
	while (str[i] != '\0')
	{
		while (str[j + i] == to_find[j] && (j + i) < n)
		{
			if (to_find[j + 1] == '\0')
				return (char *)str + i;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
