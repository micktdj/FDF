/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:16:53 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/25 18:35:27 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = -1;
	if (str == NULL)
		return (0);
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	i = -1;
	str[0] = ft_toupper(str[0]);
	while (str[++i])
	{
		if (ft_isalnum(str[i]) == 0 && ft_isalnum(str[i + 1]) == 1)
			str[i + 1] = ft_toupper(str[i + 1]);
	}
	return (str);
}
