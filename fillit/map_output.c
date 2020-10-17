/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:16:26 by hunnamab          #+#    #+#             */
/*   Updated: 2019/12/16 15:18:45 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			big_map_output(int size, t_list *list, size_t i, size_t z)
{
	char	*map_big;
	size_t	j;

	map_big = create_map((size_t)size);
	while (list != NULL)
	{
		i = 1;
		j = 0;
		list->x += list->y * size;
		while (j < 64)
		{
			(list->tet >> j & 1) ? map_big[list->x] = list->b : 0;
			list->x++;
			j++;
			z++;
			if (z == (size_t)size)
			{
				j = 16 * i;
				i++;
				z = 0;
			}
		}
		list = list->next;
	}
	print_map(map_big, size, (size_t)size);
}

static void		map_output_2(t_list *list, int y, int size, char *map)
{
	int		j;
	int		a;
	int		i;
	size_t	map_size;

	while (y--)
	{
		map_size = (size_t)size;
		i = 0;
		j = 8;
		a = 0;
		while (i < 64)
		{
			while (i < j)
			{
				(list->tet >> i & 1) ? (map[a] = list->b) : 0;
				a++;
				i++;
			}
			a = map_size;
			map_size += (size_t)size;
			j += 8;
		}
		list = list->next;
	}
}

void			map_output(t_list *list, int y, int size)
{
	char	*map;
	size_t	map_size;

	map_size = (size_t)size;
	map = create_map(map_size);
	map_output_2(list, y, size, map);
	print_map(map, size, map_size);
	free_list(list);
}
