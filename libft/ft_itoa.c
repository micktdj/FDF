/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:04:41 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/19 20:04:46 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_length(int n)
{
	long		length;

	if (n == 0)
		return (1);
	length = 0;
	if (n < 0)
	{
		length++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length++);
}

static int		ft_isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	char *str;
	long nb;
	long length;

	nb = n;
	length = ft_length(nb);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	length--;
	if (nb < 0)
		nb = -nb;
	while (length >= 0)
	{
		str[length] = (nb % 10) + 48;
		length--;
		nb = nb / 10;
	}
	if (ft_isneg(n))
		str[0] = '-';
	return (str);
}
