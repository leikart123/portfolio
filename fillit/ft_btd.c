/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:33:58 by pmetron           #+#    #+#             */
/*   Updated: 2019/12/13 14:42:36 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint64_t	ft_btd(char *bin)
{
	uint64_t i;
	uint64_t j;
	uint64_t x;

	j = 0;
	x = 0;
	i = ft_strlen(bin);
	while (i > 0)
	{
		if (bin[j] == '1')
			x += ft_pow(2, (i - 1));
		i--;
		j++;
	}
	return (x);
}

void		make_it_zero(uint16_t *map)
{
	int a;

	a = 0;
	while (a < 16)
		map[a++] = 0;
}
