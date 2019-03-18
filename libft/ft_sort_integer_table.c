/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:50:42 by mtordjma          #+#    #+#             */
/*   Updated: 2018/11/25 19:50:43 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_integer_table(int *tab, int size)
{
	int n;
	int temp;
	int m;

	n = 0;
	m = n + 1;
	while (n < size)
	{
		while (m < size)
		{
			if (tab[m] > tab[n])
			{
				temp = tab[n];
				tab[n] = tab[m];
				tab[m] = temp;
			}
			m++;
		}
		n++;
		m = 0;
	}
}
