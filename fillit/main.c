/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:25:37 by hunnamab          #+#    #+#             */
/*   Updated: 2019/12/23 13:14:08 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		mistakes_output(int fd)
{
	int y;

	y = check_mistakes(fd);
	if (y == 0)
		ft_putstr("error\n");
	close(fd);
	return (y);
}

int		main(int argc, char **argv)
{
	int			fd;
	uint64_t	*nmb;
	t_list		*list;
	t_list		*list_const;
	int			y;

	y = 0;
	if (argc != 2)
		ft_putstr("usage: fillit source_file\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		y = mistakes_output(fd);
	}
	if (y == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	nmb = get_dec_arr(fd);
	list = create_list(nmb, y);
	list_const = create_list(nmb, y);
	free(nmb);
	fillit(list, list_const, y);
	return (0);
}
