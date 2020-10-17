/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_staff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:59:22 by hunnamab          #+#    #+#             */
/*   Updated: 2019/12/16 13:10:23 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_list *list)
{
	t_list *tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

char	*create_map(size_t map_size)
{
	char	*map;
	size_t	i;

	map = ft_strnew((map_size * map_size) + 1);
	i = 0;
	while (i < (map_size * map_size))
	{
		map[i] = '.';
		i++;
	}
	return (map);
}

void	print_map(char *map, int size, size_t map_size)
{
	size_t i;

	i = 0;
	while (map[i] != '\0')
	{
		if (i == map_size)
		{
			ft_putstr("\n");
			map_size += (size_t)size;
		}
		ft_putchar((char)map[i]);
		i++;
	}
	ft_putstr("\n");
	ft_strdel(&map);
}
