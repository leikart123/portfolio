/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dec_arr2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:05:21 by pmetron           #+#    #+#             */
/*   Updated: 2019/12/23 13:24:04 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		zero(char *arr, int start, int end)
{
	while (start < end)
	{
		arr[start] = '0';
		start++;
	}
}

char		*ft_strsub_x2(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = NULL;
	i = 0;
	if (s)
	{
		if (!(str = ft_strnew((len * 2))))
			return (NULL);
		while (i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	return (str);
}

char		**bin_strsplit(char *buf, int cnt)
{
	char	**arr;
	int		a;
	int		i;
	int		x;

	a = 0;
	i = 32;
	x = 0;
	arr = (char **)ft_memalloc(sizeof(char *) * cnt + 1);
	while (a < cnt)
	{
		arr[a] = ft_strsub_x2(buf, x, i);
		zero(arr[a], 32, 64);
		a++;
		x += 32;
	}
	return (arr);
}

uint64_t	min_y(uint64_t tet)
{
	int x;
	int z;
	int y;

	x = 0;
	z = 0;
	y = 0;
	while (y < 8)
	{
		while (x < 64)
		{
			if (((tet >> x) & 1) == 1)
			{
				break ;
			}
			x += 8;
			z++;
			if (z == 7)
				tet >>= 1;
		}
		z = 0;
		x = 0;
		y++;
	}
	return (tet);
}

uint64_t	min_x(uint64_t tet)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 8)
	{
		while (x < 8)
		{
			if (((tet >> x) & 1) == 1)
				break ;
			x++;
			if (x == 7)
				tet >>= 8;
		}
		x = 0;
		y++;
	}
	return (min_y(tet));
}
