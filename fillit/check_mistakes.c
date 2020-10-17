/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mistakes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:18:04 by hunnamab          #+#    #+#             */
/*   Updated: 2019/12/23 14:36:07 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_arr(char **arr, int cnt)
{
	int i;
	int a;

	i = 0;
	a = 4;
	while (i < cnt)
	{
		if ((ft_strlen(arr[i])) != 5)
		{
			if (arr[i][0] == '\n' && i == a)
				a = a + 5;
			else
				return (0);
		}
		i++;
	}
	return (check_tetrm(arr, cnt));
}

static int	create_arr(char *buf, int cnt)
{
	char	**arr;
	int		a;
	int		i;

	a = 0;
	i = 0;
	arr = (char **)ft_memalloc(sizeof(char *) * cnt + 1);
	while (a < cnt)
	{
		if (buf[0] != '\n')
		{
			while (buf[i] != '\n' && buf[i] != '\0')
				i++;
			arr[a] = ft_strsub(buf, 0, (i + 1));
			buf = buf + (i + 1);
		}
		else
		{
			arr[a] = ft_strsub(buf, 0, 1);
			buf = buf + 1;
		}
		a++;
	}
	return (check_arr(arr, cnt));
}

int			check_mistakes(int fd)
{
	int		ret;
	char	buf[1024];
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while ((ret = read(fd, buf, 1024)) > 0)
		buf[ret] = '\0';
	while (buf[i] != '\0')
	{
		if (buf[i] != '\n' && buf[i] != '.' && buf[i] != '#' && buf[i] != '\0')
			return (0);
		if (buf[i] == '\n')
			cnt++;
		i++;
	}
	if (cnt < 4 || cnt > 129 || (cnt + 1) % 5 != 0)
		return (0);
	return (create_arr(buf, cnt));
}
