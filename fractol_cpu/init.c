/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:40:37 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 17:39:39 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_mlx_data *cmd)
{
	cmd->mlx = mlx_init();
	cmd->img = mlx_new_image(cmd->mlx, WID, HEI);
	cmd->img_data = (t_image_data *)malloc(sizeof(t_image_data));
	cmd->mouse_locked = 0;
}

void	fractal_settings_norme(t_image_data *img_d)
{
	if (img_d->fractal_num == 1)
	{
		img_d->zoom = 240;
		img_d->x_pos = 0;
		img_d->y_pos = 0;
	}
	if (img_d->fractal_num == 2)
	{
		img_d->zoom = 260;
		img_d->x_pos = 160;
		img_d->y_pos = 0;
	}
	if (img_d->fractal_num == 3)
	{
		img_d->zoom = 240;
		img_d->x_pos = 100;
		img_d->y_pos = 100;
	}
	if (img_d->fractal_num == 4)
	{
		img_d->zoom = 100;
		img_d->x_pos = 0;
		img_d->y_pos = 0;
	}
}

void	img_data_init(t_image_data *img_d, t_mlx_data *cmd)
{
	cmd->win = mlx_new_window(cmd->mlx, WID, HEI, "fractol");
	img_d->pixels_arr = (int *)mlx_get_data_addr(cmd->img, &cmd->bpp, \
		&cmd->size_line, &cmd->endian);
	img_d->min.re = ((img_d->x_pos + (WID >> 1)) / (img_d->zoom / 2)) / -2;
	img_d->min.im = ((img_d->y_pos + (HEI >> 1)) / (img_d->zoom / 2)) / -2;
	img_d->palett_type = 1;
	img_d->thread_size = WID / THREAD_NUM;
	fractal_settings_norme(img_d);
	if (img_d->fractal_num == 5)
	{
		img_d->zoom = 100;
		img_d->x_pos = 0;
		img_d->y_pos = 0;
	}
	if (img_d->fractal_num == 6)
	{
		img_d->zoom = 200;
		img_d->x_pos = 0;
		img_d->y_pos = 0;
	}
	img_d->maxiter = 100;
}

int		key_mouse_control(t_mlx_data *cmd)
{
	mlx_hook(cmd->win, 2, (1L << 0), key_control, cmd);
	mlx_hook(cmd->win, 4, (1L << 2), mouse_press, cmd);
	mlx_hook(cmd->win, 6, (1L << 6), mouse_move, cmd);
	return (0);
}
