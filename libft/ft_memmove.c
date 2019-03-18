/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:20:15 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/19 21:28:16 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (n--)
	{
		if (dest < src)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		else
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		i++;
	}
	return (dest);
}
