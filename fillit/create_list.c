/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:00:54 by hunnamab          #+#    #+#             */
/*   Updated: 2019/12/13 16:35:59 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	get_height(uint64_t tet)
{
	int hei;
	int i;
	int j;

	i = 0;
	j = 8;
	hei = 0;
	while (i < 64)
	{
		while (i < j)
		{
			if (tet & 1)
			{
				hei++;
				break ;
			}
			tet >>= 1;
			i++;
		}
		tet >>= j - i;
		i = j;
		j += 8;
	}
	return (hei);
}

static int	unst_tet(uint64_t tet)
{
	if (((tet >> 1) & 1) && ((tet >> 9) & 1))
	{
		if (((tet & 1) && ((tet >> 10) & 1)) ||
			(((tet >> 2 & 1)) && ((tet >> 8) & 1)))
			return (1);
	}
	return (0);
}

static int	get_width(uint64_t tet)
{
	int i;
	int j;
	int w;
	int wid;

	i = 0;
	j = 8;
	wid = 0;
	if (unst_tet(tet))
		return (3);
	while (i < 64)
	{
		w = 0;
		while (i++ < j)
		{
			tet & 1 ? w++ : w;
			tet >>= 1;
		}
		w > wid ? wid = w : wid;
		j += 8;
	}
	return (wid);
}

static void	create_new_item(t_list *head, uint64_t tet, char b)
{
	t_list	*item;

	item = head;
	while (item->next != NULL)
		item = item->next;
	item->next = malloc(sizeof(t_list));
	item->next->tet = tet;
	item->next->b = b;
	item->next->wid = get_width(item->next->tet);
	item->next->hei = get_height(item->next->tet);
	item->next->next = NULL;
}

t_list		*create_list(uint64_t *tet, int y)
{
	int		i;
	char	b;
	t_list	*head;

	i = y - 2;
	y -= 1;
	b = 65;
	head = NULL;
	head = malloc(sizeof(t_list));
	head->tet = tet[y--];
	head->b = b++;
	head->wid = get_width(head->tet);
	head->hei = get_height(head->tet);
	head->next = NULL;
	while (i >= 0)
	{
		create_new_item(head, tet[i], b);
		i--;
		b++;
	}
	return (head);
}
