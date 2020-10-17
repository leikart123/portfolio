/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:46:31 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 17:59:33 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_cmd(t_mlx_data *cmd)
{
	ft_memdel((void **)&cmd->img_data);
	ft_memdel((void **)&cmd->img);
	ft_memdel((void **)&cmd);
}

int		main(int argc, char **argv)
{
	t_mlx_data	*cmd;

	if (!(cmd = (t_mlx_data *)malloc(sizeof(t_mlx_data))))
		return (0);
	init_mlx(cmd);
	if (args_parse(argc, argv, cmd) < 0)
	{
		clean_cmd(cmd);
		exit(0);
	}
	img_data_init(cmd->img_data, cmd);
	thread_init(cmd->img_data);
	key_mouse_control(cmd);
	mlx_put_image_to_window(cmd->mlx, cmd->win, cmd->img, 0, 0);
	mlx_loop(cmd->mlx);
	return (0);
}
