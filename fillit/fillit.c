/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:10:31 by pmetron           #+#    #+#             */
/*   Updated: 2019/12/16 15:24:24 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static uint64_t	put_tetr_xy(t_list *list, uint64_t buf, uint8_t x, uint8_t y)
{
	list->tet <<= x;
	list->tet <<= (y * 8);
	if ((((list->tet & buf) != 0) ? 0 : 1))
		return ((buf ^= list->tet));
	return (0);
}

static uint64_t	solve_map(t_list *list, int size, uint64_t map, uint8_t x)
{
	uint8_t		y;
	uint64_t	map_start;

	y = 0;
	map_start = map;
	if (list == NULL)
		return (1);
	while (y <= size - list->hei)
	{
		while (x <= size - list->wid)
		{
			if ((map = put_tetr_xy(list, map, x, y)) != 0)
			{
				if ((solve_map(list->next, size, map, 0)))
					return (1);
			}
			list->tet >>= x;
			list->tet >>= (y * 8);
			map = map_start;
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void			clear_list(t_list *list, t_list *list_const, int y)
{
	while (y > 0)
	{
		list->tet = list_const->tet;
		list = list->next;
		list_const = list_const->next;
		y--;
	}
}

static void		big_tetr(t_list *list, t_list *list_const, uint64_t x)
{
	int			i;
	uint8_t		buf;
	uint64_t	buf2;

	while (list != NULL)
	{
		i = 1;
		x = 0;
		buf = list->tet;
		x ^= (uint64_t)buf;
		buf2 = 0;
		while (i < list->hei)
		{
			list->tet >>= 8;
			buf2 = list->tet;
			buf2 <<= 56;
			buf2 >>= 56 - (i * 16);
			x ^= buf2;
			i++;
		}
		list->tet = x;
		list_const->tet = list->tet;
		list_const = list_const->next;
		list = list->next;
	}
}

int				fillit(t_list *list, t_list *list_const, int y)
{
	static uint64_t map;
	int				size;

	map = 0;
	size = 2;
	while (size * size < y * 4)
		size++;
	while (size <= 8)
	{
		if ((map = (solve_map(list, size, map, 0))))
			break ;
		clear_list(list, list_const, y);
		size++;
	}
	if (size <= 8)
		map_output(list, y, size);
	if (size > 8)
	{
		big_tetr(list, list_const, 0);
		control(list, size, list_const, y);
	}
	free_list(list_const);
	return (0);
}
