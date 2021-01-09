/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:40:01 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 18:00:08 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll(int key, t_mlx_data *cmd)
{
	if (key == 4)
	{
		cmd->img_data->x_pos = round(cmd->img_data->x_pos * 1.1);
		cmd->img_data->y_pos = round(cmd->img_data->y_pos * 1.1);
		cmd->img_data->zoom *= 1.1;
	}
	if (key == 5)
	{
		cmd->img_data->x_pos = round(cmd->img_data->x_pos * 0.9);
		cmd->img_data->y_pos = round(cmd->img_data->y_pos * 0.9);
		cmd->img_data->zoom *= 0.9;
	}
	if (key == 1 || key == 2)
	{
		cmd->img_data->x_pos = round((cmd->img_data->x_pos + \
		((WID >> 1) - cmd->img_data->mouse_pos.x)) * 1.1);
		cmd->img_data->y_pos = round((cmd->img_data->y_pos + \
		((HEI >> 1) - cmd->img_data->mouse_pos.y)) * 1.1);
		cmd->img_data->zoom *= 1.1;
	}
}

int		mouse_move(int x, int y, t_mlx_data *cmd)
{
	if (cmd->img_data->fractal_num == 1 && !cmd->mouse_locked)
	{
		get_new_image(cmd);
		cmd->img_data->mouse_pos.x = x;
		cmd->img_data->mouse_pos.y = y;
		change_julia_k(cmd->img_data, x, y);
		thread_init(cmd->img_data);
		mlx_put_image_to_window(cmd->mlx, cmd->win, cmd->img, 0, 0);
	}
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx_data *cmd)
{
	get_new_image(cmd);
	cmd->img_data->mouse_pos.x = x;
	cmd->img_data->mouse_pos.y = y;
	scroll(button, cmd);
	img_changes(button, cmd, cmd->img_data);
	thread_init(cmd->img_data);
	mlx_put_image_to_window(cmd->mlx, cmd->win, cmd->img, 0, 0);
	return (0);
}

int		key_control(int key, t_mlx_data *cmd)
{
	if (key == 0xff1b)
	{
		mlx_destroy_window(cmd->mlx, cmd->win);
		exit(0);
	}
	if (key == 0xffe1)
		cmd->mouse_locked = cmd->mouse_locked ? 0 : 1;
	if (key == 0x0036 || key == 0x0031 || key == 0x0032 ||\
		key == 0x0033 || key == 0x0034 || key == 0x0035 || \
		key == 0xff52 || key == 0xff51 || key == 0xff53 || key == 0xff54 ||\
		key == 0x003d || key == 0x002d || key == 0x0071 || key == 0x0077 || \
		key == 0x0065 || key == 0x0072)
	{
		get_new_image(cmd);
		img_changes(key, cmd, cmd->img_data);
		thread_init(cmd->img_data);
		mlx_put_image_to_window(cmd->mlx, cmd->win, cmd->img, 0, 0);
	}
	return (0);
}
