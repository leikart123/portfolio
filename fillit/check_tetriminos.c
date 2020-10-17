/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:25:27 by hunnamab          #+#    #+#             */
/*   Updated: 2019/12/23 13:52:49 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_links(char **arr, int i, int a, int links)
{
	int j;

	j = 0;
	while (arr[i][j] != '\0')
	{
		if (arr[i][j] == '#')
		{
			if ((j + 1) < 4 && arr[i][j + 1] == '#')
				links++;
			if ((i + 1) < a && arr[i + 1][j] == '#')
				links++;
			if ((j - 1) >= 0 && arr[i][j - 1] == '#')
				links++;
			if ((i - 1) >= 0 && arr[i - 1][j] == '#')
				links++;
		}
		j++;
	}
	return (links);
}

static int	check_tetrm2(char **arr, int cnt)
{
	int i;
	int a;
	int y;
	int links;

	i = 0;
	a = 4;
	y = (cnt + 1) / 5;
	while (i < cnt)
	{
		links = 0;
		while (i < a)
		{
			links = check_links(arr, i, a, links);
			i++;
		}
		if (links != 6 && links != 8)
		{
			double_arr_free(arr, cnt);
			return (0);
		}
		a += 5;
	}
	double_arr_free(arr, cnt);
	return (y);
}

int			check_tetrm(char **arr, int cnt)
{
	int i;
	int j;
	int delim;
	int parts;

	i = 0;
	delim = 4;
	while (i < cnt)
	{
		parts = 0;
		while (i < delim)
		{
			j = 0;
			while (arr[i][j] != '\0')
			{
				arr[i][j] == '#' ? parts++ : parts;
				j++;
			}
			i++;
		}
		if (parts != 4)
			return (0);
		delim += 5;
	}
	return (check_tetrm2(arr, cnt));
}
