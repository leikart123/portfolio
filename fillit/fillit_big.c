/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:24:22 by pmetron           #+#    #+#             */
/*   Updated: 2019/12/16 15:31:15 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check(t_list *list, uint16_t *map, int x, int y)
{
	return ((*(uint64_t *)(map + y) & (list->tet << x)));
}

static int	put_tetr(t_list *list, uint16_t *buf, int x, int y)
{
	return ((!(check(list, buf, x, y)) ? \
	(*(uint64_t *)(buf + y) ^= list->tet << x) : 0));
}

static int	for_the_norme(t_list *list, \
int size, uint16_t *map, uint16_t *buf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <= size - list->hei)
	{
		while (x <= size - list->wid)
		{
			if (put_tetr(list, map, x, y))
			{
				if ((fillit_big(list->next, map, size)))
				{
					list->x = x;
					list->y = y;
					return (1);
				}
			}
			map = ft_memcpy(map, buf, 16);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int			fillit_big(t_list *list, uint16_t *map, int size)
{
	uint16_t	*buf;

	buf = (uint16_t *)malloc(sizeof(uint16_t) * 16);
	buf = ft_memcpy(buf, map, 16);
	if (list == NULL)
	{
		free(buf);
		return (1);
	}
	if (for_the_norme(list, size, map, buf))
	{
		free(buf);
		return (1);
	}
	free(buf);
	return (0);
}

int			control(t_list *list, int size, t_list *list_const, int y)
{
	uint16_t map[16];

	while (size > 8 && size <= 16)
	{
		make_it_zero(map);
		if (fillit_big(list, map, size))
			break ;
		clear_list(list, list_const, y);
		size++;
	}
	big_map_output(size, list, 1, 0);
	free_list(list);
	return (0);
}
