/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dec_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:33:02 by pmetron           #+#    #+#             */
/*   Updated: 2019/12/23 13:01:26 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*bin_big(char *bin_char, int y)
{
	char	*buf;
	int		x;
	int		z;
	int		j;

	j = 0;
	z = 0;
	x = 0;
	buf = ft_strnew(64 * y);
	while (bin_char[x])
	{
		while (z < 4)
		{
			buf[j++] = '0';
			z++;
		}
		while (z > 0)
		{
			buf[j++] = bin_char[x++];
			z--;
		}
	}
	buf[j] = '\0';
	return (buf);
}

void			double_arr_free(char **arr, int y)
{
	y -= 1;
	while (y >= 0)
	{
		ft_strdel(&arr[y]);
		y--;
	}
	free(arr);
	arr = NULL;
}

static uint64_t	*char_to_int(char *bin_char, size_t y)
{
	uint64_t	*dec_arr;
	char		**bin_arr;
	char		*bin_buf;
	size_t		x;

	x = 0;
	bin_buf = bin_big(bin_char, y);
	dec_arr = (uint64_t *)malloc(sizeof(uint64_t) * y);
	bin_arr = bin_strsplit(bin_buf, y);
	while (x < y)
	{
		dec_arr[x] = ft_btd(bin_arr[x]);
		dec_arr[x] = min_x(dec_arr[x]);
		x++;
	}
	ft_strdel(&bin_char);
	ft_strdel(&bin_buf);
	double_arr_free(bin_arr, y);
	return (dec_arr);
}

static char		*buf_to_bin_char(char *buf, char *bin_char, int i, int x)
{
	while (i >= 0)
	{
		if (buf[i] == '#')
		{
			bin_char[x] = '1';
			x++;
		}
		if (buf[i] == '.')
		{
			bin_char[x] = '0';
			x++;
		}
		i--;
	}
	return (bin_char);
}

uint64_t		*get_dec_arr(int fd)
{
	char	buf[2048];
	char	*bin_char;
	size_t	x;
	int		i;
	size_t	y;

	x = 0;
	if ((i = read(fd, buf, 2048)))
		buf[i] = '\0';
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#' || buf[i] == '.')
			x++;
		i++;
	}
	y = x / 16;
	bin_char = ft_strnew(x);
	x = 0;
	bin_char = buf_to_bin_char(buf, bin_char, i, x);
	return (char_to_int(bin_char, y));
}
