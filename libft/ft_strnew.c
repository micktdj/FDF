/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:53:41 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/17 15:01:44 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *dest;

	if (!(dest = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(dest, '\0', size + 1);
	return (dest);
}
